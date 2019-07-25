#include "Planet.h"
#include <cstdlib>
unsigned long Planet::unique_id = 0;
Planet::Planet(int distance){
	this->id = ++unique_id;
	this->distance = distance;
	int randInd = rand() % 3;
	if(randInd == 0){
		this->type = 'r';
	}else if(randInd == 1){
		this->type = 'h';
	}else{
		this->type = 'g';
	}
}
