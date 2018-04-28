//
// Created by Joe on 4/18/2018.
//

#include "Simulator.h"
#include <algorithm>
#include <iostream>
#include <thread>
#include <chrono>
#include <glfw/glfw3.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
void simulatorThread() {
  std::cout << "Sim thread started" << std::endl;

  while (true) {
    float startTime = glfwGetTime();
    simMutex.lock();
    sim.step();
    simMutex.unlock();
    float diff = glfwGetTime() - startTime;

    //std::this_thread::sleep_for(std::chrono::seconds(5));
    if (diff < sim.timeStep) {
      // How much faster than real time to run
      float scale = 0.5;
      std::this_thread::sleep_for(std::chrono::nanoseconds((long)((sim.timeStep - diff) * 1000000000 / scale)));
    }
  }
}
#pragma clang diagnostic pop

Simulator::Simulator(double dt) : timeStep(dt){}

void Simulator::addPlanet(Planet p) {
  planets.push_back(p);
}

void Simulator::removePlanet(Planet p) {
  planets.erase(std::remove(planets.begin(), planets.end(), p), planets.end());
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

        // Make sure nothing blows up when they get too close
        distance = std::max(0.1, distance);

        // F = G*m*m / d^2 * dir_(us to them)
        netForce.at(i) += glm::normalize(direction) * G*ourMass*theirMass / (distance*distance);
      }
    }
  }

  for (int i = 0; i < planets.size(); i++) {
    glm::dvec3 vel = planets.at(i).getVel();
    glm::dvec3 accel = netForce.at(i) / planets.at(i).getMass();
    planets.at(i).setPos(planets.at(i).getPos() + vel);
    planets.at(i).setVel(vel + accel);
  }
}