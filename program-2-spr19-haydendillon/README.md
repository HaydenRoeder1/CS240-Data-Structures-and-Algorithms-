#### CS 240 - Spring 2018
# Program 2 - Finding Life
## Due Date: 11:59 p.m., April 12th, 2019

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

:no_entry: _You must have a teammate by next lab. Working with a partner is a requirement. You cannot complete this assignment on your own. If you complete the project on your own, without a partner, you will receive a 0._

***

_Replace anything surrounded by the `<< >>` symbols._

## SUMMARY:
 Group Members:Hayden Roeder, Dillon Gleason

 << Provide a short description of your program's functionality. No more than a couple sentences. >>

## TESTS:
 << Describe your tests >>
Test 1: The probability element of a planet will never be anything but 0-100.
Tests this by using the refine function to try to push the probability below 0 and above 100.
We expect that the probability will remain 0 at the lowest and 100 at the highest.

Test 2: A priority heap and vector are not ordered in the same way.
Tests this by using the same data set and putting the data into a heap and into a vector.
We expect the priority of the heap to not equal the first element of the vector.
## KNOWN BUGS AND INCOMPLETE PARTS:
 None

## REFERENCES:
 None

## MISCELLANEOUS COMMENTS:
 None

***

### Policies

#### Getting Help

Please follow the debugging guidelines outline [here](https://docs.google.com/document/d/1lbMdo-61lScAAho4UDGJ6HtkAlLXMjABbBqPL9r-w-o/edit?usp=sharing). We will try to answer questions and provide help within 24 hours of your request. If you do not receive a response in 24 hours, please send the request again.

Although we will answer questions, provide clarification, and give general help where possible up until the deadline, we will not help you debug specific code within 24 hours of the deadline. We will not provide any help after the deadline.

#### Extensions
If an extension is requested more than 24 hours before the deadline, it may  be granted, depending on the reason for the requested extension. No extension will be granted, regardless of the reason, within 24 hours of the deadline.

#### Guidelines

This is a pair programming assignment. You and a partner can divide up the work. Although both of you may not work on all parts of the program you should understand and be able to fully explain every portion of the code. Outside of your team, it is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically to solve the problem you have been given, and you may not have anyone else help you or your partner write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

If you or your partner are found to have plagiarized any part of the assignment, both will receive a 0 and be reported.

*By submitting this assignment, you agree that you have followed the above guidelines regarding collaboration and research.*

***

### Provided Files and Expected Output
* _Files_
    * Driver
       * program2.cpp
    * Test players files
       * exoplanets.dat
       * test.dat
       * test2.dat
* _Expected Command > Output_
    * Test Commands we will run
        * make
        * make run
        * make memcheck
        * make clean
    * Sample Output (with our test case):
```shell
    ./program2
    TEST #0: Missing file handled
    ========================PASS========================
    TEST #1: Create Planets from the file
    ========================PASS========================
    TEST #2: Heap is empty
    ========================PASS========================
    TEST #3: Elements stored in correct order in the heap
    ========================PASS========================
    TEST #4: Can add elements to the heap
    ========================PASS========================
    TEST #5: Planet class interface
    ========================PASS========================
    TEST #6: Scanner class interface
    ========================PASS========================
    TEST #7: Scan planets
    ========================PASS========================
    TEST #8: Scan planets where all have the same probability
    ========================PASS========================
    TEST #9: Scan and refine planets until at least one planet is 100%
    Life found on CoRoT-9b!
    ========================PASS========================
    TEST #10: Scan a large planet dataset until at least one planet is 100% for 10 simulations
     After refining probabilities 11 times life found on Kepler-1513b!
     After refining probabilities 37 times life found on tauBoob!
     After refining probabilities 40 times life found on Kepler-1515b!
     After refining probabilities 101 times life found on Pr201b!
     After refining probabilities 85 times life found on HD183263c!
     After refining probabilities 97 times life found on WASP-67b!
     After refining probabilities 97 times life found on HIP67851b!
     After refining probabilities 96 times life found on Kepler-972b!
     After refining probabilities 44 times life found on HD187123c!
     After refining probabilities 141 times life found on HD75898b!
    Number of duplicate results: 0
    ========================PASS========================
```

***

### Grading Rubric
__Total: 65 points__
* __Part A__
    * Passes test 0 [3 points]
        * Planet class interface is correct
    * Passes test 1 [2 points]
        * Handles empty file case without crashing or memory leak
    * Passes test 2 [5 points]
        * Creates a planet vector from a file
* __Part B__
    * Passes test 3 [2 points]
        * Creates an empty templated heap
    * Passes test 4 [8 points]
        * Values in heap are stored in correct order
    * Passes test 5 [7 points]
        * Elements can be added individually maintaining the heap
    * Passes test 6 [5 points]
        * Scanner class interface is correct
    * Passes test 7 [5 points]
        * Scan planets for life works as described
    * Passes test 8 [3 points]
        * Scan planets with equal probabilities
    * Passes test 9 [5 points]
        * Continuous scanning until a single planet reaches 100%
    * Passes test 10 [5 points]
        * Simulate multiple scans on a large dataset
        * Final results from each scan should be random
* __Part C__
    * Passes 2 additional tests written by the student [5 points each]
        * Each test is significant and has a description noting what is being tested
* __Part D__
    * If memory error, memory leak, no 'memcheck' target [-5 points]
    * Repository includes .o files or binary [-1 point]
    * Does not follow [Style guidelines](https://drive.google.com/open?id=1a5I7XhhCDRHoS8LUfILu3y2la4wW8HHh4olO30YvMVk)[-3 points]
    * Your submission will not be accepted if:
        * Does not follow requested project structure and submission format
        * Does not compile

***
## Assignment Description
***

Welcome to the the mission to find life outside our solar system. Unfortunately, we cannot search for _intelligent_ life since we don't know what that looks like (i.e. there's no point of reference here on earth). For this assignment, you are going to scan for life by putting all planets into a max-heap prioritized by their 'probability of life'. We will write code to scan each planet our probe found and refine our probability to either 100 or 0. Since the scanning process takes time, we will first simulate the scanning so we don't have to spend the next 4 billion years testing your program.

## Part A: Setting up the Search

Your probe from lab 5 has finally returned to earth with all the necessary information in a formatted text file. Unfortunately, in order for us to use the data, we will need to parse the file into objects.

### Planet Class
The Planet class should have the following public interface:

* `Planet(string id, double probability)`
    * sets the planet's Standard IAU name and probability of life
* `string getName()`
    * returns the planet's Standard IAU name
* `double getProbabilty()`
    * returns the Planet's chance of having life
* `double refine(double r)`
    * adds the value of `r` to the current probability of life
        * :no_entry_sign: probability should never be less than 0 or exceed 100.
    * returns the updated probability of life
* You must overload the following operators to compare planets by probability of life
    * `>, <, >=, <=, ==, !=`

### Parser

* `Parser(std::string filename)`
    * Opens the filename passed as a parameter and reads the data.
    * Parses the data into a vector of Planets
        * You can assume the data is well-formed.
        * It will follow this format: `<planet name> <probability of life>`
        * One planet per line, terminating with a blank line
* `vector<Planet> getPlanets()`
    * returns a copy of the internally stored vector

__Show your TA your working Part A code by the end of lab on April 4th.__

_You may continue to work on the remainder of the lab on your own time or in lab_

## Part B: Searching Your Planets

For Part A you read in a text document containing planet data. Once we can parse the file, our next job is to develop a scanner to scan each planet for life. The scanner is going to use a priority queue for internal storage, so it is always working with the highest probability planet. You must create a templated Heap class prioritized by the planet’s current possibility of life. Your heap must be an array based heap and may not use the STL for the heap itself; however, you can use a vector (or other STL container) for the internal array. Because heaps require comparison, we needed to overload several operators for the planet class.

### Heap<T>

The following is the required public interface:

* `Heap(){}`
    * default constructor must be implemented since we have implemented a value constructor
* `Heap(std::vector<T>)`
    * value constructor takes a vector as a parameter and heapifies the vector
* `void addElement(T element)`
    * adds an element to the heap and ensures the heap is maintained after insert
* `T getPriority()`
    * removes the priority value and ensures the heap is maintained after remove
    * calling on an empty heap is undefined behavior
* `bool empty()`
    * returns `true` if the heap is empty, otherwise `false`
* `unsigned long size()`
    * returns the number of elements in the heap
* `vector<T> getArray()`
    * returns a __copy__ of the internal array as an STL vector

:bulb: You will need additional private methods depending on your implementation.

### Scanner

Unfortunately, our scanner is still in the testing phase and cannot tell us if a planet currently has life. Instead, it can only refine the chances. Each scan improves the accuracy of our probability of life by up to +/-1%, rather than giving a definitive 'yes' or 'no'.

We are going to scan a planet, refine its probability of life, then return it to our heap. We should always be scanning the planet with the highest probability of life.

* `Scanner(vector<Planet>)`
    * Uses your heap template to heapify the vector
* `std::vector<Planet> scan(unsigned int num_planets)`
    * Removes and scans the top `num_planets` to refine their probability
        * The scanner only refines the Planet's current the probability by -1.0 or 1.0.
        * if `num_planets` is greater than the size of the heap, it should be set to the size of the heap
        * You should not alter a probability at either 0 or 100.
    * Returns a vector of the scanned planets
* `void addPlanet(Planet p)`
    * adds a planet into the internal heap
* `Heap<Planet> getHeap()`
    * returns a copy of the internal Heap
    * :warning: Does your Heap need a copy constructor?

## Part C: Testing your code

Once you are passing all of my tests, you must come up with two more tests for your code on your own. State explicitly in this README for each test:
* what you are testing
* what is the expected outcome.

Whether you use an assert() or some other mechanism, the tests must end your program abnormally if it fails.
* Example of ending your program abnormally:
    * failing an assert
    * calling exit(-1)

## Part D: Code Organization and Submission
* Required code organization:
    * program2.cpp
    * Parser.h/.cpp
    * Planet.h/.cpp
    * Scanner.h/.cpp
    * Heap.h
    * makefile
        * executable should be called: program2
        * You must have the following targets in your makefile:
            * `program2` - only compiles your source code using separate compilation for each .cpp file
            * `clean` - removes all object files and binary executables
            * `run` - compiles if necessary and runs your executable
            * `memcheck` - compiles your source if necessary, then runs your executable with valgrind
        * `program2.cpp` is set up to allow you to skip specified tests. To select tests to skip, you should set a preprocessor define directive in your makefile, using the -D flag. This sets the preprocessing variable in your makefile when you compile `program2.cpp` to an object file. Below is an example of skipping tests 4-11:
            * `g++ -g -std=c++14 -c -D TEST4 -D TEST5 -D TEST6 -D TEST7 -D TEST8 -D TEST9 -D TEST10 -D TEST11 program2.cpp -o program2.o`

Below is just a reminder of the commands you should use to submit your code. If you cannot remember the exact process, please review lab 1.

_These commands all presume that your current working directory is within the directory tracked by `git`._

You will need to do the following when your submission is ready for grading. :warning: Make sure you have added all files to your repo.

```shell
git commit -am "final commit"
git push
```

To complete your submission, you must copy and paste the commit hash into MyCourses. Go to MyCourses, select CS240, and then assignments. Select Program 2, and where it says text submission, paste your commit hash. You can get your latest commit hash with the following command:

```shell
git rev-parse HEAD
```

:warning: Remember, you __MUST__ make a submission on mycourses before the deadline to be considered on time.
