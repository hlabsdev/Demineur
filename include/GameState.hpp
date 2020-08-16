#pragma once

#include <SFML/Graphics.hpp>
#include "Etat.hpp"
#include "Jeu.hpp"
#include "Case.hpp"

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
		//sf::Sprite _cases[9][9];
		Case _cases[9][9];

        int gridArray[9][9];
		int turn;
		int gameState;
		sf::Clock _temps;
		sf::Time _elapse;
		sf::Text _chrono;
		sf::Text _drapeauRestants;
	};
}// namespace TepeGolo
