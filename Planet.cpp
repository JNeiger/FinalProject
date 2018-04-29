//
// Created by Joe on 4/18/2018.
//

#include "Planet.h"

const glm::vec3 Planet::colorArr[] =
    {COLOR_RED, COLOR_BLUE, COLOR_GREEN, COLOR_YELLOW, COLOR_ORANGE};

int Planet::idCtr = 0;

Planet::Planet(double mass, float radius, uint8_t color) : mass(mass), radius(radius), color(color), id(idCtr) {
  idCtr++;
}

void Planet::setMass(double newMass) {
  mass = newMass;
}

void Planet::setPos(glm::dvec3 newPos) {
  pos = newPos;
}

void Planet::setVel(glm::dvec3 newVel) {
  vel = newVel;
}

double Planet::getMass() const {
  return mass;
}

glm::dvec3 Planet::getPos() const {
  return pos;
}

glm::dvec3 Planet::getVel() const {
  return vel;
}

glm::vec3 Planet::getColor() const {
  return colorArr[color];
}

float Planet::getRadius() const {
  return radius;
}

void Planet::cycleColor() {
  color = ++color % 5;
}

// Called every timestep
// @param netForce Net force applied on the body
// @param dt Time step to take when applying the new force
void Planet::update(glm::dvec3 netForce, double dt) {
  vel += netForce / mass * dt; // a = F/m
  pos += vel * dt;
}

bool Planet::operator==(const Planet &rhs) {
  // They should never have the same location otherwise the simulator will break
  // so this should work, if not, we can assign ID's to each planet and do it
  // the right way
  return id == rhs.id;
}