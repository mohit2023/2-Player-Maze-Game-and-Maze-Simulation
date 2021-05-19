#include "../include/Map.h"
#include "../include/Game.h"
#include "../include/Maze.h"

Map::Map(){
  MazeMap.resize(17,vector<vector<int>>(17,vector<int>(2)));
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
          MazeMap[x][y][0] = 0;
        }
        else{
          MazeMap[x][y][0] = -1;
        }
      }
      else if(x%2 == 0 && y%2 == 0){
        MazeMap[x][y][0] = -1;
      }
      else if(x%2 == 0 && y%2 == 1){
        if(tmp[x/2+1][y/2+1].left){
          MazeMap[x][y][0] = -1;
        }
        else{
          MazeMap[x][y][0] = 0;
        }
      }
      else if(x%2 == 1 && y%2 == 0){
        if(tmp[x/2+1][y/2+1].up){
          MazeMap[x][y][0] = -1;
        }
        else{
          MazeMap[x][y][0] = 0;
        }
      }
      MazeMap[x][y][1]=0;
    }
  }
}

void Map::drawMaze(){
	int width=30;
	int height=30;

	int x=150;
	int y=50;
	for(int i=0;i<17;i++){
		x=150;
		for(int j=0;j<17;j++){
			if(MazeMap[i][j][0]==0){
				SDL_SetRenderDrawColor(Game::renderer,0,0,0,255); //black
			}
			else if(MazeMap[i][j][0]==-1){
				SDL_SetRenderDrawColor(Game::renderer,106,90,205,255); //slate-blue
			}
			else if(MazeMap[i][j][0]==1){
				SDL_SetRenderDrawColor(Game::renderer,255,165,0,30);	//orange
			}
			else{
				SDL_SetRenderDrawColor(Game::renderer,255,182,193,30); //light blue
			}
			SDL_Rect r;
			r.x=x;
			r.y=y;
			r.h=height;
			r.w=width;
			SDL_RenderFillRect(Game::renderer,&r);
			x+=width;
		}
		y+=height;
	}
}
