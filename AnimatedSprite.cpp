#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(){
	frame = 0;
	flip = SDL_FLIP_NONE;
}


void AnimatedSprite::setSources(int type){
	switch(type){
		case PLAYER:
			walkSource[0].x = 21; 
			walkSource[0].y = 194; 
			walkSource[0].w = 39;
			walkSource[0].h = 69;
			walkSource[1].x = 123;
			walkSource[1].y = 193;
			walkSource[1].w = 39;
			walkSource[1].h = 65;
			walkSource[2] = walkSource[0];
			walkSource[3] = walkSource[1];
			walkSource[4] = walkSource[0];
			walkSource[5] = walkSource[1];
			walkSource[6] = walkSource[0];
			walkSource[7] = walkSource[1];
			standSource[0].x = 427;
			standSource[0].y = 193;
			standSource[0].w = 39;
			standSource[0].h = 69;

			jumpSource[0].x = 425;
			jumpSource[0].y = 289;
			jumpSource[0].w = 39;
			jumpSource[0].h = 69;
			break;
	}
}

void AnimatedSprite::updateFrame(){
	frame++;
	if(frame >= NUM_FRAMES){
		frame = 0;
	}
	switch(getState()){
		case WALKING: 
			source = walkSource[frame];
			break;
		case STANDING: 
			source = standSource[0];
			break;
		case JUMPING:	
			source = jumpSource[0];
			break;
	}
	
}
