#include "Sprite.h"

#ifndef __TILE__
#define __TILE__

class Tile: public Sprite{
	public: 	
		//Constructors:
		Tile();
		Tile(int,int,int);


		//Setters:
		void setType(int);
		void setSolid(bool s){solid = s;}



		//Misc: 
		bool isSolid(){return solid;}
		void update();

	private: 
		int type;
		bool solid;
};
#endif
