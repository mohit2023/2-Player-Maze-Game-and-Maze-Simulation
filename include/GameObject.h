#pragma once

#include "Game.h"

enum player_moves{
	NO_CHANGE,
	MOVE_UP,
	MOVE_RIGHT,
	MOVE_DOWN,
	MOVE_LEFT
};

class GameObject{
public:
  GameObject(const char* texturesheet, int x, int y);
  ~GameObject();

  void Update(vector<vector<vector<int>>>&,int);
  void Render();
  int move=NO_CHANGE;
  int xpos;
  int ypos;
  int power;
  
private:
  SDL_Texture* objTexture;
  SDL_Rect srcRect, destRect;

};
