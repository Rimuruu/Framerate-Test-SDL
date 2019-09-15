#include "Inv.h"
#include <iostream>
using namespace std;
Inv::Inv(){
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "SDL not init" << endl;
    }
   win = SDL_CreateWindow("Framerate test SDL", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
   ren = SDL_CreateRenderer(win, -1,    SDL_RENDERER_ACCELERATED);
   isRunning = true;
   FPS = 60;
   frame = 1000/60;
   frameCount = 0;
   alphaseeker = 0;
   alphaseeker2 = 0;
   alphaseeker3 = 0;
   pause = false;

}

int Inv::run(){
		frameStart = SDL_GetTicks();
	while(isRunning){
		frameDelay=SDL_GetTicks();
		if (!pause)
		{
			render();
			
		}
		event();
		frameCount++;
		frameMax = SDL_GetTicks()-frameDelay; 
		
		if (frameMax<frame)
		{
			SDL_Delay(frame-frameMax);
		}
		//cout << "ticks : " << (SDL_GetTicks()-frameDelay) << endl;
		if (SDL_GetTicks()-frameStart>=1000)
		{
			frameStart=SDL_GetTicks();
			cout << "FPS : " << frameCount << " ticks :" << frame-frameMax << endl;
			frameCount=0;
		}
	}
	cleanup();
	SDL_Quit();
	cout << "SDL quit"<< endl;
	return 0;
}

int Inv::render(){
	SDL_SetRenderDrawColor( ren, 0, 0, 0, 255 );
	SDL_RenderClear(ren);
	bool coef = true;
	alphaseeker3=(alphaseeker3+10)%200;
	for (int y = 0; y < 600/40; ++y)
	{
		alphaseeker=(alphaseeker+10)%200;
		for (int i = 0; i < 800/40; ++i)
			
		
		{

			SDL_SetRenderDrawColor( ren, alphaseeker3, alphaseeker2, alphaseeker, 255);
			SDL_Rect r;
    		r.x = i*40;
    		r.y = y*40;
    		r.w = 40;
    		r.h = 40;
    		SDL_RenderFillRect( ren, &r );
    		alphaseeker2=(alphaseeker2+10)%200; // ^^
   
    		//cout << alphaseeker<< endl; 
    		
		}
		
		

	}
	
	
    SDL_RenderPresent(ren);

}

int Inv::cleanup(){
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	cout << "Cleanup done"<< endl;
	return 0;
}

int Inv::event(){
	while (SDL_PollEvent(&e)){
		if (e.type == SDL_QUIT){
			isRunning = false;
			break;
		}
		else if (e.type == SDL_KEYDOWN){
			switch(e.key.keysym.sym){
				case SDLK_SPACE:
					pause=!pause;
			}
		}
	
	}
	return 0;
}