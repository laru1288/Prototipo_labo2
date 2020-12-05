#include "vida_personaje.h"

vida_personaje::vida_personaje(){
	life_bar.loadFromFile("imagenes/life_bar.png");
	_life.setTexture(life_bar);
	_life.setPosition(0,0);
	_life.setTextureRect(sf::IntRect(0, 0, 31,4));
	_life.setScale(8,8);
	reallife = 5000;
}

sf::Sprite& vida_personaje::getdraw(){
	return _life;
	}

void vida_personaje::cmd(){
	  
	if (reallife == 5000) {aux_frame = 0;}
	if (reallife == 4500) { aux_frame = 1; }
	if (reallife == 4000) { aux_frame =2;}
	if (reallife == 3500) { aux_frame =3; }
	if (reallife== 3500) { aux_frame =4; }
	if (reallife == 2500) { aux_frame =6; }
	if (reallife == 2000) { aux_frame =7; }
	if (reallife == 1500) { aux_frame =8; }
	if (reallife == 1000) { aux_frame =9; }
	if (reallife == 0 || reallife < 0) murio= true;
	
}


void vida_personaje::setvida(int num){
	reallife = num;
}

int vida_personaje::getvida(){
	return reallife ;
}

void vida_personaje::setframe(){

	sf::IntRect posicion(0, aux_frame * 4, 31, 4);

	_life.setTextureRect(posicion);
}

/*
void vida_personaje::update(sf::Sprite,int vida, int danio){



}*/


