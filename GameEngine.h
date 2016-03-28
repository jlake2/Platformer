/*
	John F. Lake, Jr. 
	Class that handles managing all the different moving parts (managing levels, graphics, input, music, etc.)
*/
#include "Graphics.h"
#include "Sprite.h"
#include "Tile.h"
#include "Level.h"
#include "AnimatedSprite.h"



class GameEngine{
	public: 

		
		GameEngine();

		//Setup the player's info and the graphics object. 
		void setup();
		
		//Get input from the user (key events)
		void handleInput(int*gameLoop);
		void updateEverything();
		void checkCollisions();
		void updateCamera();
		void loadLevel(std::string);

		//Main Game loop - get input, update, render loop
		void loop();
		
	private: 
		Graphics g; 
		Sprite backGround;
		AnimatedSprite playerOne;
		Level level;
};
