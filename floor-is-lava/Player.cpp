#include "stdafx.h"
#include "Player.h"

// constructor
Player::Player() {
	// Player's speed
	speed = 500;
	gravity = 500.0f

	// associate a texture with the sprite
	texture.loadFromFile("player.png");
	sprite.setTexture(texture);

	// set Player's starting position
	position.x = 500;
	position.y = 500;
//	velocity.x 100;
	velocity.y = 500;
}


Sprite Player::getSprite() {
	return sprite;
}

void Player::moveLeft() {
	leftIsPressed = true;
}

void Player::moveRight() {
	rightIsPressed = true;
}

void Player::stopLeft() {
	leftIsPressed = false;
}

void Player::stopRight() {
	rightIsPressed = false;
}

void Player::startJump() {
	spaceIsPressed = true;
}

void Player::endJump() {
	spaceIsPressed = false;
}

// move Player based on the input this frame,
// ... the time elapsed, and the speed
void Player::update(float timeDelta) {
	if (rightIsPressed) {
		position.x += speed * timeDelta;
	}

	if (leftIsPressed) {
		position.x -= speed * timeDelta;
	}
	
	if (spaceIsPressed) {
		velocity.y = -600.0f;
		
		position.y += velocity.y * timeDelta;
		position.x += velocity.x * timeDelta;
		velocity.y += gravity * timeDelta;
	}
	else if(position <= 500)
	{
		position.y += gravity * timeDelta;
		if (velocity.y < -100.0f)
			velocity.y = -100.0f;
	}

	// move Player sprite to new position
	sprite.setPosition(position);
}
