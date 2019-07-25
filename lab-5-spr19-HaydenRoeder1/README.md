#### CS 240 - Spring 2019
# Lab 5 - Finally, the STL
## Due Date: 11:59 p.m., March 13th, 2019

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Provided Files and Expected Output
* _Files_
    * lab5.cpp
* _Expected Command > Output_
    * Test Commands we will run
        * make
        * make run
        * make memcheck
        * make clean
    * Sample Output (with our test case):
```shell
TEST #1: Star and Planet Classes
========================PASS========================
TEST #2: Verify you are using nullptr
========================PASS========================
TEST #3: Check habitability algorithm
========================PASS========================
TEST #4: Correct Queue usage
========================PASS========================
TEST #5: Shuffle
matches: 0
========================PASS========================
All Tests Passed.
Don't forget to run with Valgrind and submit your commit hash!
```

### Grading Rubric
**_TOTAL: 20 points_**
* **Part A: 16 points**
    * Test #1  [4 pts]
    * Test #2  [4 pts]
    * Test #3  [4 pts]
    * Test #4  [4 pts]
* **Part B: 5 points**
    * Test #5  [4 pts]
        * Shuffles the queue to produce a random order
* **Part C:**
    * If memory error, memory leak, no 'checkmem' target [-5 points]
    * Submission includes .o files or binary [-1 point]
    * Does not follow [Style guidelines](https://drive.google.com/open?id=1a5I7XhhCDRHoS8LUfILu3y2la4wW8HHh4olO30YvMVk) [-3 points]
    * Your submission will not be accepted if:
        * Does not follow requested project structure and submission format
        * Does not compile

### Guidelines

This is an individual lab assignment. You must do the vast majority of the work on your own. It is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically *to* solve the problem you have been given, and you may not have anyone else help you write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

*By submitting this assignment, you agree that you have followed the above guidelines regarding collaboration and research.*

### Policies

#### Getting Help

Please following the debugging guidelines outline [here](https://docs.google.com/document/d/1DLPaOPd9CmbCWbnaRHkPzDQ2Qmo2gYAdqWU1xDM2joI/edit?usp=sharing). We will try to answer questions and provide help within 24 hours of your request. If you do not receive a response in 24 hours, please send the request again.

Although we will answer questions, provide clarification, and give general help where possible up until the deadline, we will not help you debug specific code within 24 hours of the deadline. We will not provide any help after the deadline.

#### Extensions

If an extension is requested more than 24 hours before the deadline, it may  be granted, depending on the reason for the requested extension. No extension will be granted, regardless of the reason, within 24 hours of the deadline.

***

The goal of Lab 5 is to get more familiar with the STL and building data structures.

#### (Parts A must be completed in lab)

## Part A: Probe

Having newly discovered the STL, you are going to use the built in Queue from the C++ STL rather than yours. You are going to create a Probe class that uses the STL Queue. You may use anything from the STL for this lab. Nothing is off limits. The following classes must be developed:

### Planet Class
The Planet class should have the following public interface:

* `Planet(int)`
    * Sets the planet's distance from the Star to a random value between 0-3000
    * You should still randomly select a planet type between rocky, habitable, and gaseous. Add a new private variable, `char type` that represents the planet type with a character: 'h'=habitable, 'r'=rocky, 'g'=gaseous.
* `unsigned long getID()`
    * returns the planet's unique id
* `unsigned int getDistance()`
    * returns the Planet's distance from the star
* `char getType()`
    * returns the Planet's type
### Star Class
The Planet class should have the following public interface:
* `unsigned long addPlanet()`
    * Creates and adds a Planet to the Star's orbit
* `bool removePlanet(unsigned long)`
    * Removes a Planet based on the PLanet's ID
    * Returns true if found, false otherwise
* `Planet * getPlanet(unsigned long)`
    * Returns a pointer to the Planet object.
    * :warning: nullptr if not found
* `vector<Planets>& getPlanets()`
    * return a vector containing the planets orbiting the star

### Probe Class
The Probe class is going to travel from Star to Star finding habitable planets. At each star, you are going to 'scan' each planet for habitability. You will then add all Habitable planets to a queue for later exploration. Your Probe should have the following public interface:
* `vector<Planet> getHabitable(Star s)`
    * Takes a Star as a parameter, and inspect all planets orbiting the star to see if they are habitable
        * A planet must meet both conditions for habitability to be considered habitable:
            1. It must be marked habitable type, 'h'
            2. It's distance from the star is within the Goldilocks Zone: 60-140
    * returns a vector<planet> containing __only__ habitable planets around that star
* `void addToQueue(Planet p)`
    * Adds the planet object to an internal queue
* `Planet getNext()`
    * dequeues the next planet on the Queue, and returns the object
    * :warning: calling getNext() on a Probe with no planets is undefined
* `queue<Planet>& getQueue()`
    * return the internal Queue
    * :bulb: This is just for testing purposes

__Show your TA your code.__

__--END OF IN LAB REQUIRED WORK--__

_You may continue to work on the remainder of the lab on your own time or in lab_

## Part B: Shuffle
Since finding life on another world is kind of a crap shoot, we are just going to randomize the order of the planets in our queue after we fill it up. Add a method to your Probe class:

* void shuffle();
    * The shuffle method should (*surprise*) shuffle your Planet queue.
    * Your shuffle __must__ be a randomized shuffle
    * You can use additional methods or anything else you find useful, as long as you are not violating encapsulation principles (i.e. changing the values of a Planet instead of moving the objects themselves around).

## Part C: Code Organization and Submission
* Required code organization:
    * lab5.cpp (driver code - You must include the provided file in your submission)
    * Planet.cpp/.h
    * Star.cpp/.h
    * Probe.h/.cpp
    * makefile
        * executable should be called: lab3
        * You must have the following targets in your makefile:
            * `all` - only compiles your source code using separate compilation for each .cpp file
            * `clean` - removes all object files and binary executables
            * `run` - compiles if necessary and runs your executable
            * `memcheck` - compiles your source if necessary, then runs your executable with valgrind

Below is just a reminder of the commands you should use to submit your code. If you cannot remember the exact process, please review lab 1.

_These commands all presume that your current working directory is within the directory tracked by `git`._

You will need to do the following when your submission is ready for grading.
```shell
git commit -am "final commit"
git push
```

To complete your submission, you must copy and paste the commit hash into MyCourses. Go to MyCourses, select CS240, and then assignments. Select Lab 5, and where it says text submission, paste your commit hash. You can get your latest commit hash with the following command:

```shell
git rev-parse HEAD
```

:warning: Remember, you __MUST__ make a submission on mycourses before the deadline to be considered on time.
