#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "Simulator.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow *window, double xpos, double ypos);
void keyboard_callback(GLFWwindow *window, int &pwr, int &mode);

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

// Camera position / facing vectors
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 5.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 origin = glm::vec3(0.0f, 0.0f, 0.0f);

// Mouse
bool firstMouse = true; // First mouse callback?
float lastX = WINDOW_WIDTH / 2.0f; // Where the last mouse position was
float lastY = WINDOW_HEIGHT / 2.0f;
bool rotateMode = false;

// Camera facing angles
float yaw = 90.0f;
float pitch = 0.0f;
float fov = 45.0f; // Field of view

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Joseph Neiger", nullptr, nullptr);

  if (window == nullptr) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);


  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  glfwSetCursorPosCallback(window, mouse_callback);

  // Capture mouse
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

  glEnable(GL_DEPTH_TEST);
  Shader shad("shader.vs", "shader.fs");

  // Simple Plane
  float vertices[] = {
       1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
       1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
      -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
      -1.0f,  1.0f, 0.0f, 0.0f, 1.0f
  };

  // Tetrahedren
  float vertices2[] = {
       sqrt(8.0f/9.0f),             0.0f, -1.0f/3.0f, 1.0f, 1.0f,
      -sqrt(2.0f/9.0f),  sqrt(2.0f/3.0f), -1.0f/3.0f, 1.0f, 0.0f,
      -sqrt(2.0f/9.0f), -sqrt(2.0f/3.0f), -1.0f/3.0f, 0.0f, 0.0f,
                  0.0f,             0.0f,       1.0f, 0.0f, 1.0f
  };

  // Simple Plane
  unsigned int indices[] = {
      0, 1, 3,
      1, 2, 3
  };

  // Tetrahedren
  unsigned int indices2[] = {
      0, 1, 2,
      0, 1, 3,
      0, 2, 3,
      1, 2, 3
  };

  unsigned int VAO;
  unsigned int VBO;
  unsigned int EBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  unsigned int name;

  glGenTextures(1, &name);
  glBindTexture(GL_TEXTURE_2D, name);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  int width, height, nrChannels;
  stbi_set_flip_vertically_on_load(true);
  unsigned char *data = stbi_load("../name.png", &width, &height, &nrChannels, 0);

  std::cout << nrChannels << std::endl;

  if (data) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    std::cout << "Failed to load texture" << std::endl;
  }

  stbi_image_free(data);

  shad.setInt("name", 0);

  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  int w, h;
  float cx = 0.0f, cy = 0.0f, zoom = 0.4f;
  int itr = 100;
  int pwr = 2;
  int mode = 0;

  Simulator sim(0.001);
  Planet p1(10, 10, 0);
  Planet p2(10, 10, 0);
  Planet p3(10, 10, 0);

  p1.setPos(glm::dvec3(-1, 1, 0));
  p2.setPos(glm::dvec3(1, 1, 1));
  p3.setPos(glm::dvec3(0, 0, 0));

  sim.addPlanet(p1);
  sim.addPlanet(p2);
  sim.addPlanet(p3);

  while (!glfwWindowShouldClose(window)) {
    // Keyboard inputs
    keyboard_callback(window, pwr, mode);

    // Clear frame buffer to a gray
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Setup textures
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, name);

    // Setup the shader to use and get window size
    shad.use();
    glfwGetWindowSize(window, &w, &h);

    // Setup camera matrices
    glm::mat4 projection = glm::perspective(glm::radians(fov), (float)w / (float)h, 0.1f, 100.0f);
    glm::mat4 view = glm::lookAt(cameraPos, origin, cameraUp);
    shad.setMat4("projection", projection);
    shad.setMat4("view", view);


    // Set all the global uniforms for the shader
    shad.setFloat("screen_ratio", (float)w / (float)h);
    shad.set2Float("screen_size", (float)w , (float)h);
    shad.set2Float("center", cx, cy);
    shad.setFloat("zoom", zoom);
    shad.setInt("itr", itr);
    shad.setInt("pwr", pwr);
    shad.setInt("mode", mode);

    glBindVertexArray(VAO);

    std::vector<Planet> planets = sim.getPlanets();
    for (int i = 0; i < planets.size(); i++) {
      glm::mat4 model(1.0f);
      model = glm::translate(model, (glm::vec3)planets.at(i).getPos());
      shad.setMat4("model", model);
      glDrawElements(GL_TRIANGLES, sizeof(indices2), GL_UNSIGNED_INT, 0);
    }

    glBindVertexArray(0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);

  glfwTerminate();
  return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow *window, double xpos, double ypos) {
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

void keyboard_callback(GLFWwindow *window, int &pwr, int &mode) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  } else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
    pwr = 2;
  } else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {
    pwr = 3;
  } else if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS) {
    pwr = 4;
  } else if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS) {
    pwr = 5;
  } else if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS) {
    pwr = 6;
  } else if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS) {
    pwr = 7;
  } else if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS) {
    pwr = 8;
  } else if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) {
    mode = 0;
  } else if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) {
    mode = 1;
  } else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
    // Only allow this on the first instance the shift key is pressed
    if (!rotateMode) {
      rotateMode = true;
      glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
      firstMouse = true;
    }
  } else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE) {
    // Only allow this on the first instance the shift key is released
    if (rotateMode) {
      rotateMode = false;
      glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }
  }
}