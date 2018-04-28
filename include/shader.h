//
// Created by Joe on 4/16/2018.
//

#ifndef FINALPROJECT_SHADER_H
#define FINALPROJECT_SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
  unsigned int ID;

  // Load and compile the shader
  Shader(const char* vertexPath, const char* fragmentPath);

  // Activates the shader
  void use();

  // Sets the uniform variables
  void setBool(const std::string &name, bool value) const;
  void setInt(const std::string &name, int value) const;
  void setFloat(const std::string &name, float value) const;
  void set2Float(const std::string &name, float value1, float value2) const;
  void set3Float(const std::string &name, float value1, float value2,  float value3) const;
  void setMat4(const std::string &name, glm::mat4 &mat) const;

private:
  // Prints out any compile errors
  void checkCompileErrors(unsigned int shader, std::string type);
};

#endif //FINALPROJECT_SHADER_H
