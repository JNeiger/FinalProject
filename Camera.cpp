//
// Created by Joe on 4/24/2018.
//

#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <glm/ext.hpp>
#include <glm/gtx/intersect.hpp>


// Mouse
bool firstMouse = true; // First mouse callback?
float lastX = WINDOW_WIDTH / 2.0f; // Where the last mouse position was
float lastY = WINDOW_HEIGHT / 2.0f;
float curX = WINDOW_WIDTH / 2.0f;
float curY = WINDOW_WIDTH / 2.0f;
bool rotateMode = false;

float radius = 40;

int selected = -1;

void updateCamera() {
  glm::vec3 front;

  front.x = (float) (cos(glm::radians(yaw)) * cos(glm::radians(pitch)));
  front.y = (float) sin(glm::radians(pitch));
  front.z = (float) (sin(glm::radians(yaw)) * cos(glm::radians(pitch)));
  cameraPos = origin + glm::normalize(front) * radius;
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

  enum ClickType { SINGLE_CLICK, CLICK_DRAG, CONTROL_CLICK_DRAG, NONE };
  ClickType clickType = NONE;

  static double startPressTime = 0;
  static bool MOUSE_BUTTON_LEFT_IS_PRESSED = false;

  static double initialXpos = 0.0;
  static double initialYpos = 0.0;

  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
    if (!MOUSE_BUTTON_LEFT_IS_PRESSED) {
      startPressTime = glfwGetTime();
    }
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

  } else if (!MOUSE_BUTTON_LEFT_IS_PRESSED && currentPressTime - startPressTime >= CLICK_TO_HOLD_TRANSITION) {

    // Check if the shift key is held down too or not
    if (modes == GLFW_MOD_CONTROL) {
      clickType = CONTROL_CLICK_DRAG;
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
      simMutex.lock();
      glm::mat4 model(1.0f);
      model = glm::translate(model, (glm::vec3) sim.planets.at(i).getPos());
      glm::vec4 screenLoc = projection * view * model * glm::vec4(glm::vec3(0.0f), 1.0f);
      simMutex.unlock();

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
    if (closestDist < 1)
      selected = closestInd;
    else
      selected = -1;

  } else if (clickType == CLICK_DRAG && selected != -1) {
    // Click and large mouse movement is moving planet position
    //    Move the planet in the position parallel to the "Face" of the camera
    //    We have Up and Right camera vector so just doing a multiple of those should work

    simMutex.lock();
    glm::vec3 planeNorm = glm::normalize(cameraPos - origin);
    float dist = 0;
    glm::intersectRayPlane(cameraPos, ray_wor, (glm::vec3) sim.planets.at(selected).getPos(), planeNorm, dist);
    sim.planets.at(selected).setPos(cameraPos + dist*ray_wor);
    simMutex.unlock();

  } else if (clickType == CONTROL_CLICK_DRAG && selected != -1) {
    // Shift click and drag is setting the velocity of the planet
    //    May need to change shift to ctrl to make things easier
    //    Similar to the position, but it draws a line instead from planet to mouse pos
    //    Golf it style

    simMutex.lock();
    glm::vec3 planeNorm = glm::normalize(cameraPos - origin);
    float dist = 0;
    glm::intersectRayPlane(cameraPos, ray_wor, (glm::vec3) sim.planets.at(selected).getPos(), planeNorm, dist);
    glm::vec3 diff = (cameraPos + dist*ray_wor) - (glm::vec3)sim.planets.at(selected).getPos();

    sim.planets.at(selected).setVel(diff*.00001f);
    simMutex.unlock();
  }
}

void keyboard_callback(GLFWwindow *window, int &pwr, int &mode) {
  // Note: Some of these may have to be slowed down since it may execute every frame
  // Try something like checking if GLFW_REPEATED is not true?

  // TODO: Set camera to specific positions based on a few select number keys

  // State machine to only execute stuff on the first instance of the pressed key
  static bool KEY_Q_IS_PRESSED = false;
  static bool KEY_A_IS_PRESSED = false;
  static bool KEY_C_IS_PRESSED = false; // Color shift
  static bool KEY_N_IS_PRESSED = false; // New planet
  static bool KEY_D_IS_PRESSED = false; // Delete planet
  static bool KEY_S_IS_PRESSED = false; // Start sim

  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }

  // ADD: Increase mass of selected planet
  if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
    if (selected != -1 && !KEY_Q_IS_PRESSED) {
      simMutex.lock();
      sim.planets.at(selected).setMass(sim.planets.at(selected).getMass() * 1.1);
      simMutex.unlock();
    }

    KEY_Q_IS_PRESSED = true;
  } else if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_RELEASE) {
    KEY_Q_IS_PRESSED = false;
  }

  // SUBTRACT: Decrease mass of selected planet
  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
    if (selected != -1 && !KEY_A_IS_PRESSED) {
      simMutex.lock();
      sim.planets.at(selected).setMass(sim.planets.at(selected).getMass() * 0.9);
      simMutex.unlock();
    }

    KEY_A_IS_PRESSED = true;
  } else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_RELEASE) {
    KEY_A_IS_PRESSED = false;
  }

  // C: Cycle colors of the selected planet
  if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
    if (selected != -1 && !KEY_C_IS_PRESSED) {
      simMutex.lock();
      sim.planets.at(selected).cycleColor();
      simMutex.unlock();
    }

    KEY_C_IS_PRESSED = true;
  } else if (glfwGetKey(window, GLFW_KEY_C) == GLFW_RELEASE) {
    KEY_C_IS_PRESSED = false;
  }

  // C: Cycle colors of the selected planet
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
    if (!KEY_S_IS_PRESSED && simThread == nullptr && !KEY_S_IS_PRESSED) {
      simThread = new std::thread(simulatorThread);
    }

    KEY_S_IS_PRESSED = true;
  } else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_RELEASE) {
    KEY_S_IS_PRESSED = false;
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