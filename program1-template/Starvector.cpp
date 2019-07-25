#include <cstdlib>
#include <cstdio>
#include "Starvector.h"
Starvector::Starvector(){
  planetVector = new Vector();
}
Starvector::~Starvector(){
  delete planetVector;
}
long Starvector::addPlanet(){
  Planet * planetToAdd = new Planet(rand() % 3000)
  planetVector->insert(planetVector->size(), planetToAdd);
  return planetToAdd;
}
bool Starvector::removePlanet(int id){
  for(unsigned int i = 0; i < planetVector->size(); i++){
    if(planetVector->read(i)->getID() == id){
      planetVector->remove(i);
      return true;
    }
  }
  return false;
}
Planet* getPlanet(int id){
  for(unsigned int i = 0; i < planetVector->getSize(); i++){
    if(planetVector->read(i)->getID() == id){
      return planetVector->read(i);
    }
  }
  return NULL;
}
void Starvector::orbit(){
	for(unsigned int i = 0; i < planetVector->getSize(); i++){
		planetVector->read(i)->orbit();
	}
}
void Starvector::printStarInfo(){
	printf("The star currently has %d planets.\n", planetVector->getSize());
	printf("Planets:\n");
	for(unsigned int i = 0; i < planetVector->getSize(); i++){
		printf("\t Planet %c%lu is %d million miles away at position %d around the star.\n",
			planetVector->read(i)->getType(),
			planetVector->read(i)->getID(),
			planetVector->read(i)->getDistance(),
			planetVector->read(i)->getPos());
	}
}
unsigned int Starvector::getCurrentNumPlanets(){
	return planetVector->getSize();
}
