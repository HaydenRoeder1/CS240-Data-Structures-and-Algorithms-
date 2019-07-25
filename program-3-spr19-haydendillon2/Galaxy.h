#ifndef GALAXY_HEADER_HR
#define GALAXY_HEADER_HR
#include <string>
#include <vector>
#include "Planet.h"
class Galaxy{
private:
  std::vector<Planet*> planets;
public:
  Galaxy(std::string filename);
  ~Galaxy();
  unsigned int size();
  Planet* findByName(std::string planetName);
	std::vector<Planet*> shortestPath(Planet*, Planet*);
	double pathDistance(Planet*, Planet*);
  void printPlanets();
};
#endif
