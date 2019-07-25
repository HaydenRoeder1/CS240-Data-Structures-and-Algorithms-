title = program2
file2 = Scanner
file3 = Planet
file4 = Heap
file5 = Parser
CFLAGS = -g -Wextra -std=c++14
all: $(title)

$(title): $(title).o  $(file2).o $(file3).o $(file5).o
	g++ $(CFLAGS) $(title).o $(file2).o $(file3).o $(file5).o -o $(title)

$(title).o: $(file2).cpp $(file3).cpp $(file5).cpp $(title).cpp
	g++ -c $(CFLAGS) $(title).cpp -o $(title).o

$(file2).o: $(file2).cpp
	g++ -c $(CFLAGS) $(file2).cpp -o $(file2).o

$(file3).o: $(file3).cpp
	g++ -c $(CFLAGS) $(file3).cpp -o $(file3).o

$(file5).o: $(file5).cpp
	g++ -c $(CFLAGS) $(file5).cpp -o $(file5).o

run: $(title)
	./$(title)
clean:
	rm -rf *.o
	rm -rf $(title)
memcheck: $(title)
	valgrind ./$(title)
