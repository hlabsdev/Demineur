#pragma once
#include <memory>
#include <string>
#include "EtatMachine.hpp"
#include "AssetManager.hpp"
#include "ImputManager.hpp"
#include <SFML/Graphics.hpp>

namespace TepeGolo {
    struct GameData {
        EtatMachine machine;
        sf::RenderWindow fenetre;
        AssetManager assets;
        ImputManager imput;
    };
    typedef std::shared_ptr<GameData> GameDataRef;
    class Partie{
        public:
            Partie(int largeur, int hauteur, std::string titre);

        protected:

        private:
            const float dt = 1.0f/60.0f;
                sf::Clock _clock;

            GameDataRef _data = std::make_shared<GameData>();

            void Run();
    };


}
