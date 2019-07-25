#ifndef STARVECTOR_HEADER_HR
#define STARVECTOR_HEADER_HR
#include "Planet.h"
#include "Vector.h"
class Starvector{
private:
  Vector * planetVector;
public:
  Starvector();
  ~Starvector();
  long addPlanet();
  bool removePlanet(int);
  Planet* getPlanet(int);
  void orbit();
  void printStarInfo();
  unsigned int getCurrentNumPlanets();
};
#endif
