SDL = `pkg-config --cflags --libs sdl2`
IMG = -lSDL2_image
AUD = -lSDL2_mixer
TTF = -lSDL2_ttf
builddeps = Maze.o Vector2D.o TextureManager.o Map.o GameObject.o PowerPillComponent.o TimerComponent.o ResultComponent.o Game.o main.o
buildobjs = bin/Maze.o bin/Vector2D.o bin/TextureManager.o bin/Map.o bin/GameObject.o bin/PowerPillComponent.o bin/TimerComponent.o bin/ResultComponent.o bin/Game.o bin/main.o
all: $(builddeps)
	g++ -o run $(buildobjs) $(SDL) $(IMG) $(TTF) $(AUD)

Maze.o: src/Maze.cpp
	g++ -c src/Maze.cpp $(SDL) $(IMG) $(TTF) $(AUD)
	mv Maze.o bin/Maze.o
Game.o: src/Maze.cpp
	g++ -c src/Game.cpp $(SDL) $(IMG) $(TTF) $(AUD)
	mv Game.o bin/Game.o
TextureManager.o: src/TextureManager.cpp
	g++ -c src/TextureManager.cpp $(SDL) $(IMG) $(TTF) $(AUD)
	mv TextureManager.o bin/TextureManager.o
Map.o: src/Map.cpp
	g++ -c src/Map.cpp $(SDL) $(IMG) $(TTF) $(AUD)
	mv Map.o bin/Map.o
Vector2D.o: src/Vector2D.cpp
	g++ -c src/Vector2D.cpp $(SDL) $(IMG) $(TTF) $(AUD)
	mv Vector2D.o bin/Vector2D.o
GameObject.o: src/GameObject.cpp
	g++ -c src/GameObject.cpp $(SDL) $(IMG) $(TTF) $(AUD)
	mv GameObject.o bin/GameObject.o
PowerPillComponent.o: src/PowerPillComponent.cpp
	g++ -c src/PowerPillComponent.cpp $(SDL) $(IMG) $(TTF)
	mv PowerPillComponent.o bin/PowerPillComponent.o
TimerComponent.o: src/TimerComponent.cpp
	g++ -c src/TimerComponent.cpp $(SDL) $(IMG) $(TTF) $(AUD)
	mv TimerComponent.o bin/TimerComponent.o
ResultComponent.o: src/ResultComponent.cpp
	g++ -c src/ResultComponent.cpp $(SDL) $(IMG) $(TTF) $(AUD)
	mv ResultComponent.o bin/ResultComponent.o
main.o: src/main.cpp
	g++ -c src/main.cpp $(SDL) $(IMG) $(TTF) $(AUD)
	mv main.o bin/main.o
