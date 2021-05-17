#include "../include/Game.h"
#include "../include/TextureManager.h"

using namespace std;
SDL_Texture* playerTex;
SDL_Rect srcR, destR;

Game::Game(){}
Game::~Game(){}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
  int flags = 0;
  if (fullscreen){
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if(SDL_Init(SDL_INIT_EVERYTHING)==0){
    cout<<"Subsystems initialised"<<endl;

    window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if(window){
      cout<<"Window Created"<<endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer){
      SDL_SetRenderDrawColor(renderer, 238, 232, 125, 255);
      cout<<"Renderer created"<<endl;
    }
    isRunning = true;
  }
  else{
    isRunning = false;
  }

  // SDL_Surface* tmpSurface = SDL_LoadBMP("MAZE_10x10_n64.bmp");
  playerTex = TextureManager::LoadTexture("MAZE_10x10_n64.bmp",renderer);
  // SDL_FreeSurface(tmpSurface);
}
void Game::handleEvents(){
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type) {
    case SDL_QUIT:
      isRunning = false;
      break;
    default:
      break;
  }
}
void Game::update(){
  cnt++;
  destR.h = 500;
  destR.w = 500;
  destR.x = 150;
  destR.y = 50;
  // cout<<cnt<<endl;
}
void Game::render(){
  SDL_RenderClear(renderer);
  // Add stuff to renderer
  SDL_RenderCopy(renderer,playerTex, NULL, &destR);
  SDL_RenderPresent(renderer);
}
void Game::clean(){
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  cout<<"Game Cleaned"<<endl;
}
