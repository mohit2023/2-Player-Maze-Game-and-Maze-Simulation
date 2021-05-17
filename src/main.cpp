#include <iostream>
#include "../include/Maze.h"
#include "../include/Game.h"

using namespace std;

Game *game = nullptr;
int main(int argc, char* argv[]){
  Maze maze(1,10,10);
  maze.create();
  game = new Game();

  game->init("Pacman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

  while(game->running()){
    game->handleEvents();
    game->update();
    game->render();

  }
  game->clean();
  return 0;
}
