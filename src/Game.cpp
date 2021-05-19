#include "../include/Game.h"
#include "../include/TextureManager.h"
#include "../include/Components.h"
#include "../include/Map.h"
#include "../include/Vector2D.h"
#include "../include/GameObject.h"
#include "../include/TimerComponent.h"
#include "../include/ResultComponent.h"
#include "SDL_ttf.h"

using namespace std;

SDL_Renderer* Game::renderer = nullptr;

Map* map;
GameObject* player1;
GameObject* player2;
TimerComponent* timer;
ResultComponent* result;

bool Game::isRunning = false;

Mix_Music* Game::bgm = nullptr;
Mix_Chunk* Game::soundeffect = nullptr;

Game::Game(){
	isRunning = false;
	gameOver = true;
}
Game::~Game(){}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
  int flags = 0;
  if (fullscreen){
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if(SDL_Init(SDL_INIT_EVERYTHING)==0){
    cout<<"Subsystems initialised"<<endl;

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
			cout<<"Error: "<<Mix_GetError()<<endl;
		}
		Game::bgm = Mix_LoadMUS("assets/bgm.mp3");
		Game::soundeffect = Mix_LoadWAV("assets/col.wav");

    if(window){
      cout<<"Window Created"<<endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer){
      SDL_SetRenderDrawColor(renderer, 238, 232, 125, 255);
      cout<<"Renderer created"<<endl;
    }
    if(TTF_Init() == -1) {
    	gameOver = true;
    	isRunning = false;
    	cout<<"SDL_ttf error\n";
    }
    isRunning = true;
    gameOver = false;
  }
  else{
  	gameOver = true;
    isRunning = false;
  }

  map = new Map();
  player1 = new GameObject("assets/Clyde.bmp",182,82);
  player2 = new GameObject("assets/Pinky.bmp",602,502);
  timer = new TimerComponent(SDL_GetTicks());
}

void processInput(SDL_Event event){
	switch(event.key.keysym.sym){
		case SDLK_UP:
			player1->move = MOVE_UP;
			break;
		case SDLK_RIGHT:
			player1->move = MOVE_RIGHT;
			break;
		case SDLK_DOWN:
			player1->move = MOVE_DOWN;
			break;
		case SDLK_LEFT:
			player1->move = MOVE_LEFT;
			break;
		case SDLK_w:
			player2->move = MOVE_UP;
			break;
		case SDLK_d:
			player2->move = MOVE_RIGHT;
			break;
		case SDLK_s:
			player2->move = MOVE_DOWN;
			break;
		case SDLK_a:
			player2->move = MOVE_LEFT;
			break;
		case SDLK_ESCAPE:
			Game::isRunning = false;
			break;
		default:
			break;
	}
}

void Game::handleEvents(){
  SDL_Event event;
  SDL_PollEvent(&event);
  if(gameOver){
  	switch(event.type){
  		case SDL_QUIT:
  			isRunning = false;
  			break;
  		default:
  			break;
  	}
  	return ;
  }

  switch (event.type) {
	case SDL_QUIT:
	  isRunning = false;
	  break;
	case SDL_KEYUP:
	  processInput(event);
	  break;
	default:
	  break;
  }

  if(timer->timeRemaining() <= 0){
    gameOver=true;
    result = new ResultComponent(map->MazeMap);
  }
}

void reversePlayerMove(GameObject* player){
	if(player->move == MOVE_UP){
		player->move=MOVE_DOWN;
	}
	else if(player->move == MOVE_DOWN){
		player->move=MOVE_UP;
	}
	else if(player->move == MOVE_LEFT){
		player->move=MOVE_RIGHT;
	}
	else if(player->move == MOVE_RIGHT){
		player->move=MOVE_LEFT;
	}
}
void resolvePlayerCollision(GameObject* player1,GameObject* player2){
	if(player2->xpos+25 <= player1->xpos){
		return ;
	}
	if(player2->xpos >= player1->xpos+25){
		return ;
	}
	if(player2->ypos+25 <= player1->ypos){
		return ;
	}
	if(player2->ypos >= player1->ypos+25){
		return ;
	}
	Mix_PlayChannel(-1,Game::soundeffect,0);
	reversePlayerMove(player1);
	reversePlayerMove(player2);
}

void Game::update(){
  if(gameOver){
		Mix_HaltMusic();
  	return ;
  }
	if(!Mix_PlayingMusic()){
		Mix_PlayMusic(Game::bgm,-1);
	}
  player1->Update(map->MazeMap,1);
  player2->Update(map->MazeMap,2);
  resolvePlayerCollision(player1,player2);
  timer->Update(SDL_GetTicks());
}
void Game::render(){
  SDL_SetRenderDrawColor(renderer, 238, 232, 125, 255);
  SDL_RenderClear(renderer);
  if(gameOver){
  	result->Render();
  	SDL_RenderPresent(renderer);
  	return ;
  }
  timer->Render();
  map->drawMaze();
  player1->Render();
  player2->Render();
  SDL_RenderPresent(renderer);
}
void Game::clean(){
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
	Mix_FreeChunk(soundeffect);
	Mix_FreeMusic(bgm);
	Mix_Quit();
  SDL_Quit();
  cout<<"Game Cleaned"<<endl;
}
