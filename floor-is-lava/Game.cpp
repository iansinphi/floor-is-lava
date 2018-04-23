#include "stdafx.h"
#include "Game.hpp"
#include "SplashState.hpp"

Game::Game(int width, int height, std::string title)
{
	_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	_data->machine.AddState(StateRef(new SplashState(this->_data)));

	this->Run();
}


void Game::input() {
	// Player quits game
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}

	// Player movement input
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		player.moveLeft();
	}
	else {
		player.stopLeft();
	}

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		player.moveRight();
	}
	else {
		player.stopRight();
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		player.startJump();
	}
	else {
		player.endJump();
	}
}


// send time passed to all game objects
void Game::update(float seconds) {
	player.update(seconds);
}


// re-draw game every frame
void Game::render() {
	// clear previous frame
	window.clear(Color::Black);

	// draw the background
	//window.draw(bkgrdSprite);
	window.draw(player.getSprite());

	// show what has been drawn
	window.display();
}

void Game::Run()
{
    float newTime, frameTime, interpolation;
    
    float currentTime = this->_clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;
    
    while (this->_data->window.isOpen())
    {
        this->_data->machine.ProcessStateChanges();
        
        newTime = this->_clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;
        
        if (frameTime > 0.25f)
        {
            frameTime = 0.25f;
        }
        
        currentTime = newTime;
        accumulator += frameTime;
        
        while (accumulator >= dt)
        {
            this->_data->machine.GetActiveState()->HandleInput();
            this->_data->machine.GetActiveState()->Update(dt);
            
            accumulator -= dt;
        }
        
        interpolation = accumulator / dt;
        this->_data->machine.GetActiveState()->Draw(interpolation);
    }
}
