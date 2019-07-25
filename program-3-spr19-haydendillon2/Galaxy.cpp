#include "Galaxy.h"
#include <fstream>
#include <iostream>
#include <cfloat>


Galaxy::Galaxy(std::string filename){
  std::string tempName;
	double tempX;
  double tempY;
  double tempZ;
	std::ifstream fileIn;
	fileIn.open(filename);

	while(fileIn>>tempName>>tempX>>tempY>>tempZ){
		Planet * tempPlanet = new Planet(tempName, tempX, tempY, tempZ);
    for(int i = 0; i < planets.size(); i++){//Check adjacent of all planets before as well as check all planets for adjecency to this one
				Planet * p = planets[i];
				p->addAdjacent(tempPlanet);
        tempPlanet->addAdjacent(p);
		}
		planets.push_back(tempPlanet);
	}
	fileIn.close();
  //Sorts each planets adjacents from farthest to closest which optimizes fValue sorting in A* since we insert the larger fValues first resulting in less sorting
  for(auto p : planets){
    p->reverseAdjacents();
  }

}
Galaxy::~Galaxy(){
  for(auto p : planets){
    delete p;
  }
}
unsigned int Galaxy::size(){
	return planets.size();
}

Planet* Galaxy::findByName(std::string planetName){
	for(int i = 0; i < planets.size(); i++){
		if(planets[i]->getName() == planetName){
			return planets[i];
		}
	}
  return NULL;
}
void siftdown(std::vector<Planet*>& toCheck){
  //Moves the top value of the array to the proper location
  Planet* temp = toCheck.back();
  //loop from the top until the most recently added planet is in the correct position
  for(int i = toCheck.size()-1; i > 0; i--){
    if(*(toCheck[i]) > *(toCheck[i-1])){
      toCheck[i] = toCheck[i-1];
      toCheck[i-1] = temp;
    }
    else{
      break;
    }
  }

}

/*/Dijkstra
std::vector<Planet*> Galaxy::shortestPath(Planet* start, Planet* dest){
  std::vector<Planet*> toCheck;
  for(int i = 0; i < planets.size(); i++){
    if(planets[i] != start){
      planets[i]->fVal = LDBL_MAX;
    }else{
      planets[i]->fVal = 0;
      toCheck.push_back(planets[i]);
    }
  }
  start->fVal = 0;
  while(toCheck.size() > 0){
    Planet* current = toCheck.back();
    toCheck.pop_back();
    current->setColor(2);
    if(current == dest){ //Found shortestPath, reconstruct it and return
      //Traverse the list formed by the "last" pointers
      std::vector<Planet*> path;
      while(current!= NULL){
        path.push_back(current);
        current = current->last;
      }
      //Reverse the list to get the desired path
      for(int i = 0, j = path.size() - 1; i < j; i++, j--){
        Planet* temp = path[i];
        path[i] = path[j];
        path[j] = temp;
      }
      if(path.size() == 1){//Either we did not find a path, or the path is length 1
        if(path[0] == start && path[0]==dest){//Path is length 1
          return path;
        }
        else{//Path doesn't exist
          path.clear();
          return path;
        }
      }
      return path;
    }
    //Check each neighbor to see if it is the destination before performing more expensive operations
    for(auto neighbor : current->getAdjacent()){
        if(neighbor == dest){
          //Traverse the list formed by the "last" pointers
          std::vector<Planet*> path;
          neighbor->last = current;
          current = neighbor;
          while(current!= NULL){
            path.push_back(current);
            current = current->last;
          }
          //Reverse the list to get the desired path
          for(int i = 0, j = path.size() - 1; i < j; i++, j--){
            Planet* temp = path[i];
            path[i] = path[j];
            path[j] = temp;
          }
          if(path.size() == 1){//Either we did not find a path, or the path is length 1
            if(path[0] == start && path[0]==dest){//Path is length 1
              return path;
            }
            else{//Path doesn't exist
              path.clear();
              return path;
            }
          }
          return path;
        }
    }
    for(auto neighbor : current->getAdjacent()){
      if(neighbor->getColor() == 2){continue;}
      double tempDist = current->fVal + current->distanceBetween(neighbor);
      if(tempDist < neighbor->fVal){
        neighbor->fVal = tempDist;
        neighbor->last = current;
        if(neighbor->getColor()==0){//Have not visited yet, add it to the list to check
          toCheck.push_back(neighbor);
          neighbor->setColor(1);
          //Sift down to proper position
          for(int i = toCheck.size()-1; i > 0; i--){
            if(*(toCheck[i]) > *(toCheck[i-1])){
              Planet* temp = toCheck[i];
              toCheck[i] = toCheck[i-1];
              toCheck[i-1] = temp;
            }
            else{
              break;
            }
          }
        }
      }
    }

  }
  std::cout << "Path not found" << std::endl;
  std::vector<Planet*> path(0);
  return path;
}
/**/

//A*
std::vector<Planet*> Galaxy::shortestPath(Planet* start, Planet* dest){

  //Don't waste time if start and dest are the same
  if(start==dest){
    std::vector<Planet*> path;
    path.push_back(dest);
    return path;
  }

  //Create a vector that can hold the size of the planets array so inserting elements is O(1)
  std::vector<Planet*> toCheck;
  toCheck.reserve(planets.size());

  //Check planets starting with the start vertex
  toCheck.push_back(start);

  while(toCheck.size() > 0){
    //Get the next lowest fValue (shortest path to this planet + geometric distance to dest)
    Planet* current = toCheck.back();
    toCheck.pop_back();
		std::list<Planet*> neighbors = current->getAdjacent();
    current->color = 2; //Mark that we already checked it

    //Check to see if any of the neighbors are the destination before analyzing further
    //Basically constant time (at most 4 if statements) unless we find the desired path and end the function early
    for(auto neighbor : neighbors){

      //This neighbor is the destination, reconstruct path
      if(neighbor == dest){

        //Traverse linked list formed by planet "last" pointers to get the reverse path
        neighbor->last = current;
        current = neighbor;
        std::vector<Planet*> path;
        while(current!= NULL){
          path.push_back(current);
          current = current->last;
        }

        //Reverse vector to get the correct path
        for(int i = 0, j = path.size() - 1; i < j; i++, j--){
          Planet* temp = path[i];
          path[i] = path[j];
          path[j] = temp;
        }

        return path;
      }
    }
    for(auto neighbor : neighbors){

      //Already checked this planet, continue
      if(neighbor->color == 2){continue;}

      //Add this planet to the set of planets to check if it isn't already
      double tempG = current->gVal + current->distanceBetween(neighbor);
      if(neighbor->color == 0){
        neighbor->color = 1;
        toCheck.push_back(neighbor);
      }
      //If there is a shorter path to this planet, don't overwrite it
      else if(tempG > neighbor->gVal){
        continue;
      }

      //Set the value of this planet to its shortest path
      neighbor->last = current;
      neighbor->gVal = tempG;
      neighbor->fVal = neighbor->gVal + neighbor->distanceBetween(dest);

      //Sift down the value we added to keep the array sorted
      //Should be more efficient than a heap since keeping the array sorted is only 1-2 iterations most of the time
      siftdown(toCheck);

    }


  }
  std::vector<Planet*> path(0);
  return path;
}

/**/
double Galaxy::pathDistance(Planet* start, Planet* dest){
	std::vector<Planet*> pathPlanets = shortestPath(start, dest);
	double distance = 0;
  if(pathPlanets.size() == 0){

    return LDBL_MAX;
  }
  if(pathPlanets.size() == 1){
    return 0;
  }
	for(int i = 0; i < (pathPlanets.size() - 1); i ++){
		distance += pathPlanets[i]->distanceBetween(pathPlanets[i+1]);
	}

	return distance;
}
