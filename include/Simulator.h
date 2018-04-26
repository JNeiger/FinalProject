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

  // Steps one timestep
  // If dt is not used, it uses the default step size
  void step();

  std::vector<Planet> planets;
private:
  double timeStep;
};

#endif //FINALPROJECT_SIMULATOR_H
