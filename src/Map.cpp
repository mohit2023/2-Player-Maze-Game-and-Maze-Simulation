#include "../include/Map.h"
#include "../include/Game.h"

Map::Map(){
  LoadMap();
}

Map::~Map(){
}

void Map::LoadMap(){
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
  int type = 0;
  for(int row=0;row<17;row++){
    for(int col = 0;col<17;col++){
      type = map[row][col];
      Game::AddTile(type, col*25, row*25);
    }
  }
}
