#ifndef PLANET_HEADER_HR
#define PLANET_HEADER_HR
#include <string>
class Planet{
private:
  std::string id;
  double probability;
public:
  Planet(std::string id, double probability);
  std::string getName(){return id;}
  double getProbability(){return probability;}
  double refine(double r);
  bool operator>(Planet other);
  bool operator<(Planet other);
  bool operator>=(Planet other);
  bool operator<=(Planet other);
  bool operator==(Planet other);
  bool operator!=(Planet other);


};


#endif
