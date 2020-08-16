#pragma once

#include "DEFINITIONS.hpp"
#include <string>
#include "Game.hpp"
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

        protected:

        private:
            GameDataRef _data;
            int nombreCaseMineVoisine;
            float _x;
            float _y;

            sf::Sprite _face;
            bool _estDeFace;

    };
}
