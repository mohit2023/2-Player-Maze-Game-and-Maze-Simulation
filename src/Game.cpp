#include "../include/Game.h"
#include "../include/TextureManager.h"
#include "../include/Components.h"
#include "../include/Map.h"
#include "../include/Vector2D.h"
#include "../include/Collision.h"

using namespace std;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
vector<ColliderComponent*> Game::colliders;

Map* map;
Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

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
  map = new Map();

  // SDL_Surface* tmpSurface = SDL_LoadBMP("MAZE_10x10_n64.bmp");
  // playerTex = TextureManager::LoadTexture("MAZE_10x10_n64.bmp",renderer);
  // player1 = new GameObject("assets/Clyde.bmp",0,0);
  // player2 = new GameObject("assets/Pinky.bmp",30,30);
  player.addComponent<TransformComponent>(25.0,25.0);
  player.addComponent<SpriteComponent>("assets/Clyde.bmp");
  player.addComponent<KeyboardController>();
  player.addComponent<ColliderComponent>("player");
  // newPlayer.getComponent<PositionComponent>();
  wall.addComponent<TransformComponent>(300.0f,300.0f,300,20,1);
  wall.addComponent<ColliderComponent>("wall");
  // SDL_FreeSurface(tmpSurface);
}
void Game::handleEvents(){
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
  // player1->Update();
  // player2->Update();
  manager.refresh();
  manager.update();

  if(Collision::AABB(player.getComponent<ColliderComponent>().collider,wall.getComponent<ColliderComponent>().collider)){
    player.getComponent<TransformComponent>().velocity * -1;
    cout<<"Hit!"<<endl;
  }
}
void Game::render(){
  SDL_RenderClear(renderer);
  // Add stuff to renderer
  map->DrawMap();
  // SDL_RenderCopy(renderer,playerTex, NULL, &destR);
  // player1->Render();
  // player2->Render();
  manager.draw();
  SDL_RenderPresent(renderer);
}
void Game::clean(){
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  cout<<"Game Cleaned"<<endl;
}
