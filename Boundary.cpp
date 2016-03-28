#include "Boundary.h"


Boundary::Boundary(){
	boundary.x = 0;
	boundary.y = 0;
	boundary.w = 0;
	boundary.h = 0;
}
Boundary::Boundary(int x, int y, int w, int h){
	boundary.x = x;
	boundary.y = y;
	boundary.w = w;
	boundary.h = h;
}


void Boundary::setBounds(int x, int y, int w, int h){
	boundary.x = x;
	boundary.y = y;
	boundary.w = w;
	boundary.h = h;
}

void Boundary::setWidth(int w){
	boundary.w = w;
}
void Boundary::setHeight(int h){
	boundary.h = h;
}
void Boundary::setXLoc(int x){
	boundary.x = x;
}
void Boundary::setYLoc(int y){
	boundary.y = y;
}


void Boundary::update(int dx, int dy){
	boundary.x += dx; 
	boundary.y += dy; 
}


int Boundary::checkCollision(Boundary o){
	SDL_Rect other = o.getBounds();
	int left = boundary.x;
	int right= boundary.x+boundary.w;
	int up= boundary.y;
	int down= boundary.y+boundary.h;

	int otherLeft = other.x;
	int otherRight = other.x+other.w;
	int otherUp = other.y;
	int otherDown = other.y+other.h;

	int b_collision = otherDown - up;
	int t_collision = down - otherUp;
	int l_collision = right- otherLeft;
	int r_collision = otherRight - left;

	if(right >= otherLeft && left <= otherRight){
		if(down >= otherUp && up <= otherDown){
			if (t_collision < b_collision && t_collision < l_collision && t_collision < r_collision ){               
				return UP;
			}
			if (b_collision < t_collision && b_collision < l_collision && b_collision < r_collision){
				return DOWN;
			}
			if (l_collision < r_collision && l_collision < t_collision && l_collision < b_collision){
				return LEFT;
			}
			if (r_collision < l_collision && r_collision < t_collision && r_collision < b_collision){
				return RIGHT;
			}
						
			
		}
	}
	return 0;
}



