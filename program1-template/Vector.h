#ifndef VECTOR_HEADER_HR
#define VECTOR_HEADER_HR
#include "Planet.h"

class Vector{
	private:
	unsigned int vSize;
	Planet ** planets;

	public:
	Vector();
	~Vector();
	void insert(int,Planet*);
	Planet* read(int);
	bool remove(int);
	unsigned int size();
};
#endif
