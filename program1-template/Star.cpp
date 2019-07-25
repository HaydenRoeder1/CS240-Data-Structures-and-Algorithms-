
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "Planet.h"
#include "Star.h"
//STAR LIST
Starlist::Starlist(){
	planets = new List();
}
Starlist::~Starlist(){
	delete planets;
}
long Starlist::addPlanet(){
//	printf("Starlist::addPlanet called\n");
	Planet * planetToAdd = new Planet(rand() % 3000);
	planets->insert(planets->size()-1, planetToAdd);
	return (long)planetToAdd;
}
bool Starlist::removePlanet(int id){
//	printf("Starlist::removePlanet called\n");
	for(unsigned int i = 0; i < planets->size(); i++){
		if((unsigned)(planets->read(i)->getID()) == (unsigned)id){
			planets->remove(i);
			return true;
		}
	}
	return false;
}
Planet* Starlist::getPlanet(int id){
//	printf("Starlist::getPlanet called\n");
	for(unsigned int i = 0; i < planets->size(); i++){
		if((unsigned)(planets->read(i)->getID()) == (unsigned)id){
			return planets->read(i);
		}
	}
	return NULL;
}
void Starlist::orbit(){
//	printf("Starlist::orbit called\n");
	for(unsigned int i = 0; i < planets->size(); i++){
		planets->read(i)->orbit();
	}
}
void Starlist::printStarInfo(){
	printf("The star currently has %d planets.\n", planets->size());
	printf("Planets:\n");
	for(unsigned int i = 0; i < planets->size(); i++){
		printf("\t Planet %c%lu is %d million miles away at position %d around the star.\n",
			planets->read(i)->getType(),
			planets->read(i)->getID(),
			planets->read(i)->getDistance(),
			planets->read(i)->getPos());
	}
}
unsigned int Starlist::getCurrentNumPlanets(){
	return planets->size();
}
//STAR VECTOR
Starvector::Starvector(){
  planetVector = new Vector();
}
Starvector::~Starvector(){
  delete planetVector;
}
long Starvector::addPlanet(){
//	printf("Starvector::addPlanet called\n");
  Planet * planetToAdd = new Planet(rand() % 3000);
  planetVector->insert(planetVector->size(), planetToAdd);
  return (long)planetToAdd;
}
bool Starvector::removePlanet(int id){
//	printf("Starvector::removePlanet called\n");
  for(unsigned int i = 0; i < planetVector->size(); i++){
    if((unsigned)(planetVector->read(i)->getID()) == (unsigned)id){
      planetVector->remove(i);
      return true;
    }
  }
  return false;
}
Planet* Starvector::getPlanet(int id){
//	printf("Starvector::getPlanet called\n");
  for(unsigned int i = 0; i < planetVector->size(); i++){
    if((unsigned)(planetVector->read(i)->getID()) == (unsigned)id){
      return planetVector->read(i);
    }
  }
  return NULL;
}
void Starvector::orbit(){
//	printf("Starvector::orbit called\n");
	for(unsigned int i = 0; i < planetVector->size(); i++){
		planetVector->read(i)->orbit();
	}
}
void Starvector::printStarInfo(){
	printf("The star currently has %d planets.\n", planetVector->size());
	printf("Planets:\n");
	for(unsigned int i = 0; i < planetVector->size(); i++){
		printf("\t Planet %c%lu is %d million miles away at position %d around the star.\n",
			planetVector->read(i)->getType(),
			planetVector->read(i)->getID(),
			planetVector->read(i)->getDistance(),
			planetVector->read(i)->getPos());
	}
}
unsigned int Starvector::getCurrentNumPlanets(){
	return planetVector->size();
}

/* Old Star
Star::Star(){
	this->current_planets = 0;
	this->planets = NULL;
	this->next_id = 0;
}
Star::~Star(){
	for(int i = 0; i < current_planets; i++){
		delete planets[i];
	}


	delete[] this->planets;


}
long int Star::addPlanet(){
	if(this->planets == NULL){
		this->current_planets++;
		this->planets = new Planet*[1];
		this->next_id++;
		this->planets[0] = new Planet(rand() % 3000);
		return this->planets[0]->getID();
	}
	this->current_planets++;
	Planet ** newPlanets = new Planet*[this->current_planets];
	for(int i = 0; i < this->current_planets - 1; i++){
		newPlanets[i] = this->planets[i];
	}
	this->next_id++;
	Planet * planetToAdd = new Planet(this->next_id);
	newPlanets[current_planets - 1] = planetToAdd;
	delete[] this->planets;
	this->planets = newPlanets;
	return planetToAdd->getID();
}
bool Star::removePlanet(int id){
	for(int i = 0; i < this->current_planets; i++){
		if((*(this->planets[i])).getID() == id){
			Planet ** newArr = new Planet*[this->current_planets - 1];
			for(int x = 0, j = 0; x < current_planets; x++){
				if(x == i){
					delete this->planets[x];
					continue;
				}
				newArr[j] = this->planets[x];
				j++;
			}
			delete[] this->planets;
			this->planets = newArr;
			this->current_planets--;
			return true;
		}
	}
	return false;
}
Planet * Star::getPlanet(int id){
	for(int i = 0; i < this->current_planets; i++){
		if(this->planets[i]->getID() == id){
			return this->planets[i];
		}
	}
	return NULL;
}
Planet Star::getFurthest(){
	int furthestIndex = 0;
	for(int i = 0; i < this->current_planets; i++){
		if(this->planets[i]->getDistance() > this->planets[furthestIndex]->getDistance()){
			furthestIndex = i;
		}
	}
	return *(this->planets[furthestIndex]);
}
void Star::orbit(){
	for(int i = 0; i < this->current_planets; i++){
		this->planets[i]->orbit();
	}
}
void Star::printStarInfo(){
	printf("The star currently has %d planets.\n", this->current_planets);
	printf("Planets:\n");
	for(int i = 0; i < this->current_planets; i++){
		printf("\t Planet %c%lu is %d million miles away at position %d around the star.\n",
			this->planets[i]->getType(),
			this->planets[i]->getID(),
			this->planets[i]->getDistance(),
			this->planets[i]->getPos());
	}
}
*/
