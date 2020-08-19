#include <sstream>
#include "GameWinState.hpp"
#include "DEFINITIONS.hpp"
#include "Grille.hpp"
#include "MainMenuState.hpp"

#include <iostream>

namespace TepeGolo
{
	GameWinState::GameWinState(GameDataRef data) : _data(data)
	{

	}

	void GameWinState::Init()
	{
		this->_data->assets.LoadTexture("Retry Button", RETRY_BUTTON);
		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);
		this->_data->assets.LoadTexture("Win", WIN_CAPTION);

		this->_retryButton.setTexture(this->_data->assets.GetTexture("Retry Button"));
		this->_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));
		this->_winImage.setTexture(this->_data->assets.GetTexture("Win"));

		this->_retryButton.setPosition((this->_data->fenetre.getSize().x / 2) - (this->_retryButton.getLocalBounds().width / 2), (this->_data->fenetre.getSize().y / 3) - (this->_retryButton.getLocalBounds().height / 2));
		this->_winImage.setPosition((this->_data->fenetre.getSize().x / 2) - (this->_winImage.getLocalBounds().width / 2), (this->_data->fenetre.getSize().y / 2) - (this->_winImage.getLocalBounds().height / 2));
		this->_homeButton.setPosition((this->_data->fenetre.getSize().x / 2) - (this->_homeButton.getLocalBounds().width / 2), (this->_data->fenetre.getSize().y / 3 * 2) - (this->_homeButton.getLocalBounds().height / 2));
	}

	void GameWinState::GererEntrer()
	{
		sf::Event event;

		while (this->_data->fenetre.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->fenetre.close();
			}

			if (this->_data->imput.IsSpriteClicked(this->_retryButton, sf::Mouse::Left, this->_data->fenetre))
			{
				// Aller a la grlle de jeu
				this->_data->machine.AjoutEtat(EtatRef(new Grille(_data)), true);
			}

			if (this->_data->imput.IsSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->fenetre))
			{
				// Aller au menu principal
				this->_data->machine.AjoutEtat(EtatRef(new MainMenuState(_data)), true);

			}
		}
	}

	void GameWinState::Update(float dt)
	{

	}

	void GameWinState::Dessiner(float dt)
	{
		this->_data->fenetre.clear(sf::Color::Green);

		this->_data->fenetre.draw(this->_retryButton);
		this->_data->fenetre.draw(this->_homeButton);
		this->_data->fenetre.draw(this->_winImage);

		this->_data->fenetre.display();
	}
}
