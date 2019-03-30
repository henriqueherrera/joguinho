#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sprite.h"
#include <vector>
#include <string.h>
#include <SDL2/SDL_ttf.h>
#include <thread>
#include <chrono>
using namespace std;

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event Event;
 
TTF_Font *font;

int style;
int SCREEN_WIDTH = 1000;
int SCREEN_HEIGHT = 750;
int mainTimer;
int count = 0,count_mov_personagem = -1, count_mov_cenario = -1 ;


bool cima = false, baixo = false, esquerda = false, direita = false, create_run = false;
bool close = false;

char WINDOW_NAME[32] = "JOGO";

sprite background[3],
       walk
       //walk[],
       //dead[],
;

void delay(void)
{
        while(!close)
        {
                std::this_thread::sleep_for(chrono::milliseconds(25));
		count_mov_personagem++;
		if(count_mov_personagem == 15 )
               	{
                     	count_mov_personagem = 0;
              	}
        }
}
void delay_background(void)
{
	 while(!close)
        {
                std::this_thread::sleep_for(chrono::milliseconds(5));
          

		for(int i  = 0; i<3; i++)
		{
 			background[i].rect.x -=1 ;
			if(background[2].rect.x == 0)
			{
		
				background[0].rect.x = 0 ;
				background[1].rect.x = 1280;
				background[2].rect.x  = 2560;
			}
		}

	}
}

//cria imagens na tela
void set_all()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << SDL_GetError() << endl;
        } else 
	{
                window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);
                if(window == NULL)
		{
                        cout << SDL_GetError() << endl;
                }
	       	else 
		{
                        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if(renderer == NULL)
			{
                                cout << SDL_GetError() << endl;
                        } else 
			{
                                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
                                int IMG_FLAGS = IMG_INIT_PNG;
                                if(!(IMG_Init(IMG_FLAGS) & IMG_FLAGS))
				{
                                        std::cout << IMG_GetError() << std::endl;
                                }
			       	else 
				{
					walk.loadWalk(renderer);
                                        walk.y = 300;
					walk.x = 300; 
					walk.rect.w = 150;
					walk.rect.h = 150;
					walk.rect.x = walk.x;
					walk.rect.y = walk.y;
					walk.vel = 10;                               
					for(int i = 0; i < 3; i++)
					{
                                        	if  ( (i == 0) || ( i == 2) )
						{
							background[i].texture = IMG_LoadTexture(renderer, "./fundo1.png");
                                       	 		SDL_QueryTexture(background[i].texture, NULL, NULL, &background[i].w, &background[i].h);
                                        		background[i].x = 1260*i;
						}
						if (i == 1)
						{
							background[i].texture = IMG_LoadTexture(renderer, "./fundo2.png");
                                       	 		SDL_QueryTexture(background[i].texture, NULL, NULL, &background[i].w, &background[i].h);
                                        		background[i].x = 1260*i;
						}
						//background[i].loadWalk(renderer);	
						background[i].y = 0;
                                        	background[i].rect.w = background[i].w;
                                        	background[i].rect.h = background[i].h;
                                        	background[i].rect.x = background[i].x;
                                        	background[i].rect.y = background[i].y;
                                        //	background[i].velocity = 20;
						
					}
				}
                        }
                }
	}
}

void comportamento(void)
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

    					SDL_RenderCopy(renderer, walk.run[count_mov_personagem], NULL, &walk.rect);
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
			
               if(mainTimer + 10 < SDL_GetTicks()){
                        if(cima){
                                walk.rect.y -= walk.vel;
                        }
                        if(baixo){
                                walk.rect.y += walk.vel;
                        }
                        if(esquerda){
                                walk.rect.x -= walk.vel;
                        }
                        if(direita){
				
                                walk.rect.x += walk.vel;
                        }
			
             
		    
                        mainTimer = SDL_GetTicks();
	       }
	
	}

	SDL_RenderCopy(renderer, walk.walk[count_mov_personagem], NULL, &walk.rect);
	
}
//gera as imagens
void blit(void)
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background[0].texture, NULL, &background[0].rect);
    SDL_RenderCopy(renderer, background[1].texture, NULL, &background[1].rect);    
    SDL_RenderCopy(renderer, background[2].texture, NULL, &background[2].rect);
    comportamento();    
   // SDL_RenderCopy(renderer, walk.walk[count_mov_personagem], NULL, &walk.rect);
    SDL_RenderPresent(renderer);
}

//roda as funções principais

void tique()
{
	blit();
}

int main(int argc, char *argv[])
{

	thread delay_1(delay);
	thread delay_2(delay_background);
        set_all();       
        
	int mainTimer = SDL_GetTicks(); 
	while(!close)
        {
 		tique();
	}
	delay_1.join();
	delay_2.join();
        SDL_DestroyWindow(window);
        SDL_Quit();
	
        return 0;
}
