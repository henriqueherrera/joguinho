#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "sprite.h"

using namespace std;
SDL_Window *window = NULL; //Cria a janela do jogo
SDL_Renderer *renderer = NULL; //Renderização
SDL_Event event; //Eventos do jogo

int SCREEN_WIDTH = 1024; //Largura da Tela
int SCREEN_HEIGHT = 768;
int mainTimer;

int main( int argc, char *argv[] )
{
	mainTimer = SDL_GetTicks();
	bool close = false;
        sprite player; 
	bool up = false, down = false, left = false, right = false;
	if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
	{
		cout <<  SDL_GetError() << endl;
	}
	else
	{
		window = SDL_CreateWindow( "Ainda não definido ",
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					SCREEN_WIDTH,
					SCREEN_HEIGHT,
					SDL_WINDOW_OPENGL       );
		if( window = NULL)
		{
			cout<< SDL_GetError << endl;
		}
		else
		{
			renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);
			if( renderer = NULL)
			{
				cout << SDL_GetError() << endl;
			}
			else
			{
				SDL_SetRenderDrawColor( renderer, 0, 0, 255, 0);

				int IMG_FLAGS = IMG_INIT_PNG;

				if( !(IMG_Init( IMG_FLAGS ) & IMG_FLAGS))
				{
					cout << IMG_GetError() << endl;
				}
				else
				{
					player.texture = IMG_LoadTexture( renderer, "~/workspace/joguinho/fototest.png");
					SDL_QueryTexture( player.texture, NULL, NULL, &player.w, &player.h);
					player.x = 10;
					player.y = 10;
					player.rect.w = player.w;
					player.rect.h = player.h;
					player.rect.x = player.x; 
					player.rect.y = player.y; 						    
			      		player.vel = 20;
				}
			}
		}
	}
		
	while(!close){
                while(SDL_PollEvent(&event) != 0){
                        if(event.type == SDL_QUIT){
                                close = true;
                        }
                        if(event.type == SDL_KEYDOWN){
                                switch(event.key.keysym.sym){
                                case SDLK_w:
                                        up = true;
                                        break;
                                case SDLK_a:
                                        left = true;
                                        break;
                                case SDLK_s:
                                        down = true;
                                        break;
                                case SDLK_d:
                                        right = true;
                                        break;
                                default:
                                        break;
                                }
                        }
                        if(event.type == SDL_KEYUP){
                                switch(event.key.keysym.sym){
                                case SDLK_w:
                                        up = false;
                                        break;
                                case SDLK_a:
                                        left = false;
                                        break;
                                case SDLK_s:
                                        down = false;
                                        break;
                                case SDLK_d:
                                        right = false;
                                        break;
                                default:
                                        break;
                                }
                        }
                }

                if(mainTimer + 10 < SDL_GetTicks()){
                        if(up){
                                player.rect.y -= player.vel;
                        }
                        if(down){
                                player.rect.y += player.vel;
                        }
                        if(left){
                                player.rect.x -= player.vel;
                        }
                        if(right){
                                player.rect.x += player.vel;
                        }
                        mainTimer = SDL_GetTicks();
                }

                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, player.texture, NULL, &player.rect);
                SDL_RenderPresent(renderer);
        }

        SDL_DestroyWindow(window);
        SDL_Quit();

        return 0;
}


