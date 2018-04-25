//
// Created by Joe on 4/24/2018.
//

#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Simulator.h"

// Mouse
bool firstMouse = true; // First mouse callback?
float lastX = WINDOW_WIDTH / 2.0f; // Where the last mouse position was
float lastY = WINDOW_HEIGHT / 2.0f;
bool rotateMode = false;

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

    glm::vec3 front;
    front.x = (float) (cos(glm::radians(yaw)) * cos(glm::radians(pitch)));
    front.y = (float) sin(glm::radians(pitch));
    front.z = (float) (sin(glm::radians(yaw)) * cos(glm::radians(pitch)));
    cameraPos = glm::normalize(front) * 5.0f;
  }
}

void mouse_button_callback(GLFWwindow *window, int button, int action, int mods) {
  // Action:
  //  GLFW_PRESS or GLFW_RELEASE
  // Mods:
  //  GLFW_MOD_SHIFT
  //  GLFW_MOD_CONTROL
  //  GLFW_MOD_ALT
  //  GLFW_MOD_SUPER
  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
    // Single click with very little mouse movement is planet select
    //    Find screen position that is clicked
    //    Convert all the planets to screen coordinates
    //    Check the closet one by radius
    //    If that's the closest, then select it

    // Click and large mouse movement is moving planet position
    //    Move the planet in the position parallel to the "Face" of the camera
    //    We have Up and Right camera vector so just doing a multiple of those should work
    //
    //
    // Shift click and drag is setting the velocity of the planet
    //    May need to change shift to ctrl to make things easier
    //    Similar to the position, but it draws a line instead from planet to mouse pos
    //    Golf it style
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


  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  } else if (glfwGetKey(window, GLFW_KEY_KP_ADD) == GLFW_PRESS) {
    // Increase mass of selected planet
  } else if (glfwGetKey(window, GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS) {
    // Decrease mass of selected planet
  } else if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
    // Cycle Colors of selected planet
  } else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
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