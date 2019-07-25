#ifndef STAR_HEADER_HR
#define STAR_HEADER_HR
#include <vector>
#include "Planet.h"
class Star{
private:
  std::vector<Planet> planets;
public:
  unsigned long addPlanet();
  bool removePlanet(unsigned long);
  Planet * getPlanet(unsigned long);
  std::vector<Planet>& getPlanets();

};

#endif
