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

void Personaje::set_vida(int da�o){
	_vida -= da�o;
}

void Personaje::set_tama�odevida(int vida){
	_vida = vida;
}


