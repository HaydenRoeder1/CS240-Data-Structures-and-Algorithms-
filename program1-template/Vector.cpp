#include "Vector.h"
#include <cstdlib>
//
Vector::Vector(){
	vSize = 0;
	planets = new Planet*[vSize];
	// You must create your internal array on the heap (using new).
}

Vector::~Vector(){
	for(unsigned int i = 0; i < vSize; i++){
		delete planets[i];
	}
	delete[] planets;
}

void Vector::insert(int index, Planet*p){
	if((unsigned int)index > vSize){
		unsigned int oldSize = vSize;
		vSize = index + 1;
		Planet ** newPlanets = new Planet*[vSize];
		for(unsigned int i = 0; i < oldSize; i++){
			newPlanets[i] = planets[i];
		}
		for(unsigned int i = oldSize; i < vSize-1; i++){
			newPlanets[i] = NULL;
		}
		newPlanets[vSize-1] = p;
		delete[] planets;
		planets = newPlanets;
	}else{
		vSize++;
		Planet ** newPlanets = new Planet*[vSize];
		for(unsigned int i = 0, j = 0; i < vSize; i++){
			if(i == (unsigned int)index){
				newPlanets[i] = p;
			}
			else{
				newPlanets[i] = planets[j];
				j++;
			}
		}
		delete[] planets;
		planets = newPlanets;
	}
}

Planet* Vector::read(int index){
	if((unsigned int)index >= vSize || index < 0){
		return NULL;
	}
	else{
		return planets[index];
	}
}

bool Vector::remove(int index){
	if(index < 0 || (unsigned int)index >= vSize){return false;}
	Planet ** newPlanets = new Planet*[vSize - 1];
	for(unsigned int i = 0, j = 0; i < vSize; i++){
		if(i == (unsigned int)index){
			delete planets[i];
		}else{
			newPlanets[j] = planets[i];
			j++;
		}
	}
	vSize--;
	delete[] planets;
	planets = newPlanets;
	return true;
}

unsigned Vector::size(){
	return vSize;
 }
