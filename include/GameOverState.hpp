#pragma once
#include <SFML/Graphics.hpp>
#include "Etat.hpp"
#include "Partie.hpp"

namespace TepeGolo
{
	class GameOverState : public Etat
	{
	public:
		GameOverState(GameDataRef data);

		void Init();

		void GererEntrer();
		void Update(float dt);
		void Dessiner(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _retryButton;
		sf::Sprite _homeButton;

	};
}
