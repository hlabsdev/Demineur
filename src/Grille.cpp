#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include "Grille.hpp"
#include "GameOverState.hpp"
#include "MainMenuState.hpp"
#include "PauseState.hpp"
#include "Case.hpp"
#include "DEFINITIONS.hpp"

using namespace std;

namespace TepeGolo{
    Grille::Grille(GameDataRef data):_data(data){}

	void Grille::Init(){
		gameState = STATE_PLAYING;
		_temps.restart();

		this->_data->assets.LoadTexture("Button Pause", PAUSE_BUTTON);
		this->_data->assets.LoadTexture("Grid Sprite", GRID_SPRITE_FILEPATH);
		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Case", CASE_DOS_PATH);
		this->_data->assets.LoadTexture("Case Vide", CASE_VIDE_PATH);
		this->_data->assets.LoadTexture("Case Minee", CASE_MINEE_PATH);
		this->_data->assets.LoadTexture("Case Marquee", DRAPEAU);
		this->_data->assets.LoadFont("Arial", FONT_ONE);

		for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                _cases[i][j] = Case();
            }
		}

        _chrono.setFont(this->_data->assets.GetFont("Arial"));
        _chrono.setString("000");

        _drapeauRestants.setFont(this->_data->assets.GetFont("Arial"));
        _drapeauRestants.setString("00");

		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		_pauseButton.setTexture(this->_data->assets.GetTexture("Button Pause"));
		_gridSprite.setTexture(this->_data->assets.GetTexture("Grid Sprite"));

		//_pauseButton.setPosition( this->_data->fenetre.getSize().x - _pauseButton.getLocalBounds().width, _pauseButton.getPosition().y );

		_drapeauRestants.setPosition( 600, _drapeauRestants.getPosition().y);
		_chrono.setPosition(50, _chrono.getPosition().y );
		_gridSprite.setPosition( (SCREEN_WIDTH/2)- (_gridSprite.getGlobalBounds().width/2), (SCREEN_HEIGHT/2)- (_gridSprite.getGlobalBounds().height/2) );

		InitCase();
		for(int x=0; x<9; x++){
            for(int y=0; y<9; y++){
                gridArray[x][y]=VIDE;
            }
		}
	}

	void Grille::GererEntrer(){
		sf::Event event;

		while (this->_data->fenetre.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->fenetre.close();
			}

			if (this->_data->imput.IsSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->fenetre))
			{
				// PAUSE
				this->_data->machine.AjoutEtat(EtatRef(new PauseState(_data, *this)));

			}
			else if(this->_data->imput.IsSpriteClicked(this->_gridSprite, sf::Mouse::Left, this->_data->fenetre)){
                this->ClickGauche();
			}
			else if(this->_data->imput.IsSpriteClicked(this->_gridSprite, sf::Mouse::Right, this->_data->fenetre)){
                this->ClickDroit();
			}
		}
	}

	void Grille::Update(float dt){
        if(STATE_DRAW == gameState || STATE_LOSE == gameState || STATE_WON == gameState){
            if(this->_temps.getElapsedTime().asSeconds() > TEMPS_AVANT_GAME_OVER){
                this->_data->machine.AjoutEtat(EtatRef(new GameOverState(_data)), true);
            }
        }

        if(this->firstClick != true){
            _temps.restart();
            _elapse = sf::seconds(0);
        }

        this->_drapeauRestants.setString(to_string(this->nbMine));
        this->_elapse = _temps.getElapsedTime();
        this->_chrono.setString(to_string(int(this->_elapse.asSeconds())));
	}

	void Grille::Dessiner(float dt){
		this->_data->fenetre.clear(sf::Color::Red);

		this->_data->fenetre.draw( this->_background );

		//this->_data->fenetre.draw( this->_pauseButton );
		this->_data->fenetre.draw( this->_chrono );
		this->_data->fenetre.draw( this->_drapeauRestants );
		this->_data->fenetre.draw( this->_gridSprite );
		for(int x=0; x<9; x++){
            for(int y=0; y<9; y++){
                _cases[x][y].afficher(this->_data->fenetre);
            }
		}

		this->_data->fenetre.display();
	}

	void Grille::InitCase(){
		sf::Vector2u tempSpriteSize = this->_data->assets.GetTexture("Case").getSize();
		this->GenererMine();

		for (int x = 0; x < 9; x++)
		{
			for (int y = 0; y < 9; y++)
			{
				_cases[x][y].placerCase(_gridSprite.getPosition().x + (tempSpriteSize.x * x) + 7, _gridSprite.getPosition().y + (tempSpriteSize.y * y) + 7);
			}
		}
	}

	void Grille::ClickGauche(){
	    sf::Vector2i posClick = this->_data->imput.GetMousePosition(this->_data->fenetre);
	    sf::FloatRect tailleGrille = _gridSprite.getGlobalBounds();
	    sf::Vector2f espace = sf::Vector2f((SCREEN_WIDTH - tailleGrille.width)/2, (SCREEN_HEIGHT-tailleGrille.height)/2);
	    sf::Vector2f posSurGrille = sf::Vector2f(posClick.x-espace.x, posClick.y-espace.y);

	    sf::Vector2f tailleCase = sf::Vector2f(tailleGrille.width/9, tailleGrille.height/9);
	    int colonne, ligne;

        //Determinons la colonne
	    if(posSurGrille.x < tailleCase.x){
            colonne =1;
	    }
	    else if(posSurGrille.x < tailleCase.x*2){
            colonne =2;
	    }
	    else if(posSurGrille.x < tailleCase.x*3){
            colonne =3;
	    }
	    else if(posSurGrille.x < tailleCase.x*4){
            colonne =4;
	    }
	    else if(posSurGrille.x < tailleCase.x*5){
            colonne =5;
	    }
	    else if(posSurGrille.x < tailleCase.x*6){
            colonne =6;
	    }
	    else if(posSurGrille.x < tailleCase.x*7){
            colonne =7;
	    }
	    else if(posSurGrille.x < tailleCase.x*8){
            colonne =8;
	    }
	    else if(posSurGrille.x < tailleGrille.width){
            colonne =9;
	    }

        //Determinons la ligne
	    if(posSurGrille.y < tailleCase.y){
            ligne =1;
	    }
	    else if(posSurGrille.y < tailleCase.y*2){
            ligne =2;
	    }
	    else if(posSurGrille.y < tailleCase.y*3){
            ligne =3;
	    }
	    else if(posSurGrille.y < tailleCase.y*4){
            ligne =4;
	    }
	    else if(posSurGrille.y < tailleCase.y*5){
            ligne =5;
	    }
	    else if(posSurGrille.y < tailleCase.y*6){
            ligne =6;
	    }
	    else if(posSurGrille.y < tailleCase.y*7){
            ligne =7;
	    }
	    else if(posSurGrille.y < tailleCase.y*8){
            ligne =8;
	    }
	    else if(posSurGrille.y < tailleGrille.height){
            ligne =9;
	    }

        if(this->firstClick != true){
            _cases[colonne-1][ligne-1].decouvrir();
            _temps.restart();
            firstClick = true;
        }
        else{
            _cases[colonne-1][ligne-1].decouvrir();
        }
        if(_cases[colonne-1][ligne-1]._estMinee){
            this->MontrerMines();
            gameState = STATE_LOSE;
        }
	}

	void Grille::ClickDroit(){
	    sf::Vector2i posClick = this->_data->imput.GetMousePosition(this->_data->fenetre);
	    sf::FloatRect tailleGrille = _gridSprite.getGlobalBounds();
	    sf::Vector2f espace = sf::Vector2f((SCREEN_WIDTH - tailleGrille.width)/2, (SCREEN_HEIGHT-tailleGrille.height)/2);
	    sf::Vector2f posSurGrille = sf::Vector2f(posClick.x-espace.x, posClick.y-espace.y);

	    sf::Vector2f tailleCase = sf::Vector2f(tailleGrille.width/9, tailleGrille.height/9);
	    int colonne, ligne;

        //Determinons la colonne
	    if(posSurGrille.x < tailleCase.x){
            colonne =1;
	    }
	    else if(posSurGrille.x < tailleCase.x*2){
            colonne =2;
	    }
	    else if(posSurGrille.x < tailleCase.x*3){
            colonne =3;
	    }
	    else if(posSurGrille.x < tailleCase.x*4){
            colonne =4;
	    }
	    else if(posSurGrille.x < tailleCase.x*5){
            colonne =5;
	    }
	    else if(posSurGrille.x < tailleCase.x*6){
            colonne =6;
	    }
	    else if(posSurGrille.x < tailleCase.x*7){
            colonne =7;
	    }
	    else if(posSurGrille.x < tailleCase.x*8){
            colonne =8;
	    }
	    else if(posSurGrille.x < tailleGrille.width){
            colonne =9;
	    }

        //Determinons la ligne
	    if(posSurGrille.y < tailleCase.y){
            ligne =1;
	    }
	    else if(posSurGrille.y < tailleCase.y*2){
            ligne =2;
	    }
	    else if(posSurGrille.y < tailleCase.y*3){
            ligne =3;
	    }
	    else if(posSurGrille.y < tailleCase.y*4){
            ligne =4;
	    }
	    else if(posSurGrille.y < tailleCase.y*5){
            ligne =5;
	    }
	    else if(posSurGrille.y < tailleCase.y*6){
            ligne =6;
	    }
	    else if(posSurGrille.y < tailleCase.y*7){
            ligne =7;
	    }
	    else if(posSurGrille.y < tailleCase.y*8){
            ligne =8;
	    }
	    else if(posSurGrille.y < tailleGrille.height){
            ligne =9;
	    }

	    /*if(this->nbMine <= 0 && _cases[colonne-1][ligne-1]._estMarque == false){
                //marquer
            _cases[colonne-1][ligne-1].Marquer();
            nbMine -= 1;
        }
        else if(this->nbMine <= 0 && _cases[colonne-1][ligne-1]._estMarque ==  true){
            //Demarquer
             _cases[colonne-1][ligne-1].Marquer();
            nbMine += 1;
        }*/
        _cases[colonne-1][ligne-1].Marquer();
	}

	void Grille::GenererMine(){
        srand(time(NULL));
        int mineRestantAPlacer = 11;

        while (mineRestantAPlacer > 0) {
            int x(rand() % 9);
            int y(rand() % 9);

            _cases[x][y].placerMine();
            if (_cases[x][y]._estMinee){
                mineRestantAPlacer--;
                if (x!=0 && y!=0){
                    _cases[x][y-1].ajoutVoisin();
                    _cases[x][y+1].ajoutVoisin();

                    _cases[x-1][y].ajoutVoisin();
                    _cases[x+1][y].ajoutVoisin();
                }
                else if (x==0 && y==0){
                    _cases[x][y-1].ajoutVoisin();
                    _cases[x+1][y].ajoutVoisin();

                    _cases[x-1][y].ajoutVoisin();
                    _cases[x+1][y].ajoutVoisin();
                }
                else if (x==0 && y!=0){
                    _cases[x][y-1].ajoutVoisin();
                    _cases[x][y+1].ajoutVoisin();
                    _cases[x+1][y].ajoutVoisin();
                }
                else if (x!=0 && y==0){
                    _cases[x][y].ajoutVoisin();
                    _cases[x-1][y+1].ajoutVoisin();
                    _cases[x+1][y].ajoutVoisin();
                }

            }

        }
	}

	void Grille::MontrerMines(){
	    for(int x=0; x<9; x++){
            for(int y=0; y<9; y++){
                if(_cases[x][y]._estMinee){
                    _cases[x][y].decouvrir();
                };
            }
        }
	}

}//namespace TepeGolo
