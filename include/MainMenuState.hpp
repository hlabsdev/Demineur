#pragma once

#include <SFML/Graphics.hpp>
#include "Etat.hpp"
#include "Jeu.hpp"


namespace TepeGolo{
    class MainMenuState:public Etat{
    public:
        MainMenuState(GameDataRef data);

        void Init();

        void GererEntrer();
        void Update(float dt);
        void Dessiner(float dt);

    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _debutant;
        sf::Sprite _intermediaire;
        sf::Sprite _difficile;
        sf::Sprite _titre;
    };
}

