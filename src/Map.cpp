#include "../include/Map.h"

Map::Map(){
  src.x = src.y = 0;
  src.w = src.h = 20;
  dest.x = 150;
  dest.y = 50;
  dest.w = 500;
  dest.h = 500;
  LoadMap();
}

Map::~Map(){}

void Map::LoadMap(){
  maze = TextureManager::LoadTexture("MAZE_10x10_n64.bmp");
}
void Map::DrawMap(){
  TextureManager::Draw(maze, src, dest);
}
