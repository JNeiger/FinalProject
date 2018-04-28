//
// Created by Joe on 4/18/2018.
//

#ifndef FINALPROJECT_PLANET_H
#define FINALPROJECT_PLANET_H

#include <glm/glm.hpp>

#define COLOR_RED    glm::vec3(1.0f, 0.0f, 0.0f)
#define COLOR_GREEN  glm::vec3(0.0f, 0.5f, 0.0f)
#define COLOR_BLUE   glm::vec3(0.0f, 0.0f, 1.0f)
#define COLOR_YELLOW glm::vec3(1.0f, 1.0f, 0.0f)
#define COLOR_ORANGE glm::vec3(1.0f, 0.6f, 0.0f)

class Planet {
public:
  Planet(double mass, float radius, uint8_t color);

  void setMass(double newMass);
  void setPos(glm::dvec3 newPos);
  void setVel(glm::dvec3 newVel);

  double getMass() const;
  glm::dvec3 getPos() const;
  glm::dvec3 getVel() const;
  glm::vec3 getColor() const;
  float getRadius() const;

  // Cycles the color one increment to the next set
  void cycleColor();

  // Called every timestep
  // @param netForce Net force applied on the body
  // @param dt Time step to take when applying the new force
  void update(glm::dvec3 netForce, double dt);

  bool operator==(const Planet &rhs);

private:
  double mass;
  glm::dvec3 pos;
  glm::dvec3 vel;

  float radius;
  uint8_t color;
  const static glm::vec3 colorArr[];
};

#endif //FINALPROJECT_PLANET_H
