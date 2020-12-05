#include "Personaje.h"


Personaje::Personaje(){
	
	_ataque = uno;
}

void Personaje::cmd(){

}

void Personaje::update(){

}

int Personaje::get_vida(){
	return _vida;
}

void Personaje::set_vida(int daño){
	_vida -= daño;
}

void Personaje::set_tamañodevida(int vida){
	_vida = vida;
}


