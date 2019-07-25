
#include <cstdlib>
#include <cstdio>
#include "Star.h"

/*Star*/
Star::Star(int numPlanets){
	this->max_planets = numPlanets;	
	this->current_planets = 0;
	this->next_id = 0;
	for(int i = 0; i < max_planets; i++){
		this->planets[i] = Planet(0,0);
	}
	
}
bool Star::addPlanet(){
	if(this->current_planets < this->max_planets){
		this->current_planets++;
		this->next_id++;
		this->planets[current_planets] = Planet(rand() % 3000, this->next_id);	
		return true;
	}
	return false;
}
Planet Star::getFurthest(){
	int furthestIndex = 0;
	for(int i = 0; i < this->current_planets; i++){
		if(this->planets[i].getDistance() > this->planets[furthestIndex].getDistance()){
			furthestIndex = i;
		}
	}
	return this->planets[furthestIndex];
}
void Star::orbit(){
	for(int i = 0; i < this->current_planets; i++){
		this->planets[i].orbit();
	}
}
void Star::printStarInfo(){
	printf("The star currently has %d planets.\n", this->current_planets);
	printf("The star can support up to %d planets.\n", this->max_planets);
	printf("Planets:\n");
	for(int i = 0; i < this->current_planets; i++){
		printf("\t Planet %d is %d million miles away at position %d around the star.\n",
			this->planets[i].getID(),
			this->planets[i].getDistance(),
			this->planets[i].getPos());
	}
}
int Star::getCurrentNumPlanets(){
	return this->current_planets;
}
int Star::getMaxPlanets(){
	return this->max_planets;
}

/*Planet*/
Planet::Planet(int distance, int id){
	this->id = id;
	this->distance = distance;
    	this->pos = 0;
}
int Planet::orbit(){
	this->pos++;
	this->pos = this->pos % 360;
	return this->pos;
}
int Planet::getID(){
	return this->id;
}
int Planet::getDistance(){
	return this->distance;
}
int Planet::getPos(){
	return this->pos;
}
