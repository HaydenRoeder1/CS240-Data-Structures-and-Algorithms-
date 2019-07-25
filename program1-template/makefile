CFLAGS = -g -Wall -Wextra -DDEBUG -std=c++14
all: program1.o
	g++ $(CFLAGS) list.o planet.o vector.o star.o program1.o -o program4
program1.o: list.o planet.o vector.o star.o program1.cpp
	g++ -c $(CFLAGS) program1.cpp -o program1.o
planet.o: Planet.cpp
	g++ -c $(CFLAGS) Planet.cpp -o planet.o
list.o: List.cpp
	g++ -c $(CFLAGS) List.cpp -o list.o
vector.o: Vector.cpp
	g++ -c $(CFLAGS) Vector.cpp -o vector.o
star.o: Star.cpp
	g++ -c $(CFLAGS) Star.cpp -o star.o
clean:
	rm -rf *.o
run: all
	./program4
memcheck: all
	valgrind --leak-check=full ./program4 
