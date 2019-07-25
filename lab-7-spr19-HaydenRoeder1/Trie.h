#ifndef TRIE_HEADER_HR
#define TRIE_HEADER_HR

#include <utility>
#include <vector>
#include <string>
class Trie{
private:
  std::vector<Trie*> children;
  Trie* parent;
  bool leaf;
  double value;
  char key;
  void remove(Trie*);
public:
  Trie();
  ~Trie();
  bool add(std::pair<std::string, double>);
  unsigned int numLeaves();
  unsigned int numNodes();
  void printTrie();
  double search(std::string);
};
#endif
