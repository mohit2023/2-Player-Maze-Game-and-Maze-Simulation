#include <string>
#include <sstream>
#include "../include/ResultComponent.h"
#include "../include/TextureManager.h"
#include "SDL_ttf.h"

ResultComponent::ResultComponent(vector<vector<vector<int>>>& MazeMap){
	score1=0;
	score2=0;
	for(int i=0;i<17;i++){
		for(int j=0;j<17;j++){
			if(MazeMap[i][j][0]==1){
				score1++;
			}
			if(MazeMap[i][j][0]==2){
				score2++;
			}
		}
	}

	if(score1==score2){
		winner=0;
	}
	else if(score1>score2){
		winner=1;
	}
	else{
		winner=2;
	}
}

void textRender(stringstream& t,TTF_Font* font,int x,int y){
	SDL_Surface* textSurface = TTF_RenderText_Solid(font,t.str().c_str(),{0,0,0,255});
	SDL_Texture* mTexture = SDL_CreateTextureFromSurface(Game::renderer,textSurface);
	SDL_Rect renderQuad = {x,y,textSurface->w,textSurface->h};
	SDL_FreeSurface(textSurface);
	SDL_SetRenderDrawColor(Game::renderer,0xFF,0xFF,0xFF,0xFF);
	SDL_RenderCopyEx(Game::renderer,mTexture,NULL,&renderQuad,0.0,NULL,SDL_FLIP_NONE);
}

void ResultComponent::Render(){
	stringstream scoreboard;
	scoreboard<<"Scoreboard";
	stringstream p1score;
	stringstream p2score;
	stringstream endresult;
	p1score<<"Player 1 : ";
	p1score<<score1;
	p2score<<"Player 2 : ";
	p2score<<score2;
	endresult<<"Result: ";
	if(winner==0){
		endresult<<"Draw";
	}
	else{
		endresult<<"Player ";
		endresult<<winner;
		endresult<<" Won";
	}

	TTF_Font* font = TTF_OpenFont("assets/Sans.ttf",26);
	if(!font) {
		cout<<TTF_GetError();
	}

	textRender(scoreboard, font, 330, 70);
	textRender(p1score,font,320,120);
	textRender(p2score,font,320,180);
	textRender(endresult,font,280,350);

	SDL_Texture* player1 = TextureManager::LoadTexture("assets/Clyde.bmp");
	SDL_Texture* player2 = TextureManager::LoadTexture("assets/Pinky.bmp");
	SDL_Rect srcRect, destRect;
	srcRect.x = srcRect.y =0;
	srcRect.w = srcRect.h = 25;
	destRect.x = 375;
	destRect.y = 400;
	destRect.h = destRect.w = 50;
	if(winner == 1){
		TextureManager::Draw(player1,srcRect,destRect);
	}
	else if(winner == 2){
		TextureManager::Draw(player2,srcRect,destRect);
	}

	TTF_CloseFont(font);
}
