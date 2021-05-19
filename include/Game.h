#pragma once

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include <iostream>
#include <vector>

using namespace std;

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
  bool isgameOver() {return gameOver;}
  static bool isRunning;

  static SDL_Renderer *renderer;
  static Mix_Chunk* soundeffect;
  static Mix_Music* bgm;
private:
  //int cnt = 0;
  bool gameOver;
  SDL_Window *window;
};
