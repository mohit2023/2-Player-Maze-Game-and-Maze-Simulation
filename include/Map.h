#pragma once

#include "Game.h"
#include "TextureManager.h"

class Map{
public:
  Map();
  ~Map();
  void LoadMap();
  void DrawMap();
private:
  SDL_Rect src, dest;
  SDL_Texture* maze;
  int **map;
};
