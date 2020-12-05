#include "Dados.h"
#include<iostream>


Dados::Dados(){
	carga_textura("imagenes/dados/dados.png");
	_fuente.loadFromFile("fuente/fuente.ttf");
	_texto.setFont(_fuente);
	_texto.setString("ENTER");
	_texto.setCharacterSize(36);
	_texto.setPosition(465, 180);	
	_texto.setFillColor(sf::Color::Magenta);
	_dado.setTexture(_dados);
	_dado.setPosition(500, 230);
	_dado.setScale(2, 2);
	_frame_cara_dado.x = _frame_movimiento.y= 0;
	_frame_cara_dado.y = _frame_movimiento.x = 1;	
	_dado_lanzado = false;

}

void Dados::cmd(){

}

void Dados::update(){
	if(_dado_lanzado){
		_frame_cara_dado.x = _numero_dado - 1;
     }
}

sf::Sprite& Dados::getdraw(){   return _dado; }

sf::Text& Dados::getdrawtext() { return _texto; }

void Dados::carga_textura(std::string archivo){
	_dados.loadFromFile(archivo);
}
int Dados::get_numero_dado(){	return _numero_dado;}

void Dados::set_numero_dado(int numero){
	_numero_dado = numero;
}

bool Dados::get_dadolanzado(){
	return _dado_lanzado;
}

void Dados::setframe_movimiento() {
	sf::IntRect posicion(_frame_movimiento.x * 17, _frame_movimiento.y * 24,17, 24);

	_dado.setTextureRect(posicion);
}

void Dados::setframe_cara_dado(){
	sf::IntRect posicion(_frame_cara_dado.x * 17, _frame_cara_dado.y * 24, 17, 17);

	_dado.setTextureRect(posicion);
}

void Dados::reset_movimiento(){
	_dado_lanzado = false;
	_frame_movimiento.x = 1;
	_frame_movimiento.y = 0;
}

void Dados::movimiento_dado(){
	if (_dado_lanzado==false) {
		_frame_movimiento.x++;
			if (_frame_movimiento.x == 4) _frame_movimiento.x=1;

	}

}

void Dados::lanzar_dado(){
	
	//srand(time(NULL));
	_numero_dado= 1 + rand() % 6;
	_dado_lanzado = true;
}
