#include "Trie.h"
#include <iostream>
using namespace std;
Trie::Trie(){
  parent = nullptr;
  leaf = false;
  value = -1;
  key = '?';
}
Trie::~Trie(){
  for(int i = 0; i < children.size(); i++){
    delete(children[i]);
  }
}

bool Trie::add(pair<string, double> element){
  Trie* curTrie = this;
  string str = get<string>(element);
  for(int i = 0; i <= str.length(); i++){
    bool foundNextChar = false;
    for(int j = 0; j < curTrie->children.size(); j++){

      if(curTrie->children[j]->key == str[i]){
        curTrie = curTrie->children[j];
        foundNextChar = true;
        break;
      }
    }
    if(foundNextChar == false){
      Trie* newTrie = new Trie();
      newTrie->key = str[i];
      newTrie->parent = curTrie;
      curTrie->children.push_back(newTrie);
      curTrie = newTrie;
    }

  }
  if(curTrie->value != -1){return false;}
  curTrie->value = get<double>(element);
  curTrie->leaf = true;
  return true;

}
unsigned int Trie::numLeaves(){
  int childLeaves = 0;
  if(leaf){
    return 1;
  }
  for(int i = 0; i < children.size(); i++){
      childLeaves += children[i]->numLeaves();
  }
  return childLeaves;
}
unsigned int Trie::numNodes(){

  if(leaf){
    return 1;
  }
  int childNodes = 0;
  for(int i = 0; i < children.size(); i++){
      childNodes += children[i]->numNodes();
  }
  if(parent != nullptr){ //Ignores the root
    childNodes++;
  }

  return childNodes;
}
void Trie::printTrie(){
  cout << endl;
  cout << "Parent: (key) " << key << " : (value) " << value << endl;
  for(int i = 0; i < children.size(); i++){
    cout << "-----> Child: (key) " << children[i]->key << " : (value) " << children[i]->value << endl;
  }
  for(int i = 0; i < children.size(); i++){
    children[i]->printTrie();
  }
}
double Trie::search(string str){
  Trie* curTrie = this;
  for(int i = 0; i <= str.length(); i++){
    bool foundNextChar = false;
    for(int j = 0; j < curTrie->children.size(); j++){
      if(curTrie->children[j]->key == str[i]){
        curTrie = curTrie->children[j];
        foundNextChar = true;
        break;
      }
    }
    if(foundNextChar == false){
      return -1.0;
    }
  }

  return curTrie->value;
}
