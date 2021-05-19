#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <vector>

using namespace std;

class ColliderComponent;

class Game{
public:
  Game();
  ~Game();
  void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

  void handleEvents();
  void update();
  void render();
  void clean();

  bool running() {return isRunning;}
  enum groubLabels : size_t{
    groupMap,
    groupPlayers,
    groupColliders
  };

  static void AddTile(int id, int x, int y);
  static SDL_Renderer *renderer;
  static SDL_Event event;
  static vector<ColliderComponent*> colliders;
  static bool isRunning;
private:
  int cnt = 0;
  SDL_Window *window;
};
