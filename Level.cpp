#include "Level.h"

Level::Level(){}

void Level::addTile(int x, int y, int type){
	Tile * t = new Tile(x,y,type);
	t->setGraphics(g);
	t->setWidth(TILE_SIZE);
	t->setHeight(TILE_SIZE);
	t->loadTexture("./Images/tileset.png");
	tiles.push_back(t);
}

void Level::update(){
	for(Tile *t : tiles){
		t->update();
	}
}
