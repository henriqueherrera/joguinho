#include "sprite.h"
sprite::sprite()
{

}

sprite::~sprite()
{

}

void sprite::loadWalk( SDL_Renderer *renderer)
{
	this->walk[0] = IMG_LoadTexture(renderer, "./boneco/Walk (1).png");
	SDL_QueryTexture( this->walk[0], NULL, NULL, &(this->w),&(this->h));

	this->walk[1] = IMG_LoadTexture(renderer, "./boneco/Walk (2).png");
	SDL_QueryTexture( this->walk[1], NULL, NULL, &(this->w), &(this->h));

	this->walk[2] = IMG_LoadTexture(renderer, "./boneco/Walk (3).png");
	SDL_QueryTexture( this->walk[2], NULL, NULL, &(this->w), &(this->h));

	this->walk[3] = IMG_LoadTexture(renderer, "./boneco/Walk (4).png");
	SDL_QueryTexture( this->walk[3], NULL, NULL, &(this->w), &(this->h));

	this->walk[4] = IMG_LoadTexture(renderer, "./boneco/Walk (5).png");
	SDL_QueryTexture( this->walk[4], NULL, NULL, &(this->w), &(this->h));

	this->walk[5] = IMG_LoadTexture(renderer, "./boneco/Walk (6).png");
	SDL_QueryTexture( this->walk[5], NULL, NULL, &(this->w), &(this->h));

	this->walk[6] = IMG_LoadTexture(renderer, "./boneco/Walk (7).png");
	SDL_QueryTexture( this->walk[6], NULL, NULL, &(this->w), &(this->h));

	this->walk[7] = IMG_LoadTexture(renderer, "./boneco/Walk (8).png");
	SDL_QueryTexture( this->walk[7], NULL, NULL, &(this->w), &(this->h));

	this->walk[8] = IMG_LoadTexture(renderer, "./boneco/Walk (9).png");
	SDL_QueryTexture( this->walk[8], NULL, NULL, &(this->w), &(this->h));

	this->walk[9] = IMG_LoadTexture(renderer, "./boneco/Walk (10).png");
	SDL_QueryTexture( this->walk[9], NULL, NULL, &(this->w), &(this->h));

	this->walk[10] = IMG_LoadTexture(renderer, "./boneco/Walk (11).png");
	SDL_QueryTexture( this->walk[10], NULL, NULL, &(this->w), &(this->h));

	this->walk[11] = IMG_LoadTexture(renderer, "./boneco/Walk (12).png");
	SDL_QueryTexture( this->walk[11], NULL, NULL, &(this->w), &(this->h));

	this->walk[12] = IMG_LoadTexture(renderer, "./boneco/Walk (13).png");
	SDL_QueryTexture( this->walk[12], NULL, NULL, &(this->w), &(this->h));

	this->walk[13] = IMG_LoadTexture(renderer, "./boneco/Walk (14).png");
	SDL_QueryTexture( this->walk[13], NULL, NULL, &(this->w), &(this->h));

	this->walk[14] = IMG_LoadTexture(renderer, "./boneco/Walk (15).png");
	SDL_QueryTexture( this->walk[14], NULL, NULL, &(this->w), &(this->h));


}


