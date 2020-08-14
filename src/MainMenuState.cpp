#pragma once

#include <sstream>
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace TepeGolo
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{
	}

	void MainMenuState::Init()
	{
		this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);
		this->_data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_FILEPATH);

		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		this->_titre.setTexture(this->_data->assets.GetTexture("Game Title"));

		this->_playButton.setPosition((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_playButton.getGlobalBounds().height / 2));

		this->_titre.setPosition((SCREEN_WIDTH / 2) - (this->_titre.getGlobalBounds().width / 2), this->_titre.getGlobalBounds().height * 0.1);
	}

	void MainMenuState::GererEntrer()
	{
		sf::Event event;

		while (this->_data->fenetre.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->fenetre.close();
			}

			if (this->_data->imput.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->fenetre))
			{
				this->_data->machine.AjoutEtat(EtatRef (new GameState(_data)), true);
                //std::cout << "Pause The Game" << std::endl;

			}
		}
	}

	void MainMenuState::Update(float dt)
	{
	}

	void MainMenuState::Dessiner(float dt)
	{
		this->_data->fenetre.clear(sf::Color::Red);

		this->_data->fenetre.draw(this->_background);
		this->_data->fenetre.draw(this->_playButton);
		this->_data->fenetre.draw(this->_titre);

		this->_data->fenetre.display();
	}
} // namespace TepeGolo
