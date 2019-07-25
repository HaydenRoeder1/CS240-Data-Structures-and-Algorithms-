#include "Star.h"
#include "Star.h"
#include "Planet.h"
#include "Planet.h"
#include "Probe.h"
#include "Probe.h"
#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <vector>

#define EXTRA_CREDIT 1

using namespace std;

#define NUM_STARS 500

int main(){
	srand(time(NULL));
	cerr << "\n\tTEST #1: Star and Planet Classes" << endl;

    Star s;
    vector<unsigned long> ids;
    for(int i = 0; i < 10; i++){
        unsigned long n = s.addPlanet();
        ids.push_back(n);
    }
    for(auto i: ids){
        Planet * p = s.getPlanet(i);
        assert(p->getDistance() > 0 && p->getDistance() < 3001);
        assert(p->getType() == 'r' || p->getType() == 'g' || p->getType() == 'h');
    }
    for(auto i: ids){
        assert(s.removePlanet(i));
    }



	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #2: Verify you are using nullptr " << endl;

    assert(s.getPlanet(-1) == nullptr);

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #3: Check habitability algorithm" << endl;

    vector<Star> galaxy;
    for(int i = 0; i < NUM_STARS; i++){
        Star star;
        for(int j = 0; j < rand() % 30; j++){
            star.addPlanet();
        }
        galaxy.push_back(star);
    }
    Probe probe;
    vector <Planet> habitable;
    for(auto star : galaxy){
        vector<Planet> h = probe.getHabitable(star);
        for(auto planet: h){
            cerr << planet.getID() << endl;
            habitable.push_back(planet);
        }
    }
    for(auto h: habitable){
        assert(h.getType() == 'h' && h.getDistance() <= 140 && h.getDistance() >= 60);
    }

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #4: Correct Queue usage" << endl;

    vector<unsigned long> pids;
    unsigned int num_habitable = 0;
    for(auto h: habitable){
        pids.push_back(h.getID());
        probe.addToQueue(h);
        num_habitable++;
    }

    for(unsigned int i = 0; i < num_habitable; i++){
        Planet p = probe.getNext();
        unsigned int q = pids.front();
        pids.erase(pids.begin());
        cerr << p.getID() << " : " << q << endl;
        assert(q == p.getID());
    }

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #5: Shuffle" << endl;
	Probe probeA, probeB, probeC;
    num_habitable = 0;
    for(auto h: habitable){
        probeA.addToQueue(h);
        probeB.addToQueue(h);
        probeC.addToQueue(h);
        num_habitable++;
    }
    probeA.shuffle();
    probeB.shuffle();
    probeC.shuffle();
    unsigned int num_matches = 0;
    while(!(probeA.getQueue().empty()) ||
            !(probeB.getQueue().empty()) ||
            !(probeC.getQueue().empty())
            ){
        Planet a = probeA.getNext();
        Planet b = probeB.getNext();
        Planet c = probeC.getNext();
        if(a.getID() == b.getID() && b.getID() == c.getID()){
            num_matches++;
        }
    }
    cerr << "matches: " << num_matches << endl;
	assert(num_matches < 50);

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tAll Tests Passed.\nDon't forget to run with Valgrind and submit your commit hash!\n" << endl;
	return 0;
}
