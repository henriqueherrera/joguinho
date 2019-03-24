#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

class sprite
{
	public:
		sprite(void);
		~sprite(void);
		void test(void);	
		SDL_Texture *texture, *walk[15];
		SDL_Rect rect;
		void loadWalk( SDL_Renderer *renderer);	
		int x;
		int y;
		int w;
		int h;
		int vel;
};
