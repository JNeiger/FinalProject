#include <iostream>
#include <thread>
#include <mutex>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "Simulator.h"
#include "Camera.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void renderSphere();

const unsigned int WINDOW_WIDTH = 800;
const unsigned int WINDOW_HEIGHT = 600;

// Camera position / facing vectors
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 40.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
glm::vec3 origin = glm::vec3(0.0f, 0.0f, 0.0f);

// Camera facing angles
float yaw = 90.0f;
float pitch = 0.0f;
float fov = 45.0f; // Field of view

Simulator sim(0.0001);
std::thread *simThread = nullptr;
std::mutex simMutex;

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
  glfwSetCursorPosCallback(window, mouse_pos_callback);
  glfwSetMouseButtonCallback(window, mouse_button_callback);
  glfwSetScrollCallback(window, scroll_callback);

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

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  int w, h;
  float cx = 0.0f, cy = 0.0f, zoom = 0.4f;
  int itr = 100;
  int pwr = 2;
  int mode = 0;

  Planet sun    (1.989 * pow(10, 30), 3, 3);
  Planet mercury(0.330 * pow(10, 24), 4.879 / 12.104, 0);
  Planet venus  (4.87 * pow(10, 24), 12.104 / 12.104, 4);
  Planet earth  (5.97 * pow(10, 24), 12.756 / 12.104, 1);

  sun.setPos(glm::dvec3(0, 0, 0));
  mercury.setPos(glm::dvec3(57.9 * pow(10, 9), 0, 0));
  venus.setPos(glm::dvec3(108.2 * pow(10, 9), 0, 0));
  earth.setPos(glm::dvec3(149.6 * pow(10, 9), 0, 0));

  sun.setVel(glm::dvec3(0, 0, 0));
  mercury.setVel(glm::dvec3(0, 47.4 * pow(10, 3), 0));
  venus.setVel(glm::dvec3(0, 35.0 * pow(10, 3), 0));
  earth.setVel(glm::dvec3(0, 29.8 * pow(10, 3), 0));

  sim.addPlanet(sun);
  sim.addPlanet(mercury);
  sim.addPlanet(venus);
  sim.addPlanet(earth);

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


    glBindVertexArray(VAO);

    for (int i = 0; i < sim.planets.size(); i++) {
      simMutex.lock();

      glm::mat4 model(1.0f);
      glm::vec3 pos = (glm::vec3)sim.planets.at(i).getPos();
      glm::vec3 color = sim.planets.at(i).getColor();

      pos /= pow(10, 10);

      model = glm::translate(model, pos);
      shad.setMat4("model", model);
      shad.setFloat("radius", sim.planets.at(i).getRadius());

      shad.set3Float("color", color.x, color.y, color.z);

      renderSphere();

      simMutex.unlock();
    }

    // TODO: Decide if this is actually a good idea
    //simMutex.lock();
    //origin = (glm::vec3)sim.planets.at(0).getPos();
    //simMutex.unlock();

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

// Renders a sphere
// Taken from the learnopengl tutorial
unsigned int sphereVAO = 0;
unsigned int indexCount;
void renderSphere()
{
  if (sphereVAO == 0)
  {
    glGenVertexArrays(1, &sphereVAO);

    unsigned int vbo, ebo;
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> uv;
    std::vector<glm::vec3> normals;
    std::vector<unsigned int> indices;

    const unsigned int X_SEGMENTS = 64;
    const unsigned int Y_SEGMENTS = 64;
    const float PI = 3.14159265359;
    for (unsigned int y = 0; y <= Y_SEGMENTS; ++y)
    {
      for (unsigned int x = 0; x <= X_SEGMENTS; ++x)
      {
        float xSegment = (float)x / (float)X_SEGMENTS;
        float ySegment = (float)y / (float)Y_SEGMENTS;
        float xPos = std::cos(xSegment * 2.0f * PI) * std::sin(ySegment * PI);
        float yPos = std::cos(ySegment * PI);
        float zPos = std::sin(xSegment * 2.0f * PI) * std::sin(ySegment * PI);

        positions.push_back(glm::vec3(xPos, yPos, zPos));
        uv.push_back(glm::vec2(xSegment, ySegment));
        normals.push_back(glm::vec3(xPos, yPos, zPos));
      }
    }

    bool oddRow = false;
    for (int y = 0; y < Y_SEGMENTS; ++y)
    {
      if (!oddRow) // even rows: y == 0, y == 2; and so on
      {
        for (int x = 0; x <= X_SEGMENTS; ++x)
        {
          indices.push_back(y       * (X_SEGMENTS + 1) + x);
          indices.push_back((y + 1) * (X_SEGMENTS + 1) + x);
        }
      }
      else
      {
        for (int x = X_SEGMENTS; x >= 0; --x)
        {
          indices.push_back((y + 1) * (X_SEGMENTS + 1) + x);
          indices.push_back(y       * (X_SEGMENTS + 1) + x);
        }
      }
      oddRow = !oddRow;
    }
    indexCount = indices.size();

    std::vector<float> data;
    for (int i = 0; i < positions.size(); ++i)
    {
      data.push_back(positions[i].x);
      data.push_back(positions[i].y);
      data.push_back(positions[i].z);
      if (uv.size() > 0)
      {
        data.push_back(uv[i].x);
        data.push_back(uv[i].y);
      }
      if (normals.size() > 0)
      {
        data.push_back(normals[i].x);
        data.push_back(normals[i].y);
        data.push_back(normals[i].z);
      }
    }
    glBindVertexArray(sphereVAO);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
    float stride = (3 + 2 + 3) * sizeof(float);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, stride, (void*)(5 * sizeof(float)));
  }

  glBindVertexArray(sphereVAO);
  glDrawElements(GL_TRIANGLE_STRIP, indexCount, GL_UNSIGNED_INT, 0);
}