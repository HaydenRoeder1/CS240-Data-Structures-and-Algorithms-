#ifndef PLANET_HEADER_HR
#define PLANET_HEADER_HR
class Planet{
	private:
		static unsigned long unique_id;
		unsigned long id;
		int distance;
		char type;
	public:
		Planet(int);
		unsigned long getID(){return id;}
    		int getDistance(){return distance;}
    		char getType(){return type;}
		//you may add any additional methods you may need.
};
#endif
