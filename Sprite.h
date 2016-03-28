/*
	John F. Lake, Jr. 
	The sprite class extends the entity class and adds graphics stuff - rectangles & SDL textures
*/
#include "Entity.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "Graphics.h"

#ifndef __SPRITE__
#define __SPRITE__

class Sprite : public Entity{
	public: 
		Sprite();
		//setters
		void setTexture(SDL_Texture * t){texture = t;}
		void setGraphics(Graphics*g){graphics = g;}
		void setSource(int x, int y, int w, int h);
		void setDest(int x, int y, int w, int h);
		void setDestX(int x){dest.x = x;}
		void setDestY(int y){dest.y = y;}
		void setWidth(int w);
		void setHeight(int h);

		//getters:
		SDL_Texture* getTexture(){return texture;}
		SDL_Rect*     getDest(){return &dest;}
		SDL_Rect*     getSource(){return &source;}
		Graphics*    getGraphicss(){return graphics;}
		

		//Misc: 
		void printStatus();
		void loadTexture(const std::string);
		void update();


	protected: 
		Graphics *graphics;
		SDL_Texture * texture;
		SDL_Rect source; 
		SDL_Rect dest; 
};
#endif
