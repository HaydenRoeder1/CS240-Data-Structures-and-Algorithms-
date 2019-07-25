#include "Hash.h"
#include <iostream>
using namespace std;
Hash::Hash(unsigned int size){
  max_size = size;
  nodes = new Node[size];
}
Hash::~Hash(){
  delete[] nodes;
}
unsigned int Hash::hasher(string key){
  int sum = 0;
  for(int i = 0; i < key.length(); i++){
    sum += key[i];

  }
  int index = sum % size();
  int counter = 0;
  for(int i = 0; i < size(); i++){
    if(nodes[i].key == key){
      return (unsigned int)(size()+1);
    }
  }
  while(nodes[index].key != "" && counter < size()){
    index++;
    if(index == size()){
      index = 0;
    }
    counter++;
  }
  if(counter == size()){
    return (unsigned int)(size()+1);
  }
  return (unsigned int)index;
}
bool Hash::insert(string key, double value){
  unsigned int index = hasher(key);
  if(index > size()){
    return false;
  }
  nodes[index].key = key;
  nodes[index].value = value;
  return true;

}
bool Hash::empty(){
  for(int i = 0; i < size(); i ++){
    if(nodes[i].key != ""){
      return false;
    }
  }
  return true;
}
int Hash::size(){
  return max_size;
}
Node * Hash::getTable(){
  return nodes;
}
bool Hash::remove(string key){
  for(int i = 0; i < size(); i++){
    if(nodes[i].key == key){
      nodes[i].key = "";
      nodes[i].value = -1.0;
      return true;
    }
  }
  return false;
}
double Hash::find(string key){
  for(int i = 0; i < size(); i++){
    if(nodes[i].key == key){
      return nodes[i].value;
    }
  }
  return -1.0;
}
