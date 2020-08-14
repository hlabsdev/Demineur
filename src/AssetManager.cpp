#include "AssetManager.hpp"
#include <SFML/Graphics.hpp>

namespace TepeGolo
{
    // Textures
    void AssetManager::LoadTexture(std::string nom, std::string fichier)
    {
        sf::Texture tex;
        if (tex.loadFromFile(fichier))
        {
            this->_textures[nom] = tex;
        }
    }

    sf::Texture &AssetManager::GetTexture(std::string nom)
    {
        return this->_textures.at(nom);
    }
    // Fonts
    void AssetManager::LoadFont(std::string nom, std::string fichier)
    {
        sf::Font font;
        if (font.loadFromFile(fichier))
        {
            this->_fonts[nom] = font;
        }
    }

    sf::Font &AssetManager::GetFont(std::string nom)
    {
        return this->_fonts.at(nom);
    }

} // namespace TepeGolo
