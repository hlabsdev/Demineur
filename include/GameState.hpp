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
	    void InitCase();
	    void Decouvrire();

		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _pauseButton;
		sf::Sprite _gridSprite;
		sf::Sprite _cases[9][9];

        int gridArray[9][9];
		int turn;
		int gameState;
	};
}// namespace TepeGolo
