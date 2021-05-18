#include "../include/TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture){
  SDL_Surface* tempSurface = SDL_LoadBMP(texture);
  SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
  SDL_FreeSurface(tempSurface);
  return tex;
}
