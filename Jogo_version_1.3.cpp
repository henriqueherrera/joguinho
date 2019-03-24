#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sprite.h"
#include <vector>
#include <string.h>
#include <SDL2/SDL_ttf.h>

using namespace std;

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event Event;
 
TTF_Font *font;

int style;
int SCREEN_WIDTH = 1000;
int SCREEN_HEIGHT = 750;
int mainTimer;
int count = 0;
bool cima = false, baixo = false, esquerda = false, direita = false, create_run = false;

char WINDOW_NAME[32] = "JOGO";


sprite background[3],
       walk
       //walk[],
       //dead[],
;


/*void txt_screen()
{
	if(TTF_Init() == -1)//if
	{
		cout<<"TTF_Init" << TTF_GetError()<<endl;
	}
	else
	{
		style = TTF_GetFontStyle(font);
	       	cout <<"The fonte style is:"<<endl;
		if( style == TTF_STYLE_NORMAL)
		{
			cout<< "normal" << endl;
		}	
	}
}*/
void back()
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
                                        		background[i].x = 1280*i;
						}
						if (i == 1)
						{
							background[i].texture = IMG_LoadTexture(renderer, "./fundo2.png");
                                       	 		SDL_QueryTexture(background[i].texture, NULL, NULL, &background[i].w, &background[i].h);
                                        		background[i].x = 1280*i;
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
//função que move o fundo da telavoid movBackground()
void movBackground()
{
	for(int i  = 0; i<3; i++)
	{
 		background[i].rect.x -= 1;
		if(background[2].rect.x == 0)
		{
		
			background[0].rect.x = 0 ;
			background[1].rect.x = 1280;
			background[2].rect.x  = 2560;
		}
	}
 
}
//gera as imagens

void blit(void)
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background[0].texture, NULL, &background[0].rect);
    SDL_RenderCopy(renderer, background[1].texture, NULL, &background[1].rect);
   // SDL_RenderCopy(renderer, background[1].walk, NULL, &background[1].rect);
	
    SDL_RenderCopy(renderer, background[2].texture, NULL, &background[2].rect);
    SDL_RenderCopy(renderer, walk.walk[count], NULL, &walk.rect);
    SDL_RenderPresent(renderer);

    if ( count == 14)
    {
    	count = -1;
    }
}
void controle()
{
}

//roda as funções principais

void tique()
{
	//txt_screen();
	blit();
	
	movBackground();
        


        
}

int main(int argc, char *argv[])
{

        back();       
 	
        int mainTimer = SDL_GetTicks();
        int sprite_tick = SDL_GetTicks();
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
	
	if(mainTimer +10 < SDL_GetTicks())
	{
		tique();//gera a parte grafica			
		mainTimer = SDL_GetTicks();
		count++;
	}
	}
        SDL_DestroyWindow(window);
        SDL_Quit();
 
        return 0;
}
