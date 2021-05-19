#include <string>
#include <sstream>
#include "../include/TimerComponent.h"
#include "SDL_ttf.h"

TimerComponent::TimerComponent(int currentTicks){
	timeLimit=60;
	start=currentTicks;
	timerValue=60;
}

int TimerComponent::timeRemaining(){
	return timerValue;
}

void TimerComponent::Update(int currentTicks){
	int timePassed = currentTicks-start;
    timerValue = timeLimit- timePassed/1000;
	//cout<<timerValue<<"\n";
}

void TimerComponent::Render(){
	stringstream time;
	time<<"Time remaining:  ";
	time<<timerValue;
	time<<"  seconds";
	TTF_Font* font = TTF_OpenFont("assets/Sans.ttf",26);
	if(!font) {
		cout<<TTF_GetError();
	}
	SDL_Surface* textSurface = TTF_RenderText_Solid(font,time.str().c_str(),{0,0,0,255});
	SDL_Texture* mTexture = SDL_CreateTextureFromSurface(Game::renderer,textSurface);
	SDL_Rect renderQuad = {10,10,textSurface->w,textSurface->h};
	SDL_FreeSurface(textSurface);
	SDL_SetRenderDrawColor(Game::renderer,0xFF,0xFF,0xFF,0xFF);
	//SDL_RenderClear(Game::renderer);
	SDL_RenderCopyEx(Game::renderer,mTexture,NULL,&renderQuad,0.0,NULL,SDL_FLIP_NONE);
	//SDL_RenderPresent(Game::renderer);
	TTF_CloseFont(font);
}
