#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

class sprite
{
	public:
		sprite(void);
		~sprite(void);
			
		SDL_Texture *texture, *walk[15], *dead[15], *run[15], *idle[15], *jump[15], *ground[18];
		SDL_Rect rect;
		
		void loadWalk( SDL_Renderer *renderer );	
		void loadGround( SDL_Renderer *renderer );
		
		int x;
		int y;
		int w;
		int h;
		int vel;	
		
};
