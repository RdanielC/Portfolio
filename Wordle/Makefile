CXX=g++
CXXFLAGS=-Wall -Werror -std=c++11
game: game.o WordleGame.o
	$(CXX) -o $@ $^
clean:
	rm -f game *.o
