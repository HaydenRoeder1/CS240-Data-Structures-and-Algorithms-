#include "Scanner.h"
#include <vector>
#include "Planet.h"
Scanner::Scanner(std::vector<Planet> planetList){

  Heap<Planet> h(planetList);
  planets = h;//?

}
std::vector<Planet> Scanner::scan(unsigned int num_planets){

  if(num_planets > (unsigned int) planets.size()){
   num_planets = (unsigned int) planets.size();
  }
  std::vector<Planet> scanned;
  for(int i = 0; i < num_planets; i++){
    Planet curPlanet = planets.getPriority();
    double randChange = (rand() % 2);
    if(randChange == 0){
      randChange = -1;
    }else{
      randChange = 1;
    }

    if(curPlanet.getProbability() != 0 && curPlanet.getProbability() != 100)
      curPlanet.refine(randChange);
    scanned.push_back(curPlanet);
  }

  return scanned;

}
void Scanner::addPlanet(Planet p){
  planets.addElement(p);
}
Heap<Planet> Scanner::getHeap(){
  return planets; //?
}
