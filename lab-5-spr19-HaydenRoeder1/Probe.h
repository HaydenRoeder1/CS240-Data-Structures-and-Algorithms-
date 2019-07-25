#ifndef PROBE_HEADER_HR
#define PROBE_HEADER_HR
#include <vector>
#include <queue>
#include "Star.h"
#include "Planet.h"
class Probe{
private:
  std::queue<Planet> pQueue;
public:
  std::vector<Planet> getHabitable(Star);
  void addToQueue(Planet p);
  Planet getNext();
  std::queue<Planet>& getQueue();
  void shuffle();
};
#endif
