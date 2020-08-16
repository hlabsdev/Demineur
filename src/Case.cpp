#include "Case.hpp"

namespace TepeGolo{
    //Case::Case(GameDataRef data): _data(data){

    Case::Case(){
        this->_data->assets.LoadTexture("Case Dos", CASE_DOS_PATH);
        this->_data->assets.LoadTexture("Case Vide", CASE_VIDE_PATH);
        this->_data->assets.LoadTexture("Mine1", UN);
        this->_data->assets.LoadTexture("Mine2", DEUX);
        this->_data->assets.LoadTexture("Mine3", TROIS);
        this->_data->assets.LoadTexture("Mine4", QUATRE);
        this->_data->assets.LoadTexture("Case Minee", CASE_MINEE_PATH);
        this->_data->assets.LoadTexture("Case Marquee", DRAPEAU);

        _estDecouvers = _estMarque = _estMinee = false;

        _face.setTexture(this->_data->assets.GetTexture("Case Dos"));
        _face.setColor(sf::Color(255,255,255,255));
        nombreCaseMineVoisine = 0;
    }

    void Case::afficher(sf::RenderWindow& fenetre){
        fenetre.draw(this->_face);
    }

    void Case::decouvrir(){
        if(this->_estDecouvers == false){
            if(this->_estMinee == true){
                this->_face.setTexture(this->_data->assets.GetTexture("Case Minee"));
            }
            else if(this->nombreCaseMineVoisine == 0){
                this->_face.setTexture(this->_data->assets.GetTexture("Case Vide"));
            }
            /*else if(this->nombreCaseMineVoisine > 0){
                string nbrMine = "Mine" + string(nombreCaseMineVoisine);
                this->_face.setTexture(this->_data->assets.GetTexture(nbrMine));
                _estMarque = true;
            }*/
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
        this->_face.setTexture(this->_data->assets.GetTexture("Case Minee"));
        _estMinee = true;
    }

    void Case::placerCase(float x, float y){
        this->_face.setPosition(x, y);
        this->setPlace(x,y);
    }

    void Case::Marquer(){
        if(this->_estMarque == true){
            this->_face.setTexture(this->_data->assets.GetTexture("Case Dos"));
            _estMarque = false;
        }
        else{
            this->_face.setTexture(this->_data->assets.GetTexture("Case Marquee"));
            _estMarque = true;
        }

    }


}
