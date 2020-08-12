#pragma once
#include <map>
#include <SFML/Graphics.hpp>

namespace TepeGolo {
    class AssetManager
    {
    public:
        AssetManager(){};
        ~AssetManager(){};

        void LoadTexture(std::string nom, std::string fichier);
        sf::Texture &GetTexture(std::string nom);

        void LoadFont(std::string nom, std::string fichier);
        sf::Font &GetFont(std::string nom);

    protected:

    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
    };
}

