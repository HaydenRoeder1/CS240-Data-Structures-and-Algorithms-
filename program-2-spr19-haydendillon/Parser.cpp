#include "Parser.h"
#include <string>
#include <iostream>
#include <fstream>
Parser::Parser(std::string filename){
	
	std::string line;
	double tempProb;
	std::ifstream fileOut;
	fileOut.open(filename);
	
	while(fileOut>>line>>tempProb){
		Planet tempPlan(line, tempProb);
		this->planets.push_back(tempPlan);
	}
	fileOut.close();
}
