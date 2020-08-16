#pragma once

#include "DEFINITIONS.hpp"
#include <string>
#include "Jeu.hpp"
#include <SFML/Graphics.hpp>
namespace TepeGolo {
    class Case
    {
        public:
            Case();

            void afficher(sf::RenderWindow& fenetre);
            void init(std::string nom, std::string fic);
            void decouvrir();

            void setPlace(float x, float y);
            float getPlace();
            void placerMine();
            void placerCase(float x, float y);
            void Marquer();
            int nombreCaseMineVoisine;

//        private:
            GameDataRef _data;
            float _x;
            float _y;
            bool _estMarque;
            bool _estMinee;
            bool _estDecouvers;
            sf::Sprite _face;


    };
}
