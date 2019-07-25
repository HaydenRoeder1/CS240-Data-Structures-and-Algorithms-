#include "Planet.h"
#define MAX_ADJACENTS_SIZE 4
#include <math.h>


Planet::Planet(std::string planetName, long xCoor, long yCoor, long zCoor){
  name = planetName;
  x = xCoor;
  y = yCoor;
  z = zCoor;
	color = 0;
  last = NULL;
  gVal = 0;
  fVal = 0;
}

void Planet::addAdjacent(Planet* pToAdd){
  std::vector<Planet*> adjacentsVec{ std::begin(adjacents), std::end(adjacents) };
	double tempDistance = distanceBetween(pToAdd);
	if(adjacentsVec.size() < MAX_ADJACENTS_SIZE){//If adjacents is not full, add the planet while keeping the list sorted
		adjacentsVec.push_back(pToAdd);
		for(int i = adjacentsVec.size()- 1; i > 0; i--){ //Sift to the proper position
			if(tempDistance < distanceBetween(adjacentsVec[i-1])){
				Planet* temp = adjacentsVec[i-1];
				adjacentsVec[i-1] = adjacentsVec[i];
				adjacentsVec[i] = temp;
			}
		}
	}else{//Otherwise add new planet to the end if it is closer than the farthest adjacent planet
		if(tempDistance < distanceBetween(adjacentsVec[MAX_ADJACENTS_SIZE - 1])){
			adjacentsVec[MAX_ADJACENTS_SIZE - 1] = pToAdd;
      for(int i = adjacentsVec.size()- 1; i > 0; i--){
  			if(tempDistance < distanceBetween(adjacentsVec[i-1])){ //Sift to the proper position
  				Planet* temp = adjacentsVec[i-1];
  				adjacentsVec[i-1] = adjacentsVec[i];
  				adjacentsVec[i] = temp;
  			}
  		}
		}
	}
  adjacents.clear();
  //Sorted clostest to farthest
  std::copy( adjacentsVec.begin(), adjacentsVec.end(), std::back_inserter( adjacents ) );

}
void Planet::reverseAdjacents(){
  adjacents.reverse();
}
std::list<Planet*> Planet::getAdjacent(){
  return adjacents;
}


double Planet::distanceBetween(Planet* other){
	long oX = other->getXCoor();
	long oY = other->getYCoor();
	long oZ = other->getZCoor();

	long diffX = oX - x;
	long diffY = oY - y;
	long diffZ = oZ - z;

	diffX = pow(diffX, 2);
	diffY = pow(diffY, 2);
	diffZ = pow(diffZ, 2);

	double total = diffX + diffY + diffZ;
	total = pow(total, .5);

	return total;
}

bool Planet::operator>(Planet other){
  return (this->fVal) > (other.fVal);
}
bool Planet::operator<(Planet other){
  return (this->fVal) < (other.fVal);
}
bool Planet::operator>=(Planet other){
  return (this->fVal) >= (other.fVal);
}
bool Planet::operator<=(Planet other){
  return (this->fVal) <= (other.fVal);
}
bool Planet::operator==(Planet other){
  return (this->fVal) == (other.fVal);
}
