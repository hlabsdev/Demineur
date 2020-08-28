#pragma once
#include "DEFINITIONS.hpp"
#include <string>
#include "Partie.hpp"
#include <SFML/Graphics.hpp>
namespace TepeGolo {
    class Case
    {
        public:
            Case();

            void afficher(sf::RenderWindow& fenetre);
            void decouvrir();
            void setPlace(float x, float y);
            float getX();
            float getY();
            void placerMine();
            void placerCase(float x, float y);
            void Marquer();
            void FausseBombe();
            void ajoutVoisin();
            int nombreCaseMineVoisine;

            GameDataRef _data = std::make_shared<GameData>();
            float _x;
            float _y;
            bool _estMarque = false;
            bool _estMinee = false;
            bool _estDecouvers = false;
            bool _estClicable = true;
            sf::Sprite _face;


    };
}
