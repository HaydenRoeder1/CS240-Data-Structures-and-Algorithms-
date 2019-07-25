
#include <cstdlib>
#include <cstdio>
#include "Planet.h"
#include "Star.h"

/*Star*/
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
int Star::addPlanet(){
	if(this->planets == NULL){
		this->current_planets++;
		this->planets = new Planet*[1];
		this->next_id++;
		this->planets[0] = new Planet(this->next_id);
		return this->next_id;
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
		printf("\t Planet %c%d is %d million miles away at position %d around the star.\n",
			this->planets[i]->getType(),
			this->planets[i]->getID(),
			this->planets[i]->getDistance(),
			this->planets[i]->getPos());
	}
}




