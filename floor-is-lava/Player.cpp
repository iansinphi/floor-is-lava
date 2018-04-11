#include "stdafx.h"
#include "Player.h"

// constructor
Player::Player() {
	// Player's speed
	speed = 500;

	// associate a texture with the sprite
	texture.loadFromFile("player.png");
	sprite.setTexture(texture);

	// set Player's starting position
	position.x = 500;
	position.y = 500;
	velocityX = 4.0;
	velocityY = 0.0
	gravity = 0.5
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

void Player::startJump()	{
	spaceIsPressed = true;
	velocityY = -12.0;
}

void endJump()		{
	spaceIsPressed = false;
	if(velocityY < -6.0)
		velocity = -6.0;
}

void Player::stopLeft() {
	leftIsPressed = false;
}

void Player::stopRight() {
	rightIsPressed = false;
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
		position.x += velocityX * timeDelta;
		position.y += velocityY * timeDelta;
		velocityY += gravity * timeDelta;
	}
	// move Player sprite to new position
	sprite.setPosition(position);
}
