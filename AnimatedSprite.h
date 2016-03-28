/*
	John F. Lake, Jr. 
	The key difference from the Sprite class is that this class has logic to alter the source rect to animate the sprite
*/
#include "Sprite.h"
#include "Constants.h"
#ifndef __ANIMATED_SPRITE__
#define __ANIMATED_SPRITE__

class AnimatedSprite : public Sprite{
	public: 
		AnimatedSprite();
		//Set all of the sources based on a particular character: 
		void setSources(int);
		void setFlip(SDL_RendererFlip f){flip = f;}
		SDL_RendererFlip getFlip(){return flip;}
		void updateFrame();
	protected: 
		int frame;
		int numFrames; 
		SDL_Rect walkSource[NUM_FRAMES];
		SDL_Rect standSource[1];
		SDL_Rect jumpSource[1];
		SDL_RendererFlip flip;
		
};


#endif
