#pragma once

#include <iostream>
#include <vector>

#include "Game.h"

class Map{
public:
  Map();
  ~Map();
  void LoadMap();
  void drawMaze();
  vector<vector<vector<int>>> MazeMap;
};
