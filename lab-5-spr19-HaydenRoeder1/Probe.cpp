#include "Probe.h"
#include <queue>
#include <vector>
#include <cstdlib>
#include "Planet.h"
#include "Star.h"
using namespace std;
vector<Planet> Probe::getHabitable(Star s){
  vector<Planet> habitable;
  for(auto &it : s.getPlanets()){
    if(it.getType() == 'h' && it.getDistance() <= 140 && it.getDistance() >= 60){
      habitable.push_back(it);
    }
  }
  return habitable;
}
void Probe::addToQueue(Planet p){
  pQueue.push(p);
}
Planet Probe::getNext(){
  Planet ret = pQueue.front();
  pQueue.pop();
  return ret;
}
queue<Planet>& Probe::getQueue(){
  return pQueue;
}
void Probe::shuffle(){
  vector<Planet> queueVector;
  while(!pQueue.empty()){
    queueVector.push_back(pQueue.front());
    pQueue.pop();
  }
  for(unsigned int i = 0; i < queueVector.size(); i++){
    Planet temp = queueVector[i];
    int randInd = rand() % queueVector.size();
    queueVector[i] = queueVector[randInd];
    queueVector[randInd] = temp;
  }
  for(unsigned int i = 0; i < queueVector.size(); i++){
    pQueue.push(queueVector[i]);
  }
}
