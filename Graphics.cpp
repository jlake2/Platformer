#include "Graphics.h"
#include "Constants.h"
#include <string>
#include <iostream>

Graphics::Graphics(){
	camera.x = 0;
	camera.y = 0;
	camera.w = WINDOW_WIDTH;
	camera.h = WINDOW_HEIGHT;
}

SDL_Texture* Graphics::getTextureFromPath(std::string path){
	SDL_Texture* tex = NULL;
	SDL_Surface* loadSurf = IMG_Load(path.c_str());
	tex = SDL_CreateTextureFromSurface(renderer,loadSurf);
	SDL_FreeSurface(loadSurf);
	return tex;
}

void Graphics::setup(const std::string title,int width, int height,int xLoc,int yLoc){
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(title.c_str(),xLoc,yLoc,width,height,0);
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
}

void Graphics::close(){
	SDL_DestroyRenderer(renderer); 
	SDL_DestroyWindow(window); 
	SDL_Quit(); 
}

void Graphics::render(SDL_Texture * t, SDL_Rect * src, SDL_Rect * dst){
	SDL_RenderCopy(renderer,t,src,dst);
}

void Graphics::renderWithFlip(SDL_Texture * t, SDL_Rect * src, SDL_Rect * dst,SDL_RendererFlip flip){
	SDL_RenderCopyEx(renderer,t,src,dst,0,0,flip);
}

SDL_Rect Graphics::makeRect(int x, int y, int w, int h){
	SDL_Rect ret; 
	ret.x = x;
	ret.y = y;
	ret.w = w;
	ret.h = h;
	return ret;
}

void Graphics::displayRect(SDL_Rect r){
	std::cout << "Rect:\n";
	std::cout << "X: " << r.x << std::endl;
	std::cout << "Y: " << r.y << std::endl;
	std::cout << "W: " << r.w << std::endl;
	std::cout << "H: " << r.h << std::endl;
}

void Graphics::updateCamera(int x, int y){
	camera.x = x; 
	camera.y = y;

	if(camera.x <= 0)
		camera.x = 0;
	if(camera.y <=0)
		camera.y = 0;
	if((camera.x + camera.w) >= LEVEL_WIDTH)
		camera.x = LEVEL_WIDTH-camera.w;
	if((camera.y + camera.h) >= LEVEL_HEIGHT)
		camera.y = LEVEL_HEIGHT-camera.h;
		
	
}
