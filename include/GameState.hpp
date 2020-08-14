#pragma once

#include <SFML/Graphics.hpp>
#include "Etat.hpp"
#include "Game.hpp"

namespace TepeGolo
{
	class GameState : public Etat
	{
	public:
		GameState(GameDataRef data);

		void Init();

		void GererEntrer();
		void Update(float dt);
		void Dessiner(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;

		sf::Sprite _pauseButton;

		int turn;
		int gameState;
	};
}// namespace TepeGolo
