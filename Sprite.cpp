#include "Sprite.h"

Sprite::Sprite(){
	setSource(0,0,0,0);
	setDest(0,0,0,0);
}


//Use the graphics context to get the texture
void Sprite::loadTexture(const std::string path){
	texture = graphics->getTextureFromPath(path);
}

void Sprite::printStatus(){
	std::cout << "\n\n";
	Entity::printStatus();
	std::cout << "Source Rectangle:\n";
	graphics->displayRect(source);
	std::cout << "Destination Rectangle:\n";
	graphics->displayRect(dest);
}


//Updates the camera, updates the sprites absolute location, and updates the dest rect. 
void Sprite::update(){
	Entity::update();
	dest.x = getXLoc()- graphics->getCamera().x;
	dest.y = getYLoc()- graphics->getCamera().y;
}


//Set source rectangle
void Sprite::setSource(int x, int y, int w, int h){
	source.x = x;
	source.y = y;
	source.w = w;
	source.h = h;
}
//Set dest rectangle
void Sprite::setDest(int x, int y, int w, int h){
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
}


void Sprite::setWidth(int w){
	Entity::setWidth(w);
	dest.w = w;
}
void Sprite::setHeight(int h){
	Entity::setHeight(h);
	dest.h = h;
}

