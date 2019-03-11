//version 1.1
//compile g++ file.cpp `pkg-config --cflags --libs sdl2`

#include <iostream>
#include "SDL.h"
#include <vector>

using namespace std;

//função principal do jogo.
int main ( int argc, char *argv[] )
{
	SDL_Init( SDL_INIT_EVERYTHING); //inicia biblioteca SDL.
	
	SDL_Window *window = NULL; //cria janela do jogo

	SDL_Surface *surface = NULL; //fundo de tela da janela
	
	SDL_Event event;

	bool close = false;
	
	int window_width = 800, window_height = 600; //largura e altura

	int R = 0, G = 0, B = 0; //cores

	int windowCounter = 0; //contador

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		cout<< "Erro ao tentar inicializar video" << SDL_GetError() << endl;
	}

	else
	{
		window = SDL_CreateWindow( "Nome indefinido", 
					SDL_WINDOWPOS_UNDEFINED, 
					SDL_WINDOWPOS_UNDEFINED, 
					window_width, window_height, 
					SDL_WINDOW_RESIZABLE );
	
		if ( window == NULL )
		{
			cout << "Erro ao tentar inicializar janela" << endl <<
		       	SDL_GetError() << endl;
		}

		else
		{
			surface = SDL_GetWindowSurface( window );
		}
	}
	//laço de repetição que roda o game
	while ( !close )
	{
		while ( SDL_PollEvent ( &event ) != 0)
		{
			if( event.type == SDL_QUIT )
			{
				close = true;
			}

			if( event.type == SDL_KEYDOWN)
			{
				switch(event.key.keysym.sym)
				{
					case SDLK_SPACE:
						R = rand()%255 + 0;
						G = rand()%255 + 0;
						B = rand()%255 + 0;
						break;
					default:
						break;
				}
			
			}
		}
		
		SDL_FillRect( surface, NULL, SDL_MapRGB( surface -> format, R, G, B));
		SDL_UpdateWindowSurface( window );//atualiza a tela
	}
	
	SDL_DestroyWindow( window ); //limpar da memória
	SDL_Quit( );//fecha a janela
	return 0;
}
