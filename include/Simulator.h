//
// Created by Joe on 4/18/2018.
//

#ifndef FINALPROJECT_SIMULATOR_H
#define FINALPROJECT_SIMULATOR_H
#include <vector>

#include "Planet.h"


class Simulator {
public:
  Simulator(double dt);

  void addPlanet(Planet p);
  void removePlanet(Planet p);

  // TODO: Figure out what to do here
  std::vector<Planet> getPlanets();

  // Steps one timestep
  // If dt is not used, it uses the default step size
  void step();
private:
  double timeStep;
  std::vector<Planet> planets;
};

#endif //FINALPROJECT_SIMULATOR_H
