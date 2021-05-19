#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/PowerPillComponent.h"
#include "../include/TextureManager.h"

PowerPillComponent::PowerPillComponent(const char* texturesheet){
	objTexture = TextureManager::LoadTexture(texturesheet);
	srcRect.h = 22;
	srcRect.w = 22;
	srcRect.x = 0;
    srcRect.y = 0;
    destRect.w = srcRect.w;
    destRect.h = srcRect.h;
	pillPresent = false;
	srand(time(0));
}
PowerPillComponent::~PowerPillComponent(){}

void PowerPillComponent::Usage(GameObject* player){
	if(pillPresent==false){
		return ;
	}
	int i = (player->ypos-50+12)/30;
	int j = (player->xpos-150+12)/30;
	
	if(i==x && j==y){
		pillPresent=false;
		player->power+=7;
	}
}

void PowerPillComponent::Update(vector<vector<vector<int>>>& MazeMap){
	if(pillPresent){
		return ;
	}
	int num = rand()%100;
	if(num>49 && num<51){
		int i=rand()%17;
		int j=rand()%17;
		if(MazeMap[i][j][0]!=-1){
			x=i;
			y=j;
			pillPresent=true;
		}
	}
}

void PowerPillComponent::Render(){
	if(pillPresent==false){
		return ;
	}	
	int xpos = 150+y*30;
	int ypos = 50+x*30;
    destRect.x = xpos+4;
    destRect.y = ypos+4;
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}

