#include "elementos.h"
#include<iostream>

elementos::elementos(){
	element_text.loadFromFile("imagenes/elements.png");
	_element.setTexture(element_text);
	_element.setPosition(325, 400);
	_element.setScale(230.f / element_text.getSize().x, 80.f / element_text.getSize().y);
	_origen = { 0,0 };
	_limite = { 551,180 };
	_elemento_seleccionado = false;
	_elemento = 0;
}

sf::Sprite& elementos::getdraw(){
	return _element;
}

void elementos::cmd(){
	
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		_elemento = 1;
	} //aire
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		_elemento = 2;
	}//tierra
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		_elemento = 3;
	}//fuego
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		_elemento = 4;
	}//agua
	
}

void elementos::update(){
	if (_elemento!=0){
		_elemento_seleccionado == true;
	}
}

void elementos::setelemento(int elemento){
	_elemento = elemento;
}

void elementos::setframe(){
	sf::IntRect posicion(_origen.x , _origen.y, _limite.x, _limite.y);

	_element.setTextureRect(posicion);
}

int elementos::getelemento(){

	return _elemento;
}

bool elementos::get_elemento_seleccionado(){
	
	return _elemento_seleccionado;
}

void elementos::set_elemento_seleccionado(bool elemento){

	_elemento_seleccionado = elemento;
}

