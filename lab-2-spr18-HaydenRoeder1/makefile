title = lab2
file2 = Star
CFLAGS = -g -Wall -Wextra -DDEBUG -std=c++14
all: $(title).o
	g++ $(CFLAGS) $(title).o $(file2).o -o $(title)
$(title).o: $(file2).o
	g++ -c $(CFLAGS) $(title).cpp -o $(title).o
$(file2).o: $(file2).cpp
	g++ -c $(CFLAGS) $(file2).cpp -o $(file2).o
run: all
	./$(title)
clean: 
	rm -rf *.o
	rm -rf $(title)
cleanobjects:
	rm -rf *.o
