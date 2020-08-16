#pragma once

#include "DEFINITIONS.hpp"
#include <string>
#include "Jeu.hpp"
#include <SFML/Graphics.hpp>

namespace TepeGolo {
    class Case
    {
        public:
            Case(GameDataRef data);
            ~Case(){};

            void afficher(sf::RenderWindow& fenetre);
            void tourner();

            void setPosition(float x, float y);

        private:
            GameDataRef _data;
            int nombreCaseMineVoisine;
            float _x;
            float _y;
            bool estMarque;
            bool estMinee;

            sf::Sprite _face;
            bool _estDeFace;

    };
}
