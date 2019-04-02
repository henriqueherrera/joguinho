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
int SCREEN_HEIGHT = 700;
int mainTimer;
int count = 0,count_mov_personagem = -1, count_mov_cenario = -1 ;
int coordenada_y[18] = {500,500,500,600,600,600,500,600,600,600,500,300,300,300,
	300,300,500,600};

double gravidade = 8.80665;
double F;
double m = 300;
double M = 30;
double r;

bool cima = false, pulo  = false, esquerda = false, direita = false, create_run = false;
bool close = false;

char WINDOW_NAME[32] = "JOGO";

sprite background[3], walk, ground[18];

void delay( void )
{
        while( !close )
        {
                std::this_thread::sleep_for(chrono::milliseconds(50));
		count_mov_personagem++;
		if(count_mov_personagem == 15 )
               	{
                     	count_mov_personagem = 0;
              	}
        	walk.rect.y +=5; 

        }
}
void delay_background(void)
{
	 while(!close)
        {
                std::this_thread::sleep_for(chrono::milliseconds(30));
          

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

void set_movimentacao( void )
{
	walk.loadWalk(renderer);
        walk.y = 365 ;
	walk.x = 300; 
	walk.rect.w = 150;
	walk.rect.h = 150;
	walk.rect.x = walk.x;
	walk.rect.y = walk.y;
	walk.vel = 5;
}

void set_ground( void )
{
	for( int i = 0; i<18; i++)
	{
		ground[i].loadGround(renderer);
		ground[i].x = 0;
		ground[i].y = coordenada_y[i] ;
		ground[i].rect.w = 100;
		ground[i].rect.h = 100;
		ground[i].rect.x = ground[i].x;
		ground[i].rect.y = ground[i].y;
	}
}

void set_background( void )
{
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
			
		background[i].y = 0;
                background[i].rect.w = background[i].w;
                background[i].rect.h = background[i].h;
                background[i].rect.x = background[i].x;
                background[i].rect.y = background[i].y;				
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
				        set_movimentacao();                       
					set_background();
					
					set_ground();
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
                                case SDLK_SPACE:
                                        pulo = true;
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
                                case SDLK_SPACE:
                                        pulo = false;
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
                        if(pulo){
                                walk.rect.y -= 50;
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
}

void colisoes(int y)
{
	if(walk.rect.y+133 >= y)
	{
		walk.rect.y = y-133 ;
	}
	
}
//gera as imagens
void fase_1(void)
{

	SDL_RenderCopy(renderer, ground[0].ground[0], NULL, &ground[0].rect);	
	SDL_RenderCopy(renderer, ground[7].ground[7], NULL, &ground[7].rect);
	for(int i  = 1; i<20; i++)
	{
		ground[1].rect.x = 100*i;
		ground[4].rect.x = 100*i;
	
		SDL_RenderCopy(renderer, ground[1].ground[1], NULL, &ground[1].rect);
		SDL_RenderCopy(renderer, ground[4].ground[4], NULL, &ground[4].rect);
	}
	cout<<"y personagem"<<walk.rect.y<<endl;
	cout<<ground[1].rect.y<<endl;
}
void blit(void)
{
	colisoes(ground[1].rect.y);
	colisoes(ground[4].rect.y);
	
        SDL_RenderClear(renderer);
	
	SDL_RenderCopy(renderer, background[0].texture, NULL, &background[0].rect);
	SDL_RenderCopy(renderer, background[1].texture, NULL, &background[1].rect);    
	SDL_RenderCopy(renderer, background[2].texture, NULL, &background[2].rect);
    	
	if(direita)
	{
		SDL_RenderCopy(renderer, walk.run[count_mov_personagem], NULL, &walk.rect);
   	;
	}
	else
	{
		SDL_RenderCopy(renderer, walk.walk[count_mov_personagem], NULL, &walk.rect);
	}
	fase_1();
	SDL_RenderPresent(renderer);
}
	

//roda as funções principais

void tique()
{
	comportamento();
}

int main(int argc, char *argv[])
{

	thread delay_1(delay);
	thread delay_2(delay_background);
        set_all();       
        
	int mainTimer = SDL_GetTicks(); 
	while(!close)
        {
	
		thread blitt(blit);
 		tique();
		blitt.join();
	}
	delay_1.join();
	delay_2.join();

        SDL_DestroyWindow(window);
        SDL_Quit();
	
        return 0;
}

