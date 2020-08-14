#pragma once

#include <sstream>
#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace TepeGolo
{
	GameState::GameState(GameDataRef data) : _data(data){}

	void GameState::Init(){
		gameState = STATE_PLAYING;
		turn = PLAYER_PIECE;

		this->_data->assets.LoadTexture("Button Pause", PAUSE_BUTTON);

		_background.setTexture(this->_data->assets.GetTexture("Background"));
		_pauseButton.setTexture(this->_data->assets.GetTexture("Button Pause"));

		_pauseButton.setPosition( this->_data->fenetre.getSize( ).x - _pauseButton.getLocalBounds( ).width, _pauseButton.getPosition( ).y );
	}

	void GameState::GererEntrer()
	{
		sf::Event event;

		while (this->_data->fenetre.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->fenetre.close();
			}

			if (this->_data->imput.IsSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->fenetre))
			{
				// PAUSE
				std::cout << "Pause The Game" << std::endl;
			}
		}
	}

	void GameState::Update(float dt)
	{

	}

	void GameState::Dessiner(float dt)
	{
		this->_data->fenetre.clear(sf::Color::Red);

		this->_data->fenetre.draw( this->_background );

		this->_data->fenetre.draw( this->_pauseButton );

		this->_data->fenetre.display();
	}
}
