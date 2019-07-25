title = lab5
file2 = Planet
file3 = Star
file4 = Probe
CFLAGS = -g -Wall -Wextra -DDEBUG -std=c++14
all: $(title).o $(file2).o $(file3).o $(file4).o
	g++ $(CFLAGS) $(title).o $(file2).o $(file3).o $(file4).o -o $(title)
$(title).o: $(file2).o $(file3).o $(file4).o $(title).cpp
	g++ -c $(CFLAGS) $(title).cpp -o $(title).o
$(file2).o: $(file2).cpp
	g++ -c $(CFLAGS) $(file2).cpp -o $(file2).o
$(file3).o: $(file3).cpp
	g++ -c $(CFLAGS) $(file3).cpp -o $(file3).o
$(file4).o: $(file4).cpp
	g++ -c $(CFLAGS) $(file4).cpp -o $(file4).o
run: all
	./$(title)
clean:
	rm -rf *.o
	rm -rf $(title)
memcheck: all
	valgrind ./$(title)
