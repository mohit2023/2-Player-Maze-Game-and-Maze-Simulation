#pragma once

#include "ECS.h"
#include "Components.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"
#include "SDL2/SDL.h"

class TileComponent : public Component{
public:
  TransformComponent *transform;
  SpriteComponent *sprite;

  SDL_Rect tileRect;
  int tileID;
  const char* path;

  TileComponent() = default;
  TileComponent(int x, int y, int w, int h, int id){
    tileRect.x = x;
    tileRect.y = y;
    tileRect.h = h;
    tileRect.w = w;
    tileID = id;
    switch (tileID) {
      case 0:
        path = "assets/WHITE.bmp";
        break;
      case 1:
        path = "assets/BLACK.bmp";
        break;
      default:
        break;
    }
  }
  void init() override{
    entity->addComponent<TransformComponent>((float)tileRect.x,(float)tileRect.y,tileRect.w,tileRect.h,1);
    transform = &entity->getComponent<TransformComponent>();

    entity->addComponent<SpriteComponent>(path);
    sprite = &entity->getComponent<SpriteComponent>();
  }
};
