#ifndef PARSER_HEADER_HR
#define PARSER_HEADER_HR
#include <vector>
#include <string>
#include "Planet.h"
class Parser{
private:
  std::vector<Planet> planets;
public:
  Parser(std::string filename);
  std::vector<Planet> getPlanets(){return planets;}

};

#endif
