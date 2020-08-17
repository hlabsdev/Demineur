#include "Case.hpp"
using namespace std;

namespace TepeGolo{

    Case::Case(){
        _data->assets.LoadTexture("CaseDos", CASE_DOS_PATH);
        _data->assets.LoadTexture("CaseVide", CASE_VIDE_PATH);
        _data->assets.LoadTexture("Mine1", UN);
        _data->assets.LoadTexture("Mine2", DEUX);
        _data->assets.LoadTexture("Mine3", TROIS);
        _data->assets.LoadTexture("Mine4", QUATRE);
        _data->assets.LoadTexture("CaseMinee", CASE_MINEE_PATH);
        _data->assets.LoadTexture("CaseMarquee", DRAPEAU);

        _face.setTexture(this->_data->assets.GetTexture("CaseDos"));
        _face.setColor(sf::Color(255,255,255,255));
        nombreCaseMineVoisine = 0;
    }

    void Case::afficher(sf::RenderWindow& fenetre){
        fenetre.draw(this->_face);
    }

    void Case::decouvrir(){
        if(this->_estDecouvers == false){
            if(this->_estMinee == true){
                _face.setTexture(this->_data->assets.GetTexture("CaseMinee"));
            }
            else if(this->nombreCaseMineVoisine == 0){
                _face.setTexture(this->_data->assets.GetTexture("CaseVide"));
            }
            else if(this->nombreCaseMineVoisine > 0){
                string nbrMine = "Mine" + to_string(nombreCaseMineVoisine);
                this->_face.setTexture(this->_data->assets.GetTexture(nbrMine));
                _estMarque = true;
            }
            _face.setColor(sf::Color(255,255,255,255));
            _estDecouvers = true;
        }
    }

    void Case::setPlace(float x, float y){
        _x = x;
        _y = y;
    }

    float Case::getPlace(){
        return(this->_x, this->_y);
    }

    void Case::placerMine(){
        _estMinee = true;
    }

    void Case::placerCase(float x, float y){
        _face.setPosition(x, y);
        setPlace(x,y);
    }

    void Case::Marquer(){
        if(this->_estMarque == true){
            _face.setTexture(this->_data->assets.GetTexture("CaseDos"));
            _estMarque = false;
        }
        else{
            _face.setTexture(this->_data->assets.GetTexture("CaseMarquee"));
            _estMarque = true;
        }
    }

    void Case::ajoutVoisin(){
        this->nombreCaseMineVoisine +=1;
    }


}
