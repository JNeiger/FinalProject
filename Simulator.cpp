//
// Created by Joe on 4/18/2018.
//

#include "Simulator.h"
#include <algorithm>

Simulator::Simulator(double dt) : timeStep(dt){}

void Simulator::addPlanet(Planet p) {
  planets.push_back(p);
}

void Simulator::removePlanet(Planet p) {
  planets.erase(std::remove(planets.begin(), planets.end(), p), planets.end());
}

std::vector<Planet> Simulator::getPlanets() {
  return planets;
}

void Simulator::step() {

  std::vector<glm::dvec3> netForce;

  // for each planet
  // for each other planet
  // F = G * m * m / d^2
  for (int i = 0; i < planets.size(); i++) {
    double G = 6.674e-11;

    // Push back 0
    netForce.push_back(glm::dvec3());

    for (int j = 0; j < planets.size(); j++) {
      // Make sure we don't calculate force to ourself
      if (i != j) {
        double ourMass       = planets.at(i).getMass();
        double theirMass     = planets.at(j).getMass();
        glm::dvec3 direction = planets.at(j).getPos() - planets.at(i).getPos();
        double distance      = glm::length(direction);
        // This line above gives an error but it's not actually an error
        // It's just intellisense blowing up

        // F = G*m*m / d^2 * dir_(us to them)
        netForce.at(i) += glm::normalize(direction) * G*ourMass*theirMass / (distance*distance);
      }
    }

  }
}