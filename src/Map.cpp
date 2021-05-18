#include "../include/Map.h"
#include <iostream>

using namespace std;

Map::Map(){
  // src.x = src.y = 0;
  // src.w = src.h = 20;
  // dest.x = 150;
  // dest.y = 50;
  // dest.w = 500;
  // dest.h = 500;
  white = TextureManager::LoadTexture("assets/WHITE.bmp");
  black = TextureManager::LoadTexture("assets/BLACK.bmp");
  LoadMap();
  src.x = src.y = 0;
  src.h = src.w = 10;
  dest.w = dest.h = 25;
  dest.x = dest.y = 0;
}

Map::~Map(){
  SDL_DestroyTexture(maze);
}

void Map::LoadMap(){
  // maze = TextureManager::LoadTexture("MAZE_10x10_n64.bmp");
  Maze maze(1,10,10);
  cell** tmp;
  tmp= new cell*[10];
  for(int i=0;i<10;i++){
    tmp[i]=new cell[10];
  }
  tmp = maze.create();
  for(int y = 0;y<17;y++){
    for(int x = 0;x<17;x++){
      if(x%2== 1 && y%2==1){
        if(tmp[x/2+1][y/2+1].in){
          map[x][y] = 0;
        }
        else{
          map[x][y] = 1;
        }
      }
      else if(x%2 == 0 && y%2 == 0){
        map[x][y] = 1;
      }
      else if(x%2 == 0 && y%2 == 1){
        if(tmp[x/2+1][y/2+1].left){
          map[x][y] = 1;
        }
        else{
          map[x][y] = 0;
        }
      }
      else if(x%2 == 1 && y%2 == 0){
        if(tmp[x/2+1][y/2+1].up){
          map[x][y] = 1;
        }
        else{
          map[x][y] = 0;
        }
      }
    }
  }
}
void Map::DrawMap(){
  // TextureManager::Draw(maze, src, dest);
  int type = 0;
  for(int row=0;row<17;row++){
    for(int col = 0;col<17;col++){
      type = map[row][col];
      dest.x = col*25;
      dest.y = row*25;
      switch (type) {
        case 0:
          TextureManager::Draw(white,src,dest);
          break;
        case 1:
          TextureManager::Draw(black,src,dest);
          break;
        default:
          break;
      }
    }
  }
}
