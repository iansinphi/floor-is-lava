// Player.h
//
// This Player class stores all the necessary attributes
// ... of a player object and provides functions for all
// ... player behavior.

#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Player
{
private:
	// Player's x, y position
	Vector2f position;
	Vector2f velocity;

	// Player's texture and sprite
	Sprite sprite;

	// which direction is the player currently moving in
	bool leftIsPressed;
	bool rightIsPressed;
	bool spaceIsPressed;

	// Player's speed in pixels/second
	float speed;
	float gravity;

public:
	// constructor
	Player(Sprite);

	// retreive Player's sprite
	Sprite getSprite();

	// get Player's current position
	Vector2f getPosition();

	// move Player
	void moveLeft();
	void moveRight();
	void startJump();

	// Stop Player's movement
	void stopLeft();
	void stopRight();
	void endJump();
	
	// called every frame
	void input();
	void update(float);
};
