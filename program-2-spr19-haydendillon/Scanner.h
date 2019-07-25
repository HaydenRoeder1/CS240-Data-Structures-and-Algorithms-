#ifndef SCANNER_HEADER_HR
#define SCANNER_HEADER_HR
#include "Heap.h"
#include <vector>
#include "Planet.h"
class Scanner{
private:
  Heap<Planet> planets;
public:
  Scanner(std::vector<Planet>);
  std:: vector<Planet> scan(unsigned int num_planets);
  void addPlanet(Planet);
  Heap<Planet> getHeap();
};
#endif
