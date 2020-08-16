#include "Case.hpp"

namespace TepeGolo{
    Case::Case(GameDataRef data): _data(data){
        this->_data->assets.LoadTexture("Case Vide", CASE_VIDE_PATH);
        this->_face.setTexture(this->_data->assets.GetTexture("Case Vide"));
    }

    void Case::afficher(sf::RenderWindow& fenetre){
        fenetre.draw(this->_face);
    }

    void Case::setPosition(float x, float y){
        this->_x = x;
        this->_y = y;
    }

    void Case::tourner(){

    }
}
