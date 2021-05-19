#include "../include/GameObject.h"
#include "../include/TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y){
  objTexture = TextureManager::LoadTexture(texturesheet);
  xpos = x;
  ypos = y;
}

bool noMazeCollison(int nx,int ny,vector<vector<vector<int>>>& MazeMap){
	int j1=(nx-150)/30;
	int i1=(ny-50)/30;
	int i2=(ny-50+25-1)/30;
	int j2=(nx-150+25-1)/30;
	
	if(MazeMap[i1][j1][0]==-1){
		return false;
	}
	if(MazeMap[i2][j1][0]==-1){
		return false;
	}
	if(MazeMap[i1][j2][0]==-1){
		return false;
	}
	if(MazeMap[i2][j2][0]==-1){
		return false;
	}
	
	/*if(MazeMap[i1][j1][1]){
		if(ny<=100+i1*40+1){
			return false;
		}
	}
	if(MazeMap[i1][j1][2]){
		if(nx<=200+j1*40+1){
			return false;
		}
	}
	if(i1+1>=10 || (i1+1<10 && MazeMap[i1+1][j1][1])){
		if(ny+25>100+(i1+1)*40){
			return false;
		}
	}
	if(j1+1>=10 || (j1+1<10 && MazeMap[i1][j1+1][2])){
		if(nx+25>200+(j1+1)*40){
			return false;
		}
	}
	
	if(MazeMap[i2][j1][2]){
		if(nx<=200+j1*40+1){
			return false;
		}
	}
	if(j1+1>=10 || (j1+1<10 && MazeMap[i2][j1+1][2])){
		if(nx+25>200+(j1+1)*40){
			return false;
		}
	}
	
	if(MazeMap[i1][j2][1]){
		if(ny<=100+i1*40+1){
			return false;
		}
	}
	if(i1+1>=10 || (i1+1<10 && MazeMap[i1+1][j2][1])){
		if(ny+25>100+(i1+1)*40){
			return false;
		}
	}*/
	
	return true;
}
void GameObject::Update(vector<vector<vector<int>>>& MazeMap,int color){
  int nxpos=xpos,nypos=ypos;
  switch(move){
    case MOVE_UP:
    	nypos=ypos-1;
    	break;
    case MOVE_RIGHT:
    	nxpos=xpos+1;
    	break;
    case MOVE_DOWN:
    	nypos=ypos+1;
    	break;
    case MOVE_LEFT:
    	nxpos=xpos-1;
    	break;
    default:
    	break;
  }
  
  bool ispossible = noMazeCollison(nxpos,nypos,MazeMap);
  if(ispossible){
  	xpos=nxpos;
  	ypos=nypos;
  	/*int i1=(ypos-100+2)/40;
  	int i2=(ypos-100+25-3)/40;
  	int j1=(xpos-200+2)/40;
  	int j2=(xpos-200+25-3)/40;
  	if(i1==i2 && j1==j2){
  		MazeMap[i1][j1][0]=color;
  	}*/
  	int i=(ypos-50+12)/30;
  	int j=(xpos-150+12)/30;
  	if(MazeMap[i][j][1]==0){
  		MazeMap[i][j][0]=color;
  	}
  }
  else{
  	move=NO_CHANGE;
  }

  srcRect.h = 24;
  srcRect.w = 24;
  srcRect.x = 0;
  srcRect.y = 0;

  destRect.x = xpos;
  destRect.y = ypos;
  destRect.w = srcRect.w;
  destRect.h = srcRect.h;
}
void GameObject::Render(){
  SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
