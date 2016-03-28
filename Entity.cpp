#include "Entity.h"

Entity::Entity(){
	width = 0;
	height = 0;
	xLocation = 0;
	yLocation = 0;
	xVelocity = 0;
	yVelocity = 0;
	xAcceleration = 0;
	yAcceleration = GRAVITY;
	bounds.setBounds(0,0,0,0);
	state = STANDING;
}

void Entity::printStatus(){
	std::cout << "Entity Status:\n";
	std::cout << "X: " << xLocation << std::endl;
	std::cout << "Y: " << yLocation << std::endl;
	std::cout << "\n\nXVel: " << xVelocity << std::endl;
	std::cout << "YVel: " << yVelocity << std::endl;
	std::cout << "\n\nXAcc: " << xAcceleration << std::endl;
	std::cout << "YAcc: " << yAcceleration << std::endl;
	std::cout << "\nBounds X:" << bounds.getXLoc() << std::endl;
	std::cout << "Bounds Y:" << bounds.getYLoc() << std::endl;
	std::cout << "Bounds H:" << bounds.getHeight() << std::endl;
	std::cout << "Bounds W:" << bounds.getWidth() << std::endl;
	std::cout << "STATE: " << state << std::endl;
	
}



void Entity::jump(){
	if(state == WALKING || state == STANDING){
		setYVel(JUMPVEL);
		state = JUMPING;
	}
}

void Entity::update(){
	xLocation+=xVelocity;
	yLocation+=yVelocity;
	xVelocity+=xAcceleration;
	yVelocity+=yAcceleration;
	if(yVelocity > 10){
		yVelocity = 10;
	}

	if(xLocation <= 0)
		xLocation = 0;
	if(yLocation <= 0)
		yLocation = 0;
	if((xLocation + width) >= LEVEL_WIDTH)
		xLocation = LEVEL_WIDTH - width;
	if((yLocation + height) >= LEVEL_HEIGHT){
		yLocation = LEVEL_HEIGHT - height;
		if(xVelocity > 0)
			state = WALKING;
		else
			state = STANDING;
		yVelocity = 0;
	}
	
	
	bounds.setXLoc(xLocation);
	bounds.setYLoc(yLocation);
	}
