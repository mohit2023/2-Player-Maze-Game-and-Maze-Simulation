all: Maze.o main.o
	g++ -o run bin/Maze.o bin/main.o

Maze.o: src/Maze.cpp
	g++ -c src/Maze.cpp
	mv Maze.o bin/Maze.o
main.o: src/main.cpp
	g++ -c src/main.cpp
	mv main.o bin/main.o
