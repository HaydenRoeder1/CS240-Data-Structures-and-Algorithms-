#include "Star.h"
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
unsigned long Star::addPlanet(){
  Planet  pToAdd(rand() % 3000);
  planets.push_back(pToAdd);
  return pToAdd.getID();
}
bool Star::removePlanet(unsigned long id){
  int indexToRemove = -1;
  for(unsigned int i = 0; i < planets.size(); i++){
    if((planets[i]).getID() == id){
      indexToRemove = i;
    }
  }
  if(indexToRemove != -1){
    planets.erase(planets.begin() + indexToRemove);
    return true;
  }
  return false;
}
Planet * Star::getPlanet(unsigned long id){
  for(unsigned int i = 0; i < planets.size(); i++){
	if((planets[i]).getID() == id){
		return &(planets[i]);
	}
  }
  return nullptr;

}
vector<Planet>& Star::getPlanets(){
  return planets;
}
