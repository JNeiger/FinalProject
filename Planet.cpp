//
// Created by Joe on 4/18/2018.
//

#include "Planet.h"

Planet::Planet(double mass, float radius, uint8_t color) : mass(mass), radius(radius) {
  // TODO: Set up the colors
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

void Planet::cycleColor() {
  // TODO: Cycle colors
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
  return mass == rhs.getMass() && pos == rhs.getPos();
}