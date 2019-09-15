#pragma once
#include <SDL2/SDL.h>

class Inv{
private:
  	SDL_Window *win;
   SDL_Renderer *ren;
   bool isRunning;
   bool pause;
   int FPS;
   Uint32 frameDelay;
   int frameMax; //???
   int frame;
   int frameCount;
   int frameStart;
   int alphaseeker;
   int alphaseeker2;
   int alphaseeker3;
   SDL_Event e;
public:
	Inv();
	~Inv();
	int run(); 
	int update(); // ???
	int cleanup();
	int event();
	int render();
};