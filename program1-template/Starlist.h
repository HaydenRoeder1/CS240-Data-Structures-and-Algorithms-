#ifndef STARLIST_HEADER_HR
#define STARLIST_HEADER_HR
#include "Planet.h"
#include "List.h"
class Starlist{
private:
	List * planets;
public:
	Starlist();
	~Starlist();
	long addPlanet(); 
	bool removePlanet(int); 
	Planet * getPlanet(int); 
	void orbit();
	void printStarInfo();
	unsigned int getCurrentNumPlanets();	
};
#endif
