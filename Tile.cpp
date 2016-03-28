#include "Tile.h"
Tile::Tile(){
	setSource(0,0,0,0);
	setDest(0,0,TILE_SIZE,TILE_SIZE);
	setType(STONE_BRICK);
	setWidth(TILE_SIZE);
	setHeight(TILE_SIZE);
}

void Tile::update(){
	dest.x = getXLoc()- graphics->getCamera().x;
	dest.y = getYLoc()- graphics->getCamera().y;
}


Tile::Tile(int x, int y, int type){
	setXLoc(x);
	setYLoc(y);
	setType(type);
}

void Tile::setType(int t){
	type = t;
	switch(t){
		case STONE_BRICK:
			setSource(STONE_BRICK_X*TILE_SOURCE_SIZE,STONE_BRICK_Y*TILE_SOURCE_SIZE,TILE_SOURCE_SIZE,TILE_SOURCE_SIZE);
			solid = true;
			break;
	}
}
