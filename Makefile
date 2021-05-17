SDL = `pkg-config --cflags --libs sdl2`
IMG = -lSDL2_image
builddeps = Maze.o Game.o main.o
buildobjs = bin/Maze.o bin/Game.o bin/main.o
all: $(builddeps)
	g++ -o run $(buildobjs) $(SDL) $(IMG)

Maze.o: src/Maze.cpp
	g++ -c src/Maze.cpp $(SDL) $(IMG)
	mv Maze.o bin/Maze.o
Game.o: src/Maze.cpp
	g++ -c src/Game.cpp $(SDL) $(IMG)
	mv Game.o bin/Game.o
main.o: src/main.cpp
	g++ -c src/main.cpp $(SDL) $(IMG)
	mv main.o bin/main.o
