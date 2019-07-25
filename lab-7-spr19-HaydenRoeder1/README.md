#### CS 240 - Spring 2019
# Lab 7 - Trie
## Due Date: 11:59 p.m., April 17th, 2019

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

***

### Policies

#### Getting Help

Please follow the debugging guidelines outline [here](https://docs.google.com/document/d/1lbMdo-61lScAAho4UDGJ6HtkAlLXMjABbBqPL9r-w-o/edit?usp=sharing). We will try to answer questions and provide help within 24 hours of your request. If you do not receive a response in 24 hours, please send the request again.

Although we will answer questions, provide clarification, and give general help where possible up until the deadline, we will not help you debug specific code within 24 hours of the deadline. We will not provide any help after the deadline.

#### Extensions
If an extension is requested more than 24 hours before the deadline, it may  be granted, depending on the reason for the requested extension. No extension will be granted, regardless of the reason, within 24 hours of the deadline.

#### Guidelines

This is an individual lab assignment. You must do the vast majority of the work on your own. It is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically *to* solve the problem you have been given, and you may not have anyone else help you write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

*By submitting this assignment, you agree that you have followed the above guidelines regarding collaboration and research.*

***

### Provided Files and Expected Output
* _Files_
    * Driver
       * lab7.cpp
    * Test files
       * exoplanets.dat
       * testa.dat
       * testb.dat
       * testc.dat
* _Expected Command > Output_
    * Test Commands we will run
        * make
        * make run
        * make memcheck
        * make clean
    * Sample Output:
```shell
    ./lab7
    TEST #0: Trie is empty
    ========================PASS========================
    TEST #1: add elements
    ===========================
    Parent: (key) ? : (value) -1
        -----> Child: (key) a : (value) -1
        -----> Child: (key) d : (value) -1
        -----> Child: (key) q : (value) -1
        -----> Child: (key) l : (value) -1
    ===========================
    ...
    ===========================
        Parent: (key)  : (value) 4
     Trie complete
    ========================PASS========================
    TEST #2: add overlapping elements
    ===========================
    Parent: (key) ? : (value) -1
        -----> Child: (key) a : (value) -1
        -----> Child: (key) b : (value) -1
        -----> Child: (key) c : (value) -1
    ===========================
    ...
    ===========================
    Parent: (key)  : (value) 8
    Trie complete
    ========================PASS========================
    TEST #3: search Trie
    ========================PASS========================
    TEST #4: add and search with large dataset
    ========================PASS========================
    TEST #5: Large data set
    ========================PASS========================
    Tests complete! Make sure you submit your commit hash on MyCourses and run with valgrind.
```
***

### Grading Rubric
__Total: 20 points__

:warning: __It is possible to pass the tests with something other than a trie. Your submission will not be accepted if you do not implement a trie.__

* __Part A__
    * Passes test 0 [1 point]
        * Empty trie
    * Passes test 1 [2 points]
        * Reads and store non-overlapping keys
    * Passes test 2 [5 points]
        * Reads and store overlapping keys
* __Part B__
    * Passes test 3 [5 points]
        * Trie is searchable
    * Passes test 4 [4 points]
        * Values in heap are stored in correct order
    * Passes test 5 [3 points]
        * Elements can be added individually maintaining the heap
* __Part C__
    * If memory error, memory leak, no 'memcheck' target [-5 points]
    * Repository includes .o files or binary [-1 point]
    * Does not follow [Style guidelines](https://drive.google.com/open?id=1a5I7XhhCDRHoS8LUfILu3y2la4wW8HHh4olO30YvMVk)[-3 points]
    * Your submission will not be accepted if:
        * Does not follow requested project structure and submission format
        * Does not compile

***
## Assignment Description
***

For lab7, you are going to build a Trie. As discussed in class, there are several ways to design it. You are free to choose whatever design you like, as long as you pass the tests and implement a trie. You may also implement the Node class class however you choose (think of the various ways we have implemented a node class for other data structures).

## Part A: Building a Trie

We are going to store all our planet data in a Trie, using the planet name as the key, allowing us to quickly retrieve the probability of life. The interface is as follows:

### Trie
The Trie class should have the following public interface:

* `Trie()`
    * creates a empty trie
* `bool add(pair<string, double>)`
    * takes an [STL pair](http://www.cplusplus.com/reference/utility/pair/pair/) object as a parameter, storing the string as the key and double as the value
    * returns false if the object is already trie
* `unsigned int numLeaves()`
    * returns the number of leaves in the trie
* `unsigned int numNodes()`
    * returns the number of nodes (not including the root) in the trie
* `void printTrie()`
    * prints each node in the trie and it's children
        * Please review the output above for expected format

__Show your TA your code.__

__--END OF IN LAB REQUIRED WORK--__

_You may continue to work on the remainder of the lab on your own time or in lab_

## Part B: Searching Your Trie

Since the whole point of a trie is retrieval, your trie must be searchable.

### Trie
Add the following to your trie's public interface:

* `double search(string)`
    * returns the value based on the string keys
    * returns value if found, -1.0 if not found.


## Part C: Code Organization and Submission
* Required code organization:
    * lab7.cpp
    * Trie.h/.cpp
    * makefile
        * executable should be called: lab7
        * You must have the following targets in your makefile:
            * `lab7` - only compiles your source code using separate compilation for each .cpp file
            * `clean` - removes all object files and binary executables
            * `run` - compiles if necessary and runs your executable
            * `memcheck` - compiles your source if necessary, then runs your executable with valgrind
        * `lab7.cpp` is set up to allow you to skip specified tests. To select tests to skip, you should set a preprocessor define directive in your makefile, using the -D flag. This sets the preprocessing variable in your makefile when you compile `program2.cpp` to an object file. Below is an example of skipping tests 3-5:
            * `g++ -g -std=c++14 -c lab7.cpp -o lab7.o -DTEST3 -DTEST4 -DTEST5`

Below is just a reminder of the commands you should use to submit your code. If you cannot remember the exact process, please review lab 1.

_These commands all presume that your current working directory is within the directory tracked by `git`._

You will need to do the following when your submission is ready for grading. :warning: Make sure you have added all files to your repo.

```shell
git commit -am "final commit"
git push
```

To complete your submission, you must copy and paste the commit hash into MyCourses. Go to MyCourses, select CS240, and then assignments. Select Lab 7, and where it says text submission, paste your commit hash. You can get your latest commit hash with the following command:

```shell
git rev-parse HEAD
```

:warning: Remember, you __MUST__ make a submission on mycourses before the deadline to be considered on time.
