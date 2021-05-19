SDL = `pkg-config --cflags --libs sdl2`
IMG = -lSDL2_image
builddeps = Maze.o Collision.o ECS.o Vector2D.o TextureManager.o Map.o GameObject.o Game.o main.o
buildobjs = bin/Maze.o bin/Collision.o bin/ECS.o bin/Vector2D.o bin/TextureManager.o bin/Map.o bin/GameObject.o bin/Game.o bin/main.o
all: $(builddeps)
	g++ -o run $(buildobjs) $(SDL) $(IMG)

Maze.o: src/Maze.cpp
	g++ -c src/Maze.cpp $(SDL) $(IMG)
	mv Maze.o bin/Maze.o
Game.o: src/Maze.cpp
	g++ -c src/Game.cpp $(SDL) $(IMG)
	mv Game.o bin/Game.o
TextureManager.o: src/TextureManager.cpp
	g++ -c src/TextureManager.cpp $(SDL) $(IMG)
	mv TextureManager.o bin/TextureManager.o
Map.o: src/Map.cpp
	g++ -c src/Map.cpp $(SDL) $(IMG)
	mv Map.o bin/Map.o
Vector2D.o: src/Vector2D.cpp
	g++ -c src/Vector2D.cpp $(SDL) $(IMG)
	mv Vector2D.o bin/Vector2D.o
GameObject.o: src/GameObject.cpp
	g++ -c src/GameObject.cpp $(SDL) $(IMG)
	mv GameObject.o bin/GameObject.o
Collision.o: src/Collision.cpp
	g++ -c src/Collision.cpp $(SDL) $(IMG)
	mv Collision.o bin/Collision.o
ECS.o: src/ECS.cpp
	g++ -c src/ECS.cpp $(SDL) $(IMG)
	mv ECS.o bin/ECS.o
main.o: src/main.cpp
	g++ -c src/main.cpp $(SDL) $(IMG)
	mv main.o bin/main.o
