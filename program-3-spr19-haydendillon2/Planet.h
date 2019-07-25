#ifndef PLANET_HEADER_HR
#define PLANET_HEADER_HR
#include <string>
#include <list>
#include <vector>
class Planet{
private:
  std::string name;
  long x;
  long y;
  long z;




	std::list<Planet*> adjacents;

public:
  //A* variables
  double gVal; //Shortest path to this planet
  double fVal; //Shortest path to this planet + geometric distance to the destination
  int color;//0: unvisited 1: frontier 2: visited
  Planet* last;
  Planet(std::string planetName, long xCoor, long yCoor, long zCoor);
  std::string getName(){return name;}
  int getXCoor(){return x;}
  int getYCoor(){return y;}
  int getZCoor(){return z;}
  double distanceBetween(Planet* other);
  std::list<Planet*> getAdjacent();
	void addAdjacent(Planet* pToAdd);
  void reverseAdjacents();

  //Overriding comparisons for A*
  bool operator>(Planet other);
  bool operator<(Planet other);
  bool operator>=(Planet other);
  bool operator<=(Planet other);
  bool operator==(Planet other);

};
#endif
