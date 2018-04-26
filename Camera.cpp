//
// Created by Joe on 4/24/2018.
//

#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <glm/ext.hpp>


// Mouse
bool firstMouse = true; // First mouse callback?
float lastX = WINDOW_WIDTH / 2.0f; // Where the last mouse position was
float lastY = WINDOW_HEIGHT / 2.0f;
float curX = WINDOW_WIDTH / 2.0f;
float curY = WINDOW_WIDTH / 2.0f;
bool rotateMode = false;

float radius = 5;

int selected = -1;

void updateCamera() {
  glm::vec3 front;
  front.x = (float) (cos(glm::radians(yaw)) * cos(glm::radians(pitch)));
  front.y = (float) sin(glm::radians(pitch));
  front.z = (float) (sin(glm::radians(yaw)) * cos(glm::radians(pitch)));
  cameraPos = glm::normalize(front) * radius;
}

void scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
  if (rotateMode) {
    radius -= yoffset * 0.5;
    radius = std::max(0.1f, radius); // Make sure it doesn't go negative
    updateCamera();
  }
}

void mouse_pos_callback(GLFWwindow *window, double xpos, double ypos) {
  if (rotateMode) {
    if (firstMouse) {
      lastX = (float) xpos;
      lastY = (float) ypos;
      firstMouse = false;
    }

    float xoffset = (float) xpos - lastX;
    float yoffset = (float) ypos - lastY; // Y coords are inverted
    lastX = (float) xpos;
    lastY = (float) ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    pitch = std::min(std::max(pitch, -89.0f), 89.0f);

    updateCamera();
  } else {
    curX = xpos;
    curY = ypos;
  }
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int modes) {
  // Action:
  //  GLFW_PRESS or GLFW_RELEASE
  // Mods:
  //  GLFW_MOD_SHIFT
  //  GLFW_MOD_CONTROL
  //  GLFW_MOD_ALT
  //  GLFW_MOD_SUPER

  enum ClickType { SINGLE_CLICK, CLICK_DRAG, SHIFT_CLICK_DRAG, NONE };
  ClickType clickType = NONE;

  static double startPressTime = 0;
  static bool MOUSE_BUTTON_LEFT_IS_PRESSED = false;

  static double initialXpos = 0.0;
  static double initialYpos = 0.0;

  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
    startPressTime = glfwGetTime();
    MOUSE_BUTTON_LEFT_IS_PRESSED = true;

  } else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
    clickType = NONE;
    MOUSE_BUTTON_LEFT_IS_PRESSED = false;
  }

  double currentPressTime = glfwGetTime();
  const double CLICK_TO_HOLD_TRANSITION = 0.1;

  // Check if button is held down enough to be considered a click and drag
  if (MOUSE_BUTTON_LEFT_IS_PRESSED && currentPressTime - startPressTime < CLICK_TO_HOLD_TRANSITION) {
    clickType = SINGLE_CLICK;

  } else if (MOUSE_BUTTON_LEFT_IS_PRESSED && currentPressTime - startPressTime >= CLICK_TO_HOLD_TRANSITION) {

    // Check if the shift key is held down too or not
    if (modes == GLFW_MOD_SHIFT) {
      clickType = SHIFT_CLICK_DRAG;
    } else {
      clickType = CLICK_DRAG;
    }
  }

  // Setup projection and view matrices
  int w, h;
  glfwGetWindowSize(window, &w, &h);

  glm::mat4 projection = glm::perspective(glm::radians(fov), (float) w / (float) h, 0.1f, 100.0f);
  glm::mat4 view = glm::lookAt(cameraPos, origin, cameraUp);

  // Vector from camera in direction of cursor
  float x = 2.0f * curX / w - 1;
  float y = 1.0 - 2.0 * curY / h;
  float z = 1.0f;
  glm::vec3 ray_nds = glm::vec3(x, y, z); // normalized device coordinates
  glm::vec4 ray_clip = glm::vec4(ray_nds.x, ray_nds.y, -1.0f, 1.0f); // eye space (Non normalized clip space)
  glm::vec4 ray_eye = glm::inverse(projection) * ray_clip; // view space
  ray_eye = glm::vec4(ray_eye.x, ray_eye.y, -1.0f, 0.0f);
  glm::vec3 ray_wor = glm::vec3(glm::inverse(view) * ray_eye); // world space
  ray_wor = glm::normalize(ray_wor); // Cursor ray

  if (clickType == SINGLE_CLICK) {
    // Single click with very little mouse movement is planet select
    //    Find screen position that is clicked
    //    Convert all the planets to screen coordinates
    //    Check the closet one by radius
    //    If that's the closest, then select it

    // Model -> Screen Pos Transformation
    // projection * view * model * modelPos

    int closestInd = -1;
    float closestDist = 100;
    for (int i = 0; i < sim.planets.size(); i++) {
      glm::mat4 model(1.0f);
      model = glm::translate(model, (glm::vec3) sim.planets.at(i).getPos());
      glm::vec4 screenLoc = projection * view * model * glm::vec4(glm::vec3(0.0f), 1.0f);

      // Scale the mouse location to -1 to 1
      // Scale the screen loc by the w vector (Happens automatically in vertex shader)
      float dx = x - screenLoc.x / screenLoc.w;
      float dy = y - screenLoc.y / screenLoc.w;
      float dist = sqrt(dx * dx + dy * dy);

      if (dist < closestDist) {
        closestDist = dist;
        closestInd = i;
      }
    }

    // Only select a planet if it is close enough to the cursor
    if (closestDist < 0.2)
      selected = closestInd;
    else
      selected = -1;

  } else if (clickType == CLICK_DRAG && selected != -1) {
    // Click and large mouse movement is moving planet position
    //    Move the planet in the position parallel to the "Face" of the camera
    //    We have Up and Right camera vector so just doing a multiple of those should work

    // Right vector and up vector
    // Place at current planet location
    // Projection of click location onto that plane
    // glm::gtx::intersectRayPlane
    //sim.planets.at(selected).setPos()

  } else if (clickType == SHIFT_CLICK_DRAG && selected != -1) {
    // Shift click and drag is setting the velocity of the planet
    //    May need to change shift to ctrl to make things easier
    //    Similar to the position, but it draws a line instead from planet to mouse pos
    //    Golf it style

    // Very similar to above, only difference is that you set the velocity instead of position
  }
}

void keyboard_callback(GLFWwindow *window, int &pwr, int &mode) {
  // Note: Some of these may have to be slowed down since it may execute every frame
  // Try something like checking if GLFW_REPEATED is not true?

  // TODO: Set camera to specific positions based on a few select number keys
  // TODO: On some specific key press, start running sim
  //      Split sim into own thread and do a really simple producer-consumer type solution to transfer data
  //      Disable most other keypresses while this is going
  //      Maybe add a pause?
  //      Drawing should be about the same no matter what

  // State machine to only execute stuff on the first instance of the pressed key
  static bool KEY_KP_ADD_IS_PRESSED = false;
  static bool KEY_KP_SUBTRACT_IS_PRESSED = false;
  static bool KEY_C_IS_PRESSED = false;

  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }

  // ADD: Increase mass of selected planet
  if (glfwGetKey(window, GLFW_KEY_KP_ADD) == GLFW_PRESS) {
    if (selected != -1 && !KEY_KP_ADD_IS_PRESSED) {
      sim.planets.at(selected).setMass(sim.planets.at(selected).getMass() * 1.1);
      sim.planets.at(selected).setPos(sim.planets.at(selected).getPos() + glm::dvec3(1.0, 1.0, 1.0));
    }

    KEY_KP_ADD_IS_PRESSED = true;
  } else if (glfwGetKey(window, GLFW_KEY_KP_ADD) == GLFW_RELEASE) {
    KEY_KP_ADD_IS_PRESSED = false;
  }

  // SUBTRACT: Decrease mass of selected planet
  if (glfwGetKey(window, GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS) {
    if (selected != -1 && !KEY_KP_SUBTRACT_IS_PRESSED) {
      sim.planets.at(selected).setMass(sim.planets.at(selected).getMass() * 0.9);
      sim.planets.at(selected).setPos(sim.planets.at(selected).getPos() - glm::dvec3(1.0, 1.0, 1.0));
    }

    KEY_KP_SUBTRACT_IS_PRESSED = true;
  } else if (glfwGetKey(window, GLFW_KEY_KP_SUBTRACT) == GLFW_RELEASE) {
    KEY_KP_SUBTRACT_IS_PRESSED = false;
  }

  // C: Cycle colors of the selected planet
  if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
    if (selected != -1 && !KEY_C_IS_PRESSED) {
      sim.planets.at(selected).cycleColor();
    }

    KEY_C_IS_PRESSED = true;
  } else if (glfwGetKey(window, GLFW_KEY_C) == GLFW_RELEASE) {
    KEY_C_IS_PRESSED = false;
  }

  if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
    // Shift key is pressed, change into rotate mode
    // Only allow this on the first instance the shift key is pressed
    if (!rotateMode) {
      rotateMode = true;
      glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
      firstMouse = true;
    }
  } else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE) {
    // Shift key is release, change into normal mouse mode
    // Only allow this on the first instance the shift key is released
    if (rotateMode) {
      rotateMode = false;
      glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
  }
}