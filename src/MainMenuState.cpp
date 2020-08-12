#include <sstream>
#include <iostream>
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"

namespace TepeGolo {
	MainMenuState::MainMenuState(GameDataRef data) :_data(data) {

	}

	void MainMenuState::Init() {
		this->_data->assets.LoadTexture("Arriere Plan", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Button Jouer", MAIN_MENU_PLAY_BUTTON);
		this->_data->assets.LoadTexture("Titre du Jeu", MAIN_MENU_TITLE_FILEPATH);

		this->_background.setTexture(this->_data->assets.GetTexture("Arrire plan"));
		this->_playButton.setTexture(this->_data->assets.GetTexture("Button Jouer"));
		this->_titre.setTexture(this->_data->assets.GetTexture("Titre du Jeu"));

		//this->_playButton.setPosition((SCREN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2), (SCREN_HEIGHT / 2) - (this->_playButton.getGlobalBounds().height / 2));

		//this->_titre.setPosition((SCREN_WIDTH / 2) - (this->_titre.getGlobalBounds().width / 2), this->_titre.getGlobalBounds().height * 0.1);
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
				// Aller a l'ecran du jeu
				std::cout<<"Bienvenu au jeu"<<std::endl;
				//				this->_data->machine.AjoutEtat(EtatRef(new GameState(_data)), true);
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


}
