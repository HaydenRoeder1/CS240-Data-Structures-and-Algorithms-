title = lab6
CFLAGS = -g -Wall -Wextra -DDEBUG -std=c++14
all: $(title).o BSTree.h
	g++ $(CFLAGS) $(title).o -o $(title)
$(title).o: $(title).cpp BSTree.h
	g++ -c $(CFLAGS) $(title).cpp -o $(title).o
run: all
	./$(title)
clean:
	rm -rf *.o
	rm -rf $(title)
memcheck: all
	valgrind ./$(title)
