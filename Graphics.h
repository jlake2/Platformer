/*
	John F. Lake, Jr. 
	Graphics Class
	Holds all info pertaining to rendering graphics on the screen. 

*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#ifndef __GRAPHICS__
#define __GRAPHICS__

class Graphics{
	public: 
		Graphics();
		void setup(const std::string title,int width, int height,int xLoc,int yLoc);
		void close();
		void render(SDL_Texture* t, SDL_Rect *src, SDL_Rect *dst);
		void renderWithFlip(SDL_Texture* t, SDL_Rect *src, SDL_Rect *dst,SDL_RendererFlip f);
		void present(){SDL_RenderPresent(renderer);}
		void setCamera(SDL_Rect c){camera = c;}
		void updateCamera(int dx, int dy);
		
		SDL_Rect makeRect(int x, int y, int w, int h);
		SDL_Rect getCamera(){return camera;}
		SDL_Renderer* getRenderer(){return renderer;}
		SDL_Texture* getTextureFromPath(std::string);
		void displayRect(SDL_Rect r);
		void delay(int d){SDL_Delay(d);}

	private: 
		SDL_Renderer * renderer; 
		SDL_Window* window; 
		SDL_Rect camera;
};
#endif
