#ifndef HASH_HEADER_HR
#define HASH_HEADER_HR
#include <string>

class Node{
public:
  std::string key;
  double value;
  Node(){
    key = "";
    value = -1.0;
  }
};
class Hash{
private:
  int max_size;
  Node * nodes;
public:
  Hash(unsigned int size);
  ~Hash();
  unsigned int hasher(std::string key);
  bool insert(std::string key, double value);
  bool empty();
  int size();
  Node * getTable();
  bool remove(std::string key);
  double find(std::string key);
};

#endif
