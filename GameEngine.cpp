#include "GameEngine.h"
#include <iostream> 
#include <fstream>


GameEngine::GameEngine(){}

void GameEngine::setup(){
	g.setup("Puzzler",WINDOW_WIDTH,WINDOW_HEIGHT,20,100);


	//Player
	playerOne.setGraphics(&g);
	playerOne.loadTexture("./Images/mario.png");
	playerOne.setSources(PLAYER);


	playerOne.setXLoc(20);
	playerOne.setYLoc(1700);
	playerOne.setHeight(40);
	playerOne.setWidth(40);



	//Tile
	level.setGraphics(&g);
	loadLevel("./Levels/l1.level");


	//BG 
	backGround.setGraphics(&g);
	backGround.loadTexture("./Images/l1.png");
	backGround.setSource(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);
	backGround.setDest(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);

}


void GameEngine::loadLevel(std::string path){
	std::ifstream map(path.c_str());
	int xLoc,yLoc,type;
	/*
	while(map >> xLoc >> yLoc >> type){
		if(type!=0){
			level.addTile(xLoc,yLoc,type);
		}
	}

		*/
	int i=0;
	int j=0;
	while(map >> type){
		if(type){
			std::cout << "ADDING TILE AT " << j << " " << i << std::endl;
			level.addTile(j,i,type);
			std::cout << "ADDED TILE AT " << j << " " << i << std::endl;
		}
		j+=TILE_SIZE;
		if(j >= LEVEL_WIDTH){
			j = 0;
			i+=TILE_SIZE;
		}
	}
}

void GameEngine::handleInput(int * gameLoop){
	SDL_Event e;
	while(SDL_PollEvent(&e) != 0 ){
		switch(e.type){
			case SDL_QUIT:
				*gameLoop = 0;
				break;
			case SDL_KEYDOWN:
				switch(e.key.keysym.sym){
					case SDLK_RIGHT:
						playerOne.setXVel(3);
						if(playerOne.getState() != JUMPING){
							playerOne.setState(WALKING);
							playerOne.setFlip(SDL_FLIP_HORIZONTAL);
						}
						break;
					case SDLK_LEFT:
						playerOne.setXVel(-3);
						if(playerOne.getState() != JUMPING){
							playerOne.setState(WALKING);
							playerOne.setFlip(SDL_FLIP_NONE);
						}
						break;
					case SDLK_SPACE:
						playerOne.jump();
						break;
				}
				break;
			case SDL_KEYUP:
				switch(e.key.keysym.sym){
					case SDLK_RIGHT:
						playerOne.setXVel(0);
						playerOne.setState(STANDING);
						break;
					case SDLK_LEFT:
						playerOne.setXVel(0);
						playerOne.setState(STANDING);
						break;
					case SDLK_UP:
						playerOne.setYVel(0);
						break;
					case SDLK_DOWN:
						playerOne.setYVel(0);
						break;
				}
				break;
		}
	}
}


void GameEngine::checkCollisions(){
	//Check collisions:
	for(Tile *tile : level.getTiles()){
		int result = playerOne.getBounds().checkCollision(tile->getBounds());
		if(result){
			switch(result){
				case UP: 
					playerOne.setYVel(0);
					playerOne.setYLoc(tile->getYLoc()-playerOne.getHeight());
					if(playerOne.getXVel() == 0)
						playerOne.setState(STANDING);
					else
						playerOne.setState(WALKING);
					break;
				case DOWN: 
					playerOne.setYVel(0);
					playerOne.setYLoc(tile->getYLoc()+tile->getHeight()+1);
					break;
				case LEFT: 
					playerOne.setXVel(0);
					playerOne.setXLoc(tile->getXLoc()-playerOne.getWidth());
					break;
				case RIGHT: 
					playerOne.setXVel(0);
					playerOne.setXLoc(tile->getXLoc()+tile->getWidth());
					break;
			}
		}
	}
	playerOne.setDestX(playerOne.getXLoc()- g.getCamera().x);
	playerOne.setDestY(playerOne.getYLoc()- g.getCamera().y);
}



void GameEngine::updateCamera(){
	g.updateCamera(playerOne.getXLoc()-CAMERA_OFFSET,playerOne.getYLoc()-CAMERA_OFFSET);
	if(playerOne.getXLoc() < CAMERA_OFFSET){
		g.updateCamera(0,playerOne.getYLoc()-CAMERA_OFFSET);
	}else if (playerOne.getYLoc() < CAMERA_OFFSET){
		g.updateCamera(playerOne.getXLoc()-CAMERA_OFFSET,0);
	}else if (playerOne.getXLoc() < CAMERA_OFFSET && playerOne.getYLoc() < CAMERA_OFFSET){
		g.updateCamera(0,0);
	}

}

void GameEngine::loop(){
	int gameLoop = 1;
	int frameOffset = 0;
	while(gameLoop){

		//Get input
		handleInput(&gameLoop);

		//Update everything
		playerOne.update();

		//Check collisions between player and level
		checkCollisions();

		//Update tiles relative to camera: 
		level.update();
		updateCamera();
		backGround.setSource(g.getCamera().x,g.getCamera().y,WINDOW_WIDTH,WINDOW_HEIGHT);

		//Render Everything
		g.render(backGround.getTexture(),backGround.getSource(),backGround.getDest());

		if(frameOffset == 4)
			playerOne.updateFrame();
		frameOffset++;
		if(frameOffset == 5)
			frameOffset = 0;


		for(Tile *tile : level.getTiles()){
			g.render(tile->getTexture(),tile->getSource(),tile->getDest());
		}
		g.renderWithFlip(playerOne.getTexture(),playerOne.getSource(),playerOne.getDest(),playerOne.getFlip());
		g.present();
		g.delay(DELAY);
	}
	g.close();
}
