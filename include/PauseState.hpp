#pragma once

#include <SFML/Graphics.hpp>
#include "Etat.hpp"
#include "Jeu.hpp"
#include "GameState.hpp"

namespace TepeGolo
{
	class PauseState : public Etat
	{
	public:
		PauseState(GameDataRef data, GameState jeuEnCours);

		void Init();

		void GererEntrer();
		void Update(float dt);
		void Dessiner(float dt);

	private:
		GameDataRef _data;
		GameState* _jeuEnCours;

		sf::Sprite _background;

		sf::Sprite _resumeButton;
		sf::Sprite _homeButton;

	};
}
