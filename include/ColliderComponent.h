#pragma once

#include <string>
#include "SDL2/SDL.h"
#include "ECS.h"
#include "Components.h"

using namespace std;

class ColliderComponent : public Component{
public:
  SDL_Rect collider;
  string tag;
  ColliderComponent(string t){
    tag = t;
  }
  TransformComponent* transform;

  void init() override{
    if(!entity->hasComponent<TransformComponent>()){
      entity->addComponent<TransformComponent>();
    }
    transform = &entity->getComponent<TransformComponent>();
    Game::colliders.push_back(this);
  }
  void update() override{
    collider.x = static_cast<int>(transform->position.x);
    collider.y = static_cast<int>(transform->position.y);
    collider.w = transform->width * transform->scale;
    collider.h = transform->height * transform->scale;
  }
};
