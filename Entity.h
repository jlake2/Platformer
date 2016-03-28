/*
	John F. Lake, Jr. 
	Entity class - this is a class that holds information about locations, velocities, etc.  Abstracted from the Graphics. 
*/
#include <iostream>
#include "Constants.h"
#include "Boundary.h"

#ifndef __ENTITY__
#define __ENTITY__
class Entity{
	public: 
		//Constructor
		Entity();

		//Misc Functions: 
		void printStatus();
		void update();
		void jump();

		//Setters 
		void setWidth(int w){
			width = w;
			bounds.setWidth(w);
		}
		void setHeight(int h){
			height = h;
			bounds.setHeight(h);
		}
		void setXLoc(int x){
			xLocation = x;
			bounds.setXLoc(x);
		}
		void setYLoc(int y){
			yLocation = y;
			bounds.setYLoc(y);
		}
		void setXVel(int x){xVelocity = x;}
		void setYVel(int y){yVelocity = y;}
		void setXAcc(int x){xAcceleration = x;}
		void setYAcc(int y){yAcceleration = y;}
		void setState(int s){state = s;}
		void setType(int t){type = t;}

		//Getters: 
		int getHeight(){return height;}
		int getWidth(){return width;}
		int getXLoc(){return xLocation;}
		int getYLoc(){return yLocation;}
		int getXVel(){return xVelocity;}
		int getYVel(){return yVelocity;}
		int getXAcc(){return xAcceleration;}
		int getYAcc(){return xAcceleration;}
		int getState(){return state;}
		int getType(){return type;}
		Boundary getBounds(){return bounds;}

		

	protected: 
		//Physical Attributes: 
		int width;
		int height; 

		int xLocation;
		int yLocation;
		
		int xVelocity;
		int yVelocity;

		int xAcceleration;
		int yAcceleration;

		//State: (grounded, jumping, permanent)
		int state;

		//Type: (enemy, NPC, player)
		int type; 

		//Boundary: 
		Boundary bounds;
};
#endif
