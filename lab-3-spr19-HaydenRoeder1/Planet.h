#ifndef HEADER_PLANET_HR
#define HEADER_PLANET_HR
class Planet{
	private:
		int id;
		int pos;
		int distance;
		char type;
	public:	
		Planet();
		Planet(int);
     		int orbit();
		int getID(){return id;}
       		int getDistance(){return distance;}
        	int getPos(){return pos;}
		int getType(){return type;}
		//you may add any additional methods you may need.
};
#endif
