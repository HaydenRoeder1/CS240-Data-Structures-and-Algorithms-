title = lab8
file2 = Hash

CFLAGS = -g -Wextra -std=c++14
all: $(title)

$(title): $(title).o  $(file2).o
	g++ $(CFLAGS) $(title).o $(file2).o -o $(title)

$(title).o: $(file2).cpp $(title).cpp
	g++ -c $(CFLAGS) $(title).cpp -o $(title).o

$(file2).o: $(file2).cpp
	g++ -c $(CFLAGS) $(file2).cpp -o $(file2).o


run: $(title)
	./$(title)
clean:
	rm -rf *.o
	rm -rf $(title)
memcheck: $(title)
	valgrind ./$(title)
