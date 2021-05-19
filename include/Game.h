#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <vector>
#include "Maze.h"

using namespace std;

class Game{
public:
  Game(Maze&);
  ~Game();
  void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

  void handleEvents();
  void update();
  void render();
  void clean();

  bool running() {return isRunning;}

  static SDL_Renderer *renderer;
private:
  int cnt = 0;
  bool isRunning = false;
  vector<vector<vector<int>>> MazeMap;
  SDL_Window *window;
  
  void processInput(SDL_Event);
  void drawMaze();
};
