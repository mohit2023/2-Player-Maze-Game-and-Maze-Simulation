SDL = `pkg-config --cflags --libs sdl2`
IMG = -lSDL2_image
TTF = -lSDL2_ttf
builddeps = Maze.o Vector2D.o TextureManager.o Map.o GameObject.o TimerComponent.o Game.o main.o
buildobjs = bin/Maze.o bin/Vector2D.o bin/TextureManager.o bin/Map.o bin/GameObject.o bin/TimerComponent.o bin/Game.o bin/main.o
all: $(builddeps)
	g++ -o run $(buildobjs) $(SDL) $(IMG) $(TTF)

Maze.o: src/Maze.cpp
	g++ -c src/Maze.cpp $(SDL) $(IMG) $(TTF)
	mv Maze.o bin/Maze.o
Game.o: src/Maze.cpp
	g++ -c src/Game.cpp $(SDL) $(IMG) $(TTF)
	mv Game.o bin/Game.o
TextureManager.o: src/TextureManager.cpp
	g++ -c src/TextureManager.cpp $(SDL) $(IMG) $(TTF)
	mv TextureManager.o bin/TextureManager.o
Map.o: src/Map.cpp
	g++ -c src/Map.cpp $(SDL) $(IMG) $(TTF)
	mv Map.o bin/Map.o
Vector2D.o: src/Vector2D.cpp
	g++ -c src/Vector2D.cpp $(SDL) $(IMG) $(TTF)
	mv Vector2D.o bin/Vector2D.o
GameObject.o: src/GameObject.cpp
	g++ -c src/GameObject.cpp $(SDL) $(IMG) $(TTF)
	mv GameObject.o bin/GameObject.o
TimerComponent.o: src/TimerComponent.cpp
	g++ -c src/TimerComponent.cpp $(SDL) $(IMG) $(TTF)
	mv TimerComponent.o bin/TimerComponent.o
main.o: src/main.cpp
	g++ -c src/main.cpp $(SDL) $(IMG) $(TTF)
	mv main.o bin/main.o
