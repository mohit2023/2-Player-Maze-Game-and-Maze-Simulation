#include "../include/Game.h"
#include "../include/TextureManager.h"
#include "../include/Components.h"
#include "../include/Map.h"
#include "../include/Vector2D.h"
#include "../include/GameObject.h"
#include "../include/TimerComponent.h"
#include "SDL_ttf.h"

using namespace std;

SDL_Renderer* Game::renderer = nullptr;

GameObject* player1;
GameObject* player2;

TimerComponent* timer;

//Map* map;
//Manager manager;
//auto& player(manager.addEntity());

Game::Game(Maze& maze){
	MazeMap = maze.mazeToMap();
}
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
    if(TTF_Init() == -1) {
    	cout<<"Some error\n";
    }
    isRunning = true;
  }
  else{
    isRunning = false;
  }
  //map = new Map();

  // SDL_Surface* tmpSurface = SDL_LoadBMP("MAZE_10x10_n64.bmp");
  // playerTex = TextureManager::LoadTexture("MAZE_10x10_n64.bmp",renderer);
  player1 = new GameObject("assets/Clyde.bmp",205,105);
  player2 = new GameObject("assets/Pinky.bmp",570,470);
  //player.addComponent<TransformComponent>(150.0,50.0);
  //player.addComponent<SpriteComponent>("assets/Clyde.bmp");
  // newPlayer.getComponent<PositionComponent>();
  // SDL_FreeSurface(tmpSurface);
  
  timer = new TimerComponent(SDL_GetTicks());
}
void Game::handleEvents(){
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type) {
	case SDL_QUIT:
	  isRunning = false;
	  break;
	case SDL_KEYUP:
	  processInput(event);
	  break; 
	default:
	  break;
  }
  
  if(timer->timeRemaining() <= 0){
    isRunning = false;
  }  
}
void Game::processInput(SDL_Event event){
	switch(event.key.keysym.sym){
		case SDLK_UP:
			player1->move = MOVE_UP;
			break;
		case SDLK_RIGHT:
			player1->move = MOVE_RIGHT;
			break;
		case SDLK_DOWN:
			player1->move = MOVE_DOWN;
			break;
		case SDLK_LEFT:
			player1->move = MOVE_LEFT;
			break;
		case SDLK_w:
			player2->move = MOVE_UP;
			break;
		case SDLK_d:
			player2->move = MOVE_RIGHT;
			break;
		case SDLK_s:
			player2->move = MOVE_DOWN;
			break;
		case SDLK_a:
			player2->move = MOVE_LEFT;
			break;
		default:
			break;
	}
}
void reversePlayerMove(GameObject* player){
	if(player->move == MOVE_UP){
		player->move=MOVE_DOWN;
	}
	else if(player->move == MOVE_DOWN){
		player->move=MOVE_UP;
	}
	else if(player->move == MOVE_LEFT){
		player->move=MOVE_RIGHT;
	}
	else if(player->move == MOVE_RIGHT){
		player->move=MOVE_LEFT;
	}
}
void resolvePlayerCollision(GameObject* player1,GameObject* player2){
	if(player2->xpos+25 <= player1->xpos){
		return ;
	}
	if(player2->xpos >= player1->xpos+25){
		return ;
	}
	if(player2->ypos+25 <= player1->ypos){
		return ;
	}
	if(player2->ypos >= player1->ypos+25){
		return ;
	}
	
	reversePlayerMove(player1);
	reversePlayerMove(player2);
}
void Game::update(){
  // player1->Update();
  // player2->Update();
  player1->Update(MazeMap,1);
  player2->Update(MazeMap,2);
  resolvePlayerCollision(player1,player2);
  //manager.refresh();
  //manager.update();
  //player.getComponent<TransformComponent>().position.Add(Vector2D(1,0));
  // cout<<newPlayer.getComponent<PositionComponent>().x()<<","<<newPlayer.getComponent<PositionComponent>().y()<< endl;
  // cout<<cnt<<endl;
  //if(player.getComponent<TransformComponent>().position.x > 200){
  //  player.getComponent<SpriteComponent>().setTex("assets/Pinky.bmp");
  //}
  timer->Update(SDL_GetTicks());
}
void Game::drawMaze(){
	int x=200;
	int y=100;
	
	for(int i=0;i<10;i++){
		x=200;
		for(int j=0;j<10;j++){
			SDL_Rect r;
			r.x=x;
			r.y=y;
			r.h=40;
			r.w=40;
			
			if(MazeMap[i][j][0]==0){
				SDL_SetRenderDrawColor(renderer,255,255,255,255); //white
			}
			else if(MazeMap[i][j][0]==1){
				SDL_SetRenderDrawColor(renderer,0,0,255,255); //blue
			}
			else{
				SDL_SetRenderDrawColor(renderer,144,238,144,144);	//green
			}
			SDL_RenderFillRect(renderer,&r);
			
			if(MazeMap[i][j][1]){
				SDL_Rect br;
				br.x=x;
				br.y=y;
				br.h=2;
				br.w=40;
				SDL_SetRenderDrawColor(renderer,255,105,42,42); //reddish-brown
				SDL_RenderFillRect(renderer,&br);
			}
			
			if(MazeMap[i][j][2]){
				SDL_Rect br;
				br.x=x;
				br.y=y;
				br.h=40;
				br.w=2;
				SDL_SetRenderDrawColor(renderer,255,105,42,42); //reddish-brown
				SDL_RenderFillRect(renderer,&br);
			}
			
			
			x+=40;
		}
		y+=40;
	}
	x=200;
	y=100;
	
	SDL_Rect br;
	br.x=x;
	br.y=y;
	br.h=2;
	br.w=400;
	SDL_SetRenderDrawColor(renderer,255,105,42,42); //reddish-brown
	SDL_RenderFillRect(renderer,&br);
	br.x=x;
	br.y=y;
	br.h=400;
	br.w=2;
	SDL_SetRenderDrawColor(renderer,255,105,42,42); //reddish-brown
	SDL_RenderFillRect(renderer,&br);
	br.x=x+400;
	br.y=y;
	br.h=400;
	br.w=2;
	SDL_SetRenderDrawColor(renderer,255,105,42,42); //reddish-brown
	SDL_RenderFillRect(renderer,&br);
	br.x=x;
	br.y=y+400;
	br.h=2;
	br.w=400;
	SDL_SetRenderDrawColor(renderer,255,105,42,42); //reddish-brown
	SDL_RenderFillRect(renderer,&br);
}
void Game::render(){
  SDL_SetRenderDrawColor(renderer, 238, 232, 125, 255);
  SDL_RenderClear(renderer);
  timer->Render();
  //SDL_RenderPresent(renderer);
  //manager.draw();
  drawMaze();
  // Add stuff to renderer
  //map->DrawMap();
  // SDL_RenderCopy(renderer,playerTex, NULL, &destR);
  player1->Render();
  player2->Render();
  SDL_RenderPresent(renderer);
}
void Game::clean(){
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  cout<<"Game Cleaned"<<endl;
}
