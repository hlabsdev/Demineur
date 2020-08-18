#pragma once
#include <SFML/Graphics.hpp>
#include "Etat.hpp"
#include "Partie.hpp"
#include "Grille.hpp"

namespace TepeGolo
{
	class PauseState : public Etat
	{
	public:
		PauseState(GameDataRef data, Grille jeuEnCours);

		void Init();

		void GererEntrer();
		void Update(float dt);
		void Dessiner(float dt);

	private:
		GameDataRef _data;
		Grille* _jeuEnCours;

		sf::Sprite _background;

		sf::Sprite _resumeButton;
		sf::Sprite _homeButton;

	};
}
