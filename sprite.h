#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class sprite
{
	public:
		sprite(void);
		~sprite(void);

		SDL_Texture *texture;
		SDL_Rect rect;
		
		int x;
		int y;
		int w;
		int h;
		int vel;
};
