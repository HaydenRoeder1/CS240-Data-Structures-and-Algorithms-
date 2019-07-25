#include "Planet.h"

/*
Planet(string id, double probability);
double refine(double r);

*/

Planet::Planet(std::string id, double probability){
  this->id = id;
  this->probability = probability;

}
double Planet::refine(double r){
  this->probability += r;
  if(this->probability > 100){
    this->probability = 100;
  }
  if(this->probability < 0){
    this->probability = 0;
  }
  return this->probability;
}
bool Planet::operator>(Planet other){
  return this->probability > other.probability;
}
bool Planet::operator<(Planet other){
  return this->probability < other.probability;
}
bool Planet::operator>=(Planet other){
  return this->probability >= other.probability;
}
bool Planet::operator<=(Planet other){
  return this->probability <= other.probability;
}
bool Planet::operator==(Planet other){
  return this->probability == other.probability;
}
bool Planet::operator!=(Planet other){
  return this->probability != other.probability;
}
