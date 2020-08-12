#include "Game.hpp"
#include "SplashState.hpp"

namespace TepeGolo {
    Game::Game(int largeur, int hauteur, std::string titre) {
        //_data->fenetre.create(sf::VideoMode(largeur, hauteur), titre, sf::Style::Close|sf::Style::Titlebar);
        _data->fenetre.create(sf::VideoMode(largeur, hauteur), titre, sf::Style::Close | sf::Style::Titlebar);
        //_data->machine.AjoutEtat(EtatRef(new SplashState(this->_data)));
        _data->machine.AjoutEtat(EtatRef(new SplashState(this->_data)));


        this->Run();
    }

    void Game::Run() {
        float newTime, frameTime, interpolation;
        float currentTime = this->_clock.getElapsedTime().asSeconds();

        float accumulateur = 0.0f;

        while (this->_data->fenetre.isOpen()) {
            this->_data->machine.ProcessEtatChange();

            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if (frameTime > 0.25f) {
                frameTime = 0.25;
            }
            currentTime = newTime;
            accumulateur += frameTime;

            while (accumulateur>=dt) {
                this->_data->machine.GetActiveEtat()->GererEntrer();
                this->_data->machine.GetActiveEtat()->Update(dt);

                accumulateur -= dt;
            }

            interpolation = accumulateur/dt;
            this->_data->machine.GetActiveEtat()->Dessiner(interpolation);
        }
    }
}
