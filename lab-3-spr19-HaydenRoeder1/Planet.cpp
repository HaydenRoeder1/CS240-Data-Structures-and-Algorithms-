
#include <cstdlib>
#include <cstdio>
#include "Planet.h"
#include "Star.h"

Planet::Planet(int id){
	this->id = id;
	this->distance = rand() % 3000;
    	this->pos = rand() % 360;
	int randInd = rand() % 3;
	if(randInd == 0){
		this->type = 'r';
	}else if(randInd == 1){
		this->type = 'h';
	}else{
		this->type = 'g';
	}
}
int Planet::orbit(){
	this->pos++;
	this->pos = this->pos % 360;
	return this->pos;
}

