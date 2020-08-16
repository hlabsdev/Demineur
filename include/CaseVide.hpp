#pragma once

#include <string>
#include "EtatMachine.hpp"
#include "AssetManager.hpp"
#include "ImputManager.hpp"
#include <SFML/Graphics.hpp>

namespace TepeGolo {
    class CaseVide: public Case
    {
        public:
            CaseVide(GameDataRef data);
            ~CaseVide(){};

            void afficher(sf::RenderWindow& fenetre);
            void tourner();
            void setPosition(float x, float y);

        protected:

        private:
            GameDataRef _data;
            sf::Sprite _face;
            bool _estDeFace;
    };
}
