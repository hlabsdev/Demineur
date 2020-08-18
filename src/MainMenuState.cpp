#include <sstream>
#include "MainMenuState.hpp"
#include "Grille.hpp"
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
		this->_data->assets.LoadTexture("Menu", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Debutant", DEBUTANT_BUTTON);
		this->_data->assets.LoadTexture("Intermediaire", INTERMEDIAIRE_PLAY_BUTTON);
		this->_data->assets.LoadTexture("Difficile", DIFFICILE_BUTTON);
		this->_data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_FILEPATH);

		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_menu.setTexture(this->_data->assets.GetTexture("Menu"));
		this->_debutant.setTexture(this->_data->assets.GetTexture("Debutant"));
		this->_intermediaire.setTexture(this->_data->assets.GetTexture("Intermediaire"));
		this->_difficile.setTexture(this->_data->assets.GetTexture("Difficile"));

		this->_titre.setTexture(this->_data->assets.GetTexture("Game Title"));

		this->_debutant.setPosition(200, (SCREEN_HEIGHT / 2) - (this->_debutant.getGlobalBounds().height / 2));
		this->_intermediaire.setPosition((SCREEN_WIDTH / 2) - (this->_intermediaire.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_intermediaire.getGlobalBounds().height / 2));
		this->_difficile.setPosition(470, (SCREEN_HEIGHT / 2) - (this->_difficile.getGlobalBounds().height / 2));

        this->_menu.setPosition((SCREEN_WIDTH / 2) - (this->_menu.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 4) - (this->_menu.getGlobalBounds().height / 4));
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

			if (this->_data->imput.IsSpriteClicked(this->_intermediaire, sf::Mouse::Left, this->_data->fenetre))
			{
				this->_data->machine.AjoutEtat(EtatRef (new Grille(_data)), true);
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
		this->_data->fenetre.draw(this->_debutant);
		this->_data->fenetre.draw(this->_intermediaire);
		this->_data->fenetre.draw(this->_difficile);
		this->_data->fenetre.draw(this->_titre);

		this->_data->fenetre.display();
	}
} // namespace TepeGolo
