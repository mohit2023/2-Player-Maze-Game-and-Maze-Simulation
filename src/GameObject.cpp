#include "../include/GameObject.h"
#include "../include/TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y){
  objTexture = TextureManager::LoadTexture(texturesheet);

  xpos = x;
  ypos = y;
}
void GameObject::Update(){
  xpos++;
  ypos++;

  srcRect.h = 25;
  srcRect.w = 25;
  srcRect.x = 0;
  srcRect.y = 0;

  destRect.x = xpos;
  destRect.y = ypos;
  destRect.w = srcRect.w;
  destRect.h = srcRect.h;
}
void GameObject::Render(){
  SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
