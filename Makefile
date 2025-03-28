COMPILER=g++-14
CXXFLAGS=-std=c++17 -Wall -fsanitize=address,leak -g
LDFLAGS=-fsanitize=address,leak
all: main

main: main.o Song.o Playlist.o
	${COMPILER} main.o Song.o Playlist.o -o main

main.o: main.cpp
	${COMPILER} -c main.cpp -o main.o
Song.o: Song.cpp
	${COMPILER} -c Song.cpp -o Song.o
Playlist.o: Playlist.cpp
	${COMPILER} -c Playlist.cpp -o Playlist.o
.PHONY: clean
clean:
	rm *.o main