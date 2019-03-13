#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sprite.h"
#include <vector>
#include <string.h>
using namespace std;
SDL_Window *window;
SDL_Renderer *renderer, *renderer1;
SDL_Event Event;
 
int SCREEN_WIDTH = 1000;
int SCREEN_HEIGHT = 750;
int mainTimer,run = 0;
bool cima = false, baixo = false, esquerda = false, direita = false, create_run = false;
char WINDOW_NAME[32] = "JOGO";
sprite background[3];

void back()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
		std::cout << SDL_GetError() << std::endl;
        } else {
                window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
                if(window == NULL){
                        cout << SDL_GetError() << endl;
                } else {
                        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if(renderer == NULL){
                                std::cout << SDL_GetError() << std::endl;
                        } else {
                                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
                                int IMG_FLAGS = IMG_INIT_PNG;
                                if(!(IMG_Init(IMG_FLAGS) & IMG_FLAGS)){
                                        std::cout << IMG_GetError() << std::endl;
                                } else {
					for(int i = 0; i < 3; i++)
					{
                                        	background[i].texture = IMG_LoadTexture(renderer, "./BG.png");
                                       	 	SDL_QueryTexture(background[i].texture, NULL, NULL, &background[i].w, &background[i].h);
                                        	background[i].x = 1000*i;
                                        	background[i].y = 0;
                                        	background[i].rect.w = background[i].w;
                                        	background[i].rect.h = background[i].h;
                                        	background[i].rect.x = background[i].x;
                                        	background[i].rect.y = background[i].y;
                                        	background[i].velocity = 20;
					}
	

                                }
                        }
                }
        }

}
//função que move o fundo da tela
void movBackground()
{
	for(int i  = 0; i<3; i++)
	{
 		background[i].rect.x -= 1;
		if(background[2].rect.x == 0)
		{
		
			background[0].rect.x = 0 ;
			background[1].rect.x = 1000;
			background[2].rect.x = 2000;
		}
	}
 
}
//gera as imagens
blit(void)
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background[0].texture, NULL, &background[0].rect);
    SDL_RenderCopy(renderer, background[1].texture, NULL, &background[1].rect);
    SDL_RenderCopy(renderer, background[2].texture, NULL, &background[2].rect);
	
    SDL_RenderPresent(renderer);

}
void tique()
{
        movBackground();
        blit();
        
}


int main(int argc, char *argv[])
{

        back();       
 	
        mainTimer = SDL_GetTicks();
        bool close = false;
        while(!close)
        {
                while(SDL_PollEvent(&Event) != 0)
                {
                        if(Event.type == SDL_QUIT)
                        {
                                close = true;
                        }
                        if(Event.type == SDL_KEYDOWN)
                        {
                                switch(Event.key.keysym.sym)
                                {
                                case SDLK_w:
                                        cima = true;
                                        break;
                                case SDLK_a:
                                        esquerda = true;
                                        break;
                                case SDLK_s:
                                        baixo = true;
                                        break;
                                case SDLK_d:
                                        direita = true;
                                        break;
                                default:
                                        break;
                                }
                        }
                        if(Event.type == SDL_KEYUP)
                        {
                                switch(Event.key.keysym.sym)
                                {
                                case SDLK_w:
                                        cima = false;
                                        break;
                                case SDLK_a:
                                        esquerda = false;
                                        break;
                                case SDLK_s:
                                        baixo = false;
                                        break;
                                case SDLK_d:
                                        direita = false;
                                        break;
                                default:
                                        break;
                                }
                        }
                }
 
                /*if(mainTimer + 10 < SDL_GetTicks()){
                        if(cima){
                                player.rect.y -= player.velocity;
                        }
                        if(baixo){
                                player.rect.y += player.velocity;
                        }
                        if(esquerda){
                                player.rect.x -= player.velocity;
                        }
                        if(direita){
                                player.rect.x += player.velocity;
                        }
                        mainTimer = SDL_GetTicks();
                }*/
		if(mainTimer +5 < SDL_GetTicks())
		{
			tique();//gera a parte grafica			
			mainTimer = SDL_GetTicks();
			

		}
        }
 
        SDL_DestroyWindow(window);
        SDL_Quit();
 
        return 0;
}
