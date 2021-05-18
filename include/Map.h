#pragma once

#include "Game.h"
#include "TextureManager.h"
#include "Maze.h"

class Map{
public:
  Map();
  ~Map();
  void LoadMap();
private:
  SDL_Rect src, dest;
  SDL_Texture* maze;
  SDL_Texture* white;
  SDL_Texture* black;
  int map[17][17];
};
