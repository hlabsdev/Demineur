#pragma once

#include "Etat.hpp"
#include "Jeu.hpp"
#include <SFML/Graphics.hpp>

namespace TepeGolo
{

    class SplashState : public Etat
    {
    public:
        SplashState(GameDataRef data);

        void Init();

        void GererEntrer();
        void Update(float dt);
        void Dessiner(float dt);

    protected:
    private:
        GameDataRef _data;
        sf::Clock _clock;
        sf::Texture _backgroundTexture;
        sf::Sprite _background;
    };

} // namespace TepeGolo
