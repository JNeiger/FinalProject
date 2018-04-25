//
// Created by Joe on 4/24/2018.
//

#ifndef FINALPROJECT_CAMERA_H
#define FINALPROJECT_CAMERA_H

#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>

extern const unsigned int WINDOW_WIDTH;
extern const unsigned int WINDOW_HEIGHT;

extern glm::vec3 cameraPos;
extern glm::vec3 cameraUp;
extern glm::vec3 origin;

// Camera facing angles
extern float yaw;
extern float pitch;
extern float fov; // Field of view


void mouse_pos_callback(GLFWwindow *window, double xpos, double ypos);
void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
void keyboard_callback(GLFWwindow *window, int &pwr, int &mode);

#endif //FINALPROJECT_CAMERA_H
