#pragma once
#include <SFML/Graphics.hpp>

namespace TepeGolo {
    class ImputManager {
    public:
        ImputManager(){};
        ~ImputManager(){};

        bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &fenetre);

        sf::Vector2i GetMousePosition(sf::RenderWindow &fenetre);
    private:
    };

}
