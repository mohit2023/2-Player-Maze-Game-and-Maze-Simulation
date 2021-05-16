SDLFLAGS = `pkg-config --cflags --libs sdl2`
builddeps = Maze.o Game.o main.o
buildobjs = bin/Maze.o bin/Game.o bin/main.o
all: $(builddeps)
	g++ -o run $(buildobjs) $(SDLFLAGS)

Maze.o: src/Maze.cpp
	g++ -c src/Maze.cpp $(SDLFLAGS)
	mv Maze.o bin/Maze.o
Game.o: src/Maze.cpp
	g++ -c src/Game.cpp $(SDLFLAGS)
	mv Game.o bin/Game.o
main.o: src/main.cpp
	g++ -c src/main.cpp $(SDLFLAGS)
	mv main.o bin/main.o
