#### CS 240 - Spring 2019
# Lab 4 - Templates
## Due Date: 11:59 p.m., March 6th, 2019

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Provided Files and Expected Output
* _Files_
    * lab4.cpp
* _Expected Command > Output_
    * Test Commands we will run
        * make
        * make run
        * make checkmem
        * make clean
    * Sample Output (with our test case):
```shell
        ./lab4
	TEST #1: Test create a integer Vector
	========================PASS========================
	TEST #2: Test create a double Vector
	========================PASS========================
	TEST #3: Test copy constructor and delete all elements from Vector
	========================PASS========================
	TEST #4: Test add 1 element to a Queue
	========================PASS========================
	TEST #5: Test fill a char Queue
	========================PASS========================
	TEST #6: Test Queue Order
	========================PASS========================
	TEST #7: Test Queue Interface
	========================PASS========================
	Don't forget to run with Valgrind and commit to Github!
```

### Grading Rubric
**_TOTAL: 20 points_**
* **Part A: (9 points)**
    * TEST #1: Test create a int Vector (3 points)
    * TEST #2: Test create a double Vector (3 points)
    * TEST #3: Test delete elements from both Vectors (3 points)
* **Part B: (11 points)**
    * TEST #4: Test add 1 element to a Queue (2 points)
    * TEST #5: Test create a Queue (3 points)
    * TEST #6: Test Queue Order (3 points)
    * TEST #7: Test Queue interface (3 points)
* **Part C:**
    * If memory error, memory leak, no 'checkmem' target [-5 points]
    * Does not follow requested project structure, makefile, and submission format [-3 points]
    * Submission includes .o files or binary [-1 point]
    * Does not follow [Style guidelines](https://drive.google.com/open?id=1a5I7XhhCDRHoS8LUfILu3y2la4wW8HHh4olO30YvMVk) [-3 points]

### Guidelines

This is an individual lab assignment. You must do the vast majority of the work on your own. It is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically *to* solve the problem you have been given, and you may not have anyone else help you write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

*By submitting this assignment, you agree that you have followed the above guidelines regarding collaboration and research.*

***

The goal of Lab 4 is to get you to Templatize some of your code from program1, and use your expanding library for another ADT. You are going to expand and refine your existing library by templatizing your Vector using C++ templates. Once you have successfully templated your code, you will use your fancy new template vector library to implement a Queue data structure.

:bulb: You do not have to keep your Vector the same as the project. You can start fresh if you like.

#### (Parts A must be completed in lab)

## Part A: Preparing for Exploration.

Now that you have created Data Structures to simulate the universe with planets and stars, you will next need to explore your universe. We want to prepare a probe that we will send out into our universe to find planets with the possibility of life. Since we do not know what we will find in our universe, we should be prepared for anything.

You are going to templatize your Vector from Program 1 so it can work with many types without writing multiple classes. As you are templatizing your vector, be sure to remember that all of your code must be moved into a header file. You will need to eliminate the .cpp file completely.

Your Vector will also need the following public interface:
* `Vector(int size)`
    * an initial starting size of your vector
* `Vector(const Vector<type> & v)`
    * A copy constructor
* `<type>& operator [](std::size_t index)`
    * Overload the [] operator.
    * I do not test out of bounds behavior, so you can handle that however you like
* `unsigned int size()`
    * returns the size of your vector
* `void clear()`
    * deletes your vector data and sets the size to 0
    * :warning: This is not a destructor. It does not delete the vector itself. It just reduces the size of the internal array to 0. Depending on how you implement your vector, you may also need a destructor.
* You may add any additional methods you require. This means you can use your existing methods to implement the above interface if you want to.

:warning: Every instance of `Planet *` from your previous code needs to become a type variable, and no specific calls to Planet methods should remain.

:bulb: Here is a resource that gives a brief overview of templates if you need a syntax reminder
* https://www.tutorialspoint.com/cplusplus/cpp_templates.htm

## Part B: Using your Vector Library for a Queue

Once you have completed your templated Vector, you will use it to create Queue template data structure. Your Queue should be in separate file (Queue.h), and should use your Vector as an internal data structure. This means you need to have the following methods:
* `Queue(unsigned int size)`
    * A max size for your queue
    * Your internal vector should never expand or shrink
* `bool enqueue(<type> data)`
    * Adds a data object onto the queue and returns a boolean if successful
* `<type> dequeue()`
    * removes a data object from the queue and returns it
* `<type> peek()`
    * returns a copy (not a reference) of the data object but does not remove it from the list
* `bool empty()`
    * returns `true` if the queue is empty, `false` otherwise.
* `void clear()`
   * deletes all items from the queue

:bulb: You may add any additional methods you like. For example, you may need a destructor, depending on your implementation.

## Part C : Code Organization and Submission
* Required code organization:
    * lab4.cpp (driver code - You must include this file in your submission)
    * Vector.h
    * Queue.h
    * makefile
        * executable should be called: lab4
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

To complete your submission, you must copy and paste the commit hash into MyCourses. Go to MyCourses, select CS240, and then assignments. Select Lab 4, and where it says text submission, paste your commit hash. You can get your latest commit hash with the following command:

```shell
git rev-parse HEAD
```

:warning: Remember, you __MUST__ make a submission on mycourses before the deadline to be considered on time.
