#### CS 240 - Spring 2019
# Lab 8 - Hash Tables
## Due Date: 11:59 p.m., April 24th, 2018

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
    * lab8.cpp
    * testa.dat
    * testb.dat
    * testc.dat
* _Expected Command > Output_
    * Test Commands we will run
        * make
        * make run
        * make memcheck
        * make clean
    * Sample Output (with our test case):
```shell
    ./lab8
    TEST #0: Create an empty hash of the correct size
    ========================PASS========================
    TEST #1: Test hashing function
    ========================PASS========================
    TEST #2: Insert non-colliding keys into the Hash
    ========================PASS========================
    TEST #3: Insert colliding keys into the Hash
    ========================PASS========================
    TEST #4: Verify valid keys are retrievable
    ========================PASS========================
    TEST #5: Remove entries from the hash
    ========================PASS========================
    All Tests Passed.
    Dont forget to run with Valgrind and commit to Github!
```

### Grading Rubric
**_TOTAL: 20 points_**
* **Part A: 10 points**
   * Hash and Node classes don’t use any STL containers (2 points)
   * Test 0 - create empty hash (1 point)
   * Test 1 - hashing function works as described (2 points)
   * Test 2 - insert non-colliding keys into the table (3 points)
      * must use linear open addressing to address collisions
   * Test 3 - insert colliding keys into the table  (2 points)
* **Part B: 10 points**
    * Test 4 - verify keys are retrievable (5 points)
    * Test 5 - entries are removable (5 points)
* __Part C__
    * If memory error, memory leak, no 'memcheck' target [-5 points]
    * Repository includes .o files or binary [-1 point]
    * Does not follow [Style guidelines](https://drive.google.com/open?id=1a5I7XhhCDRHoS8LUfILu3y2la4wW8HHh4olO30YvMVk)[-3 points]
    * Your submission will not be accepted if:
        * Does not follow requested project structure and submission format
        * Does not compile

***

The goal of Lab 8 is to implement a hash table for retrieving a planet's probability of life. You must use linear open addressing for collision resolution.

#### (Parts A must be completed in lab)

## Part A: Hash Table

For Part A you are going to implement a Hash and Node class that will store a key string and value double. You must use use linear open addressing for collision resolution. Open addressing sacrifices insertion and lookup performance to save memory by placing the data in the next open space when there is a collision. Your hash should correctly store and retrieve probabilities along with the key. Some rules your hash must follow are:

1. You must use linear open addressing for collision resolution
2. You must use a standard array (boring, I know).
3. Your hash table must not change size. Empty ‘slots’ are represented with empty strings.

### Node Class
:warning: Node class must **NOT** be an internal class and everything must be public. This is only for testing purposes. You must have the following interface:
* string key;
* double value;
* Node()
    * sets `key` to an empty string and `value` to -1.0

### Hash Class

* Hash(unsigned int size)
    * Should initialize an array to the size passed in. You must use an array of `Node *` to store the key/value pairs.
* unsigned int hasher(string key)
    * hash function that determines an index based on the key parameter
    * Your hash function should be implemented as follows: <sum of string ascii values> % size
* bool insert(string key, double value)
    * returns true is the key was correctly inserted into the hash
    * false if the hash is full
    * Adding duplicate keys is undefined behavior.
* bool empty()
    * returns true of the hash is empty
* int size()
    * returns the max size of the hash table (not the current number of items)
* Node * getTable()
    * return a pointer to your Node array

__Show your TA your code.__

__--END OF IN LAB REQUIRED WORK--__

_You may continue to work on the remainder of the lab on your own time or in lab_

## Part B: Retrieval and Deletion

Add the following methods to your Hash Class:

* bool remove(string key)
    * removes the entry from the hash be setting the key to an empty string and value to -1.0
    * returns false if the key was not found
* double find(string key)
    * returns the correct value based on the key parameter
    * If the key is not found, returns -1.0


## Part C: Code Organization and Submission
* Required code organization:
    * lab8.cpp  (driver code - You must include this file in your submission)
    * testa.dat, testb.dat, testc.dat - (sample test files)
    * Hash.h/.cpp
    * makefile
        * executable should be called: lab8
        * You must have the following targets in your makefile:
            * `lab8` - only compiles your source code using separate compilation for each .cpp file
            * `clean` - removes all object files and binary executables
            * `run` - compiles if necessary and runs your executable
            * `memcheck` - compiles your source if necessary, then runs your executable with valgrind
        * `lab8.cpp` is set up to allow you to skip specified tests. To select tests to skip, you should set a preprocessor define directive in your makefile, using the -D flag. This sets the preprocessing variable in your makefile when you compile `lab8.cpp` to an object file. Below is an example of skipping tests 3-5:
            * `g++ -g -std=c++14 -c lab8.cpp -o lab8.o -DTEST3 -DTEST4 -DTEST5`

Below is just a reminder of the commands you should use to submit your code. If you cannot remember the exact process, please review lab 1.

_These commands all presume that your current working directory is within the directory tracked by `git`._

You will need to do the following when your submission is ready for grading. :warning: Make sure you have added all files to your repo.

```shell
git commit -am "final commit"
git push
```

To complete your submission, you must copy and paste the commit hash into MyCourses. Go to MyCourses, select CS240, and then assignments. Select Lab 8, and where it says text submission, paste your commit hash. You can get your latest commit hash with the following command:

```shell
git rev-parse HEAD
```

:warning: Remember, you __MUST__ make a submission on mycourses before the deadline to be considered on time.
