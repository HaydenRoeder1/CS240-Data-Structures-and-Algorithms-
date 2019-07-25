#include <iostream>
#include <fstream>
#include <cassert>
#include <ctime>
#include <vector>
#include <utility>
#include "Trie.h"
#include "Trie.h"

using namespace std;

vector< pair<string, double> > parse(string filename){
    fstream file(filename, fstream::in);
    vector< pair<string, double> > planets;
    if(file.is_open()){
        while(!file.eof() && !file.fail()){
            string name;
            double probs;
            file >> name;
            file >> probs;
            file.ignore(1000, '\n');
            if(!name.empty()) planets.push_back(pair<string, double>(name, probs));
        }
        file.close();
    }
    return planets;
}

int main(){
	srand(unsigned(time(0)));

#ifndef TEST0
    {
	    cerr << "\n\tTEST #0: Trie is empty" << endl;
	    Trie t;
        //size should return the number of leaves
        assert(t.numLeaves() == 0);

        assert(t.numNodes() == 0);
        cerr << "\n\t========================PASS========================\n" << endl;
    }
#endif
#ifndef TEST1
    {
    	cerr << "\n\tTEST #1: add elements" << endl;
        vector< pair<string, double> > planets = parse("testa.dat");
        Trie t;
        unsigned int num_leaves = 0;
        unsigned int num_nodes[] = {4, 8, 12, 18};
        int i = 0;
        for(auto p: planets){
            t.add(p);
            assert(t.numLeaves() == ++num_leaves);
            assert(t.numNodes() == num_nodes[i++]);
        }
        t.printTrie();
    	cerr << "\n\t========================PASS========================\n" << endl;

    }
#endif
#ifndef TEST2
    {
    	cerr << "\n\tTEST #2: add overlapping elements" << endl;
        vector< pair<string, double> > planets = parse("testb.dat");
        Trie t;
        unsigned int num_leaves = 0;
        unsigned int num_nodes[] = {4, 6, 9, 12, 15, 17, 20, 22};
        int i = 0;
        for(auto p: planets){
            t.add(p);
            assert(t.numLeaves() == ++num_leaves);
            assert(t.numNodes() == num_nodes[i++]);
        }
        t.printTrie();
    	cerr << "\n\t========================PASS========================\n" << endl;
    }
#endif
#ifndef TEST3
    {
    	cerr << "\n\tTEST #3: search Trie" << endl;
        vector< pair<string, double> > planets = parse("testb.dat");
        Trie t;
        for(auto p: planets){
            t.add(p);
        }
        assert(t.search("abc") == 1.0);
        assert(t.search("abd") == 2.0);
        assert(t.search("acd") == 3.0);
        assert(t.search("aaa") == 4.0);
        assert(t.search("bc") == 5.0);
        assert(t.search("bd") == 6.0);
        assert(t.search("cd") == 7.0);
        assert(t.search("ca") == 8.0);
        assert(t.search("none") == -1.0);

	    cerr << "\n\t========================PASS========================\n" << endl;
    }
#endif
#ifndef TEST4
    {
    	cerr << "\n\tTEST #4: add and search with large dataset" << endl;
        vector< pair<string, double> > planets = parse("testc.dat");
        Trie t;
        unsigned int num_leaves = 0;
        for(auto p: planets){
            t.add(p);
            assert(t.numLeaves() == ++num_leaves);
        }
        assert(t.search("HAT-P-27b") == 25.97);
        assert(t.search("Kepler-1098b") == 43.4);
        assert(t.search("upsilonAndd") == 55.53);
        assert(t.search("K2-3b") == 22.74);
        assert(t.search("BD+144559b") == 73.47);
        assert(t.search("7CMab") == 48.04);
        assert(t.search("XO-3b") == 59.59);
        assert(t.search("CoRoT-9b") == 88.02);
        assert(t.search("Kepler-1049b") == 19.32);
        assert(t.search("HD116029b") == 35.0);
        assert(t.search("WASP-21b") == 72.71);
        assert(t.search("GJ649b") == 12.37);
        assert(t.search("none") == -1.0);

    	cerr << "\n\t========================PASS========================\n" << endl;
    }
#endif
#ifndef TEST5
    {
    	cerr << "\n\tTEST #5: Large data set" << endl;
        vector< pair<string, double> > planets = parse("exoplanets.dat");
        Trie t;
        for(auto p: planets) t.add(p);

        assert(t.search("HD102329b") == 23.55);
        assert(t.search("Kepler-1322b") == 14.62);
        assert(t.search("WASP-140b") == 38.32);
        assert(t.search("Kepler-???") == -1.0);
    	cerr << "\n\t========================PASS========================\n" << endl;
    }
#endif
    cerr << "\n\tTests complete! Don't forget to submit your commit hash on MyCourses and run with valgrind.\n" << endl;
}
