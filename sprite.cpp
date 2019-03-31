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

	//run
	
	this->run[0] = IMG_LoadTexture(renderer, "./boneco/Run (1).png");
	SDL_QueryTexture( this->walk[0], NULL, NULL, &(this->w),&(this->h));

	this->run[1] = IMG_LoadTexture(renderer, "./boneco/Run (2).png");
	SDL_QueryTexture( this->walk[1], NULL, NULL, &(this->w), &(this->h));

	this->run[2] = IMG_LoadTexture(renderer, "./boneco/Run (3).png");
	SDL_QueryTexture( this->walk[2], NULL, NULL, &(this->w), &(this->h));

	this->run[3] = IMG_LoadTexture(renderer, "./boneco/Run (4).png");
	SDL_QueryTexture( this->walk[3], NULL, NULL, &(this->w), &(this->h));

	this->run[4] = IMG_LoadTexture(renderer, "./boneco/Run (5).png");
	SDL_QueryTexture( this->walk[4], NULL, NULL, &(this->w), &(this->h));

	this->run[5] = IMG_LoadTexture(renderer, "./boneco/Run (6).png");
	SDL_QueryTexture( this->walk[5], NULL, NULL, &(this->w), &(this->h));

	this->run[6] = IMG_LoadTexture(renderer, "./boneco/Run (7).png");
	SDL_QueryTexture( this->walk[6], NULL, NULL, &(this->w), &(this->h));

	this->run[7] = IMG_LoadTexture(renderer, "./boneco/Run (8).png");
	SDL_QueryTexture( this->walk[7], NULL, NULL, &(this->w), &(this->h));

	this->run[8] = IMG_LoadTexture(renderer, "./boneco/Run (9).png");
	SDL_QueryTexture( this->walk[8], NULL, NULL, &(this->w), &(this->h));

	this->run[9] = IMG_LoadTexture(renderer, "./boneco/Run (10).png");
	SDL_QueryTexture( this->walk[9], NULL, NULL, &(this->w), &(this->h));

	this->run[10] = IMG_LoadTexture(renderer, "./boneco/Run (11).png");
	SDL_QueryTexture( this->walk[10], NULL, NULL, &(this->w), &(this->h));

	this->run[11] = IMG_LoadTexture(renderer, "./boneco/Run (12).png");
	SDL_QueryTexture( this->walk[11], NULL, NULL, &(this->w), &(this->h));

	this->run[12] = IMG_LoadTexture(renderer, "./boneco/Run (13).png");
	SDL_QueryTexture( this->walk[12], NULL, NULL, &(this->w), &(this->h));

	this->run[13] = IMG_LoadTexture(renderer, "./boneco/Run (14).png");
	SDL_QueryTexture( this->walk[13], NULL, NULL, &(this->w), &(this->h));

	this->run[14] = IMG_LoadTexture(renderer, "./boneco/Run (15).png");
	SDL_QueryTexture( this->walk[14], NULL, NULL, &(this->w), &(this->h));
	
	//dead

	this->dead[0] = IMG_LoadTexture(renderer, "./boneco/Dead (1).png");
	SDL_QueryTexture( this->walk[0], NULL, NULL, &(this->w),&(this->h));

	this->dead[1] = IMG_LoadTexture(renderer, "./boneco/Dead (2).png");
	SDL_QueryTexture( this->walk[1], NULL, NULL, &(this->w), &(this->h));

	this->dead[2] = IMG_LoadTexture(renderer, "./boneco/Dead (3).png");
	SDL_QueryTexture( this->walk[2], NULL, NULL, &(this->w), &(this->h));

	this->dead[3] = IMG_LoadTexture(renderer, "./boneco/Dead (4).png");
	SDL_QueryTexture( this->walk[3], NULL, NULL, &(this->w), &(this->h));

	this->dead[4] = IMG_LoadTexture(renderer, "./boneco/Dead (5).png");
	SDL_QueryTexture( this->walk[4], NULL, NULL, &(this->w), &(this->h));

	this->dead[5] = IMG_LoadTexture(renderer, "./boneco/Dead (6).png");
	SDL_QueryTexture( this->walk[5], NULL, NULL, &(this->w), &(this->h));

	this->dead[6] = IMG_LoadTexture(renderer, "./boneco/Dead (7).png");
	SDL_QueryTexture( this->walk[6], NULL, NULL, &(this->w), &(this->h));

	this->dead[7] = IMG_LoadTexture(renderer, "./boneco/Dead (8).png");
	SDL_QueryTexture( this->walk[7], NULL, NULL, &(this->w), &(this->h));

	this->dead[8] = IMG_LoadTexture(renderer, "./boneco/Dead (9).png");
	SDL_QueryTexture( this->walk[8], NULL, NULL, &(this->w), &(this->h));

	this->dead[9] = IMG_LoadTexture(renderer, "./boneco/Dead (10).png");
	SDL_QueryTexture( this->walk[9], NULL, NULL, &(this->w), &(this->h));

	this->dead[10] = IMG_LoadTexture(renderer, "./boneco/Dead (11).png");
	SDL_QueryTexture( this->walk[10], NULL, NULL, &(this->w), &(this->h));

	this->dead[11] = IMG_LoadTexture(renderer, "./boneco/Dead (12).png");
	SDL_QueryTexture( this->walk[11], NULL, NULL, &(this->w), &(this->h));

	this->dead[12] = IMG_LoadTexture(renderer, "./boneco/Dead (13).png");
	SDL_QueryTexture( this->walk[12], NULL, NULL, &(this->w), &(this->h));

	this->dead[13] = IMG_LoadTexture(renderer, "./boneco/Dead (14).png");
	SDL_QueryTexture( this->walk[13], NULL, NULL, &(this->w), &(this->h));

	this->dead[14] = IMG_LoadTexture(renderer, "./boneco/Dead (15).png");
	SDL_QueryTexture( this->walk[14], NULL, NULL, &(this->w), &(this->h));

	//parado
	
	this->idle[0] = IMG_LoadTexture(renderer, "./boneco/Idle (1).png");
	SDL_QueryTexture( this->walk[0], NULL, NULL, &(this->w),&(this->h));

	this->idle[1] = IMG_LoadTexture(renderer, "./boneco/Idle (2).png");
	SDL_QueryTexture( this->walk[1], NULL, NULL, &(this->w), &(this->h));

	this->idle[2] = IMG_LoadTexture(renderer, "./boneco/Idle (3).png");
	SDL_QueryTexture( this->walk[2], NULL, NULL, &(this->w), &(this->h));

	this->idle[3] = IMG_LoadTexture(renderer, "./boneco/Idle (4).png");
	SDL_QueryTexture( this->walk[3], NULL, NULL, &(this->w), &(this->h));

	this->idle[4] = IMG_LoadTexture(renderer, "./boneco/Idle (5).png");
	SDL_QueryTexture( this->walk[4], NULL, NULL, &(this->w), &(this->h));

	this->idle[5] = IMG_LoadTexture(renderer, "./boneco/Idle (6).png");
	SDL_QueryTexture( this->walk[5], NULL, NULL, &(this->w), &(this->h));

	this->idle[6] = IMG_LoadTexture(renderer, "./boneco/Idle (7).png");
	SDL_QueryTexture( this->walk[6], NULL, NULL, &(this->w), &(this->h));

	this->idle[7] = IMG_LoadTexture(renderer, "./boneco/Idle (8).png");
	SDL_QueryTexture( this->walk[7], NULL, NULL, &(this->w), &(this->h));

	this->idle[8] = IMG_LoadTexture(renderer, "./boneco/Idle (9).png");
	SDL_QueryTexture( this->walk[8], NULL, NULL, &(this->w), &(this->h));

	this->idle[9] = IMG_LoadTexture(renderer, "./boneco/Idle (10).png");
	SDL_QueryTexture( this->walk[9], NULL, NULL, &(this->w), &(this->h));

	this->idle[10] = IMG_LoadTexture(renderer, "./boneco/Idle (11).png");
	SDL_QueryTexture( this->walk[10], NULL, NULL, &(this->w), &(this->h));

	this->idle[11] = IMG_LoadTexture(renderer, "./boneco/Idle (12).png");
	SDL_QueryTexture( this->walk[11], NULL, NULL, &(this->w), &(this->h));

	this->idle[12] = IMG_LoadTexture(renderer, "./boneco/Idle (13).png");
	SDL_QueryTexture( this->walk[12], NULL, NULL, &(this->w), &(this->h));

	this->idle[13] = IMG_LoadTexture(renderer, "./boneco/Idle (14).png");
	SDL_QueryTexture( this->walk[13], NULL, NULL, &(this->w), &(this->h));

	this->idle[14] = IMG_LoadTexture(renderer, "./boneco/Idle (15).png");
	SDL_QueryTexture( this->walk[14], NULL, NULL, &(this->w), &(this->h));


	//jump
	
	this->jump[0] = IMG_LoadTexture(renderer, "./boneco/Jump (1).png");
	SDL_QueryTexture( this->walk[0], NULL, NULL, &(this->w),&(this->h));

	this->jump[1] = IMG_LoadTexture(renderer, "./boneco/Jump (2).png");
	SDL_QueryTexture( this->walk[1], NULL, NULL, &(this->w), &(this->h));

	this->jump[2] = IMG_LoadTexture(renderer, "./boneco/Jump (3).png");
	SDL_QueryTexture( this->walk[2], NULL, NULL, &(this->w), &(this->h));

	this->jump[3] = IMG_LoadTexture(renderer, "./boneco/Jump (4).png");
	SDL_QueryTexture( this->walk[3], NULL, NULL, &(this->w), &(this->h));

	this->jump[4] = IMG_LoadTexture(renderer, "./boneco/Jump (5).png");
	SDL_QueryTexture( this->walk[4], NULL, NULL, &(this->w), &(this->h));

	this->jump[5] = IMG_LoadTexture(renderer, "./boneco/Jump (6).png");
	SDL_QueryTexture( this->walk[5], NULL, NULL, &(this->w), &(this->h));

	this->jump[6] = IMG_LoadTexture(renderer, "./boneco/Jump (7).png");
	SDL_QueryTexture( this->walk[6], NULL, NULL, &(this->w), &(this->h));

	this->jump[7] = IMG_LoadTexture(renderer, "./boneco/Jump (8).png");
	SDL_QueryTexture( this->walk[7], NULL, NULL, &(this->w), &(this->h));

	this->jump[8] = IMG_LoadTexture(renderer, "./boneco/Jump (9).png");
	SDL_QueryTexture( this->walk[8], NULL, NULL, &(this->w), &(this->h));

	this->jump[9] = IMG_LoadTexture(renderer, "./boneco/Jump (10).png");
	SDL_QueryTexture( this->walk[9], NULL, NULL, &(this->w), &(this->h));

	this->jump[10] = IMG_LoadTexture(renderer, "./boneco/Jump (11).png");
	SDL_QueryTexture( this->walk[10], NULL, NULL, &(this->w), &(this->h));

	this->jump[11] = IMG_LoadTexture(renderer, "./boneco/Jump (12).png");
	SDL_QueryTexture( this->walk[11], NULL, NULL, &(this->w), &(this->h));

	this->jump[12] = IMG_LoadTexture(renderer, "./boneco/Jump (13).png");
	SDL_QueryTexture( this->walk[12], NULL, NULL, &(this->w), &(this->h));

	this->jump[13] = IMG_LoadTexture(renderer, "./boneco/Jump (14).png");
	SDL_QueryTexture( this->walk[13], NULL, NULL, &(this->w), &(this->h));

	this->jump[14] = IMG_LoadTexture(renderer, "./boneco/Jump (15).png");
	SDL_QueryTexture( this->walk[14], NULL, NULL, &(this->w), &(this->h));
}

void sprite::loadGround( SDL_Renderer *renderer)
{
	this->ground[0] = IMG_LoadTexture(renderer, "./ground/1.png");
	SDL_QueryTexture( this->ground[0], NULL, NULL, &(this->w),&(this->h));

	this->ground[1] = IMG_LoadTexture(renderer, "./ground/2.png");
	SDL_QueryTexture( this->ground[1], NULL, NULL, &(this->w),&(this->h));

	this->ground[2] = IMG_LoadTexture(renderer, "./ground/3.png");
	SDL_QueryTexture( this->ground[2], NULL, NULL, &(this->w),&(this->h));

	this->ground[3] = IMG_LoadTexture(renderer, "./ground/4.png");
	SDL_QueryTexture( this->ground[3], NULL, NULL, &(this->w),&(this->h));

	this->ground[4] = IMG_LoadTexture(renderer, "./ground/5.png");
	SDL_QueryTexture( this->ground[4], NULL, NULL, &(this->w),&(this->h));

	this->ground[5] = IMG_LoadTexture(renderer, "./ground/6.png");
	SDL_QueryTexture( this->ground[5], NULL, NULL, &(this->w),&(this->h));
	
	this->ground[6] = IMG_LoadTexture(renderer, "./ground/7.png");
	SDL_QueryTexture( this->ground[6], NULL, NULL, &(this->w),&(this->h));
	
	this->ground[7] = IMG_LoadTexture(renderer, "./ground/8.png");
	SDL_QueryTexture( this->ground[7], NULL, NULL, &(this->w),&(this->h));
	
	this->ground[8] = IMG_LoadTexture(renderer, "./ground/9.png");
	SDL_QueryTexture( this->ground[8], NULL, NULL, &(this->w),&(this->h));

	this->ground[9] = IMG_LoadTexture(renderer, "./ground/10.png");
	SDL_QueryTexture( this->ground[9], NULL, NULL, &(this->w),&(this->h));

	this->ground[10] = IMG_LoadTexture(renderer, "./ground/11.png");
	SDL_QueryTexture( this->ground[10], NULL, NULL, &(this->w),&(this->h));

	this->ground[11] = IMG_LoadTexture(renderer, "./ground/12.png");
	SDL_QueryTexture( this->ground[11], NULL, NULL, &(this->w),&(this->h));

	this->ground[12] = IMG_LoadTexture(renderer, "./ground/13.png");
	SDL_QueryTexture( this->ground[12], NULL, NULL, &(this->w),&(this->h));

	this->ground[13] = IMG_LoadTexture(renderer, "./ground/14.png");
	SDL_QueryTexture( this->ground[13], NULL, NULL, &(this->w),&(this->h));

	this->ground[14] = IMG_LoadTexture(renderer, "./ground/15.png");
	SDL_QueryTexture( this->ground[14], NULL, NULL, &(this->w),&(this->h));

	this->ground[15] = IMG_LoadTexture(renderer, "./ground/16.png");
	SDL_QueryTexture( this->ground[15], NULL, NULL, &(this->w),&(this->h));

	this->ground[16] = IMG_LoadTexture(renderer, "./ground/17.png");
	SDL_QueryTexture( this->ground[16], NULL, NULL, &(this->w),&(this->h));

	this->ground[17] = IMG_LoadTexture(renderer, "./ground/18.png");
	SDL_QueryTexture( this->ground[17], NULL, NULL, &(this->w),&(this->h));
}

