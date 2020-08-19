#pragma once
#include <SFML/Graphics.hpp>
#include "Etat.hpp"
#include "Partie.hpp"

namespace TepeGolo
{
	class GameWinState : public Etat
	{
	public:
		GameWinState(GameDataRef data);

		void Init();

		void GererEntrer();
		void Update(float dt);
		void Dessiner(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _retryButton;
		sf::Sprite _homeButton;
		sf::Sprite _winImage;

	};
}
