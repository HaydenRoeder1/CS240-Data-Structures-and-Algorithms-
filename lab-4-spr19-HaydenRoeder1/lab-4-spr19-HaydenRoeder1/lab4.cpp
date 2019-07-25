#include "Queue.h"
#include "Vector.h"
#include "Queue.h"
#include "Vector.h"
#include <iostream>
#include <cassert>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

#define VECTOR_SIZE 20
#define QUEUE_SIZE 5

int main(){
	srand(time(NULL));
	cerr << "\n\tTEST #1: Test create a integer Vector" << endl;
	Vector<int> list(VECTOR_SIZE);
	list[0] = 5;
	assert(list[0] == 5);
    assert(list.size() == VECTOR_SIZE);
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #2: Test create a double Vector" << endl;
	Vector<double> double_list(VECTOR_SIZE);
	double_list[0] = 1.15;
	double_list[1] = 2.15;
	double_list[2] = 3.15;
	assert(double_list[0] == 1.15);
	assert(double_list[1] == 2.15);
	assert(double_list[2] == 3.15);
    assert(double_list.size() == VECTOR_SIZE);

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #3: Test copy constructor and delete all elements from Vector" << endl;
    Vector<double> double_list2(double_list);
	double_list.clear();
	assert(double_list.size() == 0);
    assert(double_list2.size() == VECTOR_SIZE);

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #4: Test add 1 element to a Queue" << endl;

	Queue<int> queue(QUEUE_SIZE);
	assert(queue.enqueue(5));
	assert(5 == queue.dequeue());

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #5: Test fill a char Queue" << endl;

	Queue<char> char_queue(QUEUE_SIZE);
	assert(char_queue.enqueue('a'));
	assert(char_queue.enqueue('b'));
	assert(char_queue.enqueue('c'));
    assert(char_queue.enqueue('d'));
    assert(char_queue.enqueue('e'));
    assert(!char_queue.enqueue('f'));
	char let1 = char_queue.dequeue();
	assert(let1 == 'a');
	assert(char_queue.empty() == false);
    char let2 = char_queue.dequeue();
	assert(let2 == 'b');
	assert(char_queue.empty() == false);
    char let3 = char_queue.dequeue();
	assert(let3 == 'c');
	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #6: Test Queue Order" << endl;
	char_queue.enqueue('z');
	char_queue.enqueue('y');
	char letd = char_queue.dequeue();
	assert(letd == 'd');
	char_queue.enqueue('x');
	char lete = char_queue.dequeue();
	assert(lete == 'e');
	char_queue.enqueue('w');
	char letz = char_queue.dequeue();
	assert(letz == 'z');
	char lety = char_queue.dequeue();
	assert(lety == 'y');
    cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #7: Test Queue Interface" << endl;

	assert(!char_queue.empty());
	char letx = char_queue.peek();
	assert(letx == 'x');
	char letx2 = char_queue.dequeue();
	assert(letx2 == 'x');
	char_queue.clear();
	assert(char_queue.empty());
	cerr << "\n\t========================PASS========================\n" << endl;
    
    cerr << "\n\tDon't forget to run with Valgrind and commit to Github!\n" << endl;
    return 0;
}
