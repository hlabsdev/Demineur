#include "ImputManager.hpp"

namespace TepeGolo
{
    bool ImputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &fenetre)
    {
        if (sf::Mouse::isButtonPressed(button))
        {
            sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

            if (tempRect.contains(sf::Mouse::getPosition(fenetre)))
            {
                return true;
            }
        }
        return false;
    }

    sf::Vector2i ImputManager::GetMousePosition(sf::RenderWindow& fenetre)
    {
        return sf::Mouse::getPosition(fenetre);
    }

} // namespace TepeGolo
