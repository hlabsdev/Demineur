#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>

#include <SFML/Graphics.hpp>
#include "Etat.hpp"
#include "Partie.hpp"
#include "Case.hpp"

namespace TepeGolo{
    class Grille : public Etat{
        public:
            Grille(GameDataRef data);

            void Init();
            void GererEntrer();
            void Update(float dt);
            void Dessiner(float dt);
            void InitCase();

        private:
            void ClickGauche();
            void ClickDroit();
            void GenererMine();
            void LancerJeu();
            void MontrerMines();
            void VerifierGagner();

            GameDataRef _data;

            sf::Sprite _background;
            sf::Sprite _pauseButton;
            sf::Sprite _gridSprite;
            Case _cases[9][9];

            int gridArray[9][9];
            bool firstClick = false;
            int nbMine = 10;
            int gameState;
            sf::Clock _temps;
            sf::Time _elapse;
            sf::Text _chrono;
            sf::Text _drapeauRestants;
    };

}
