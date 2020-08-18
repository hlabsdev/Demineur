#pragma once

#include <sstream>
#include "PauseState.hpp"
#include "DEFINITIONS.hpp"
#include "Grille.hpp"
#include "MainMenuState.hpp"

#include <iostream>

namespace TepeGolo
{
	PauseState::PauseState(GameDataRef data, Grille jeuEnCours){
        _data = data;
        _jeuEnCours = &jeuEnCours;
	}

	void PauseState::Init()
	{
		this->_data->assets.LoadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Resume Button", RESUME_BUTTON);
		this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);

		this->_background.setTexture(this->_data->assets.GetTexture("Pause Background"));
		this->_resumeButton.setTexture(this->_data->assets.GetTexture("Resume Button"));
		this->_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));

		this->_resumeButton.setPosition((this->_data->fenetre.getSize().x / 2) - (this->_resumeButton.getLocalBounds().width / 2), (this->_data->fenetre.getSize().y / 3) - (this->_resumeButton.getLocalBounds().height / 2));
		this->_homeButton.setPosition((this->_data->fenetre.getSize().x / 2) - (this->_homeButton.getLocalBounds().width / 2), (this->_data->fenetre.getSize().y / 3 * 2) - (this->_homeButton.getLocalBounds().height / 2));
	}

	void PauseState::GererEntrer()
	{
		sf::Event event;

		while (this->_data->fenetre.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->fenetre.close();
			}

			if (this->_data->imput.IsSpriteClicked(this->_resumeButton, sf::Mouse::Left, this->_data->fenetre))
			{
				// Peprise du jeu
				//this->_data->machine.AjoutEtat(EtatRef(new Grille(_data)), true);
				//this->_data->machine.AjoutEtat(EtatRef(this->_jeuEnCours));
				//this->_data->machine.ProcessEtatChange();
				//this->_jeuEnCours->_data->machine.ProcessEtatChange();

			}

			if (this->_data->imput.IsSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->fenetre))
			{
				// Vas au menu principale
				this->_data->machine.AjoutEtat(EtatRef(new MainMenuState(_data)), true);

			}
		}
	}

	void PauseState::Update(float dt)
	{

	}

	void PauseState::Dessiner(float dt)
	{
		this->_data->fenetre.clear(sf::Color::Red);

		this->_data->fenetre.draw(this->_background);
		this->_data->fenetre.draw(this->_resumeButton);
		this->_data->fenetre.draw(this->_homeButton);

		this->_data->fenetre.display();
	}
}
