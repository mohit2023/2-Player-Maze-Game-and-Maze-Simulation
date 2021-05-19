#pragma once

#include "Game.h"
#include "GameObject.h"

class PowerPillComponent{
public:
	PowerPillComponent(const char*);
	~PowerPillComponent();
	
	void Update(vector<vector<vector<int>>>&);
	void Render();
	void Usage(GameObject*);
private:
	bool pillPresent;
	int x;
	int y;
	SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
};
