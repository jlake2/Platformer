/*
	John F. Lake, Jr. 
	Boundary class for collision detection
*/
#include <SDL2/SDL.h>
#include "Constants.h"
#ifndef __BOUNDARY__
#define __BOUNDARY__
class Boundary{
	public: 
		//Constructors: 
		Boundary();	
		Boundary(int,int,int,int);

		//Setters: 
		void setWidth(int w);
		void setHeight(int h);
		void setXLoc(int x);
		void setYLoc(int y);
		void setBounds(int,int,int,int);

		int getXLoc(){return boundary.x;}
		int getYLoc(){return boundary.y;}
		int getWidth(){return boundary.w;}
		int getHeight(){return boundary.h;}

		//Getters: 
		SDL_Rect getBounds(){return boundary;}
		
		//Other: 
		void update(int dx, int dy);
		int checkCollision(Boundary o);
	private: 
		SDL_Rect boundary; 
};
#endif
