#pragma once

#include <SFML/Graphics.hpp>
#include "Etat.hpp"
#include "Game.hpp"

namespace TepeGolo
{
	class PauseState : public Etat
	{
	public:
		PauseState(GameDataRef data);

		void Init();

		void GererEntrer();
		void Update(float dt);
		void Dessiner(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _resumeButton;
		sf::Sprite _homeButton;

	};
}
