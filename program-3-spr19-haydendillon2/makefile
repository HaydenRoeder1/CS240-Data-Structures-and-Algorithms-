title = program3
file2 = Planet
file3 = Galaxy

CFLAGS = -g -Wextra -std=c++14 -O3
all: $(title)

$(title): $(title).o  $(file2).o $(file3).o
	g++ $(CFLAGS) $(title).o $(file2).o $(file3).o -o $(title)

$(title).o: $(file2).cpp $(file3).cpp $(title).cpp
	g++ -c $(CFLAGS) $(title).cpp -o $(title).o

$(file2).o: $(file2).cpp
	g++ -c $(CFLAGS) $(file2).cpp -o $(file2).o
$(file3).o: $(file3).cpp
	g++ -c $(CFLAGS) $(file3).cpp -o $(file3).o


run: $(title)
	./$(title)
clean:
	rm -rf *.o
	rm -rf $(title)
memcheck: $(title)
	valgrind ./$(title)
