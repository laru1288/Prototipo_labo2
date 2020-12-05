#include "dragon.h"

dragon::dragon() {
	cargar_textura();
	_sp_dragon.setTexture(_tex_personaje);
	_sp_dragon.setScale(1, 1);
	_sp_dragon.setPosition(600, 350);
	cant_x = 3;
	cant_y = 4;
	frame_actual = { 0, 0 };
	frame_size = sf::Vector2f(_tex_personaje.getSize().x / cant_x, _tex_personaje.getSize().y / cant_y);
	_sp_dragon.setTextureRect(sf::IntRect(frame_actual.x * frame_size.x, frame_actual.y * frame_size.x, frame_size.x, frame_size.y));
	totaltime = 0.0f;
	switchtime = 0.025f;
	uvRect.width = _tex_personaje.getSize().x / cant_x;
	uvRect.height = _tex_personaje.getSize().y / cant_y;
	this->imagecount.x = 3;
	this->imagecount.y = 4;
}

void dragon::update(float deltatime) {
	frame_actual.y = 1;
	totaltime = deltatime;
	if (totaltime >= switchtime) {
		totaltime -= switchtime;
		frame_actual.x++;
		if (frame_actual.x >= imagecount.x) {
			frame_actual.x = 0;
		}


	}

	uvRect.left = frame_actual.x * uvRect.width;
	uvRect.top = frame_actual.y * uvRect.height;

	//realizado por enrique
	/*frame_actual.x++;
	if (frame_actual.x == 5 ) {
		frame_actual.x = 0;

	}*/
}



sf::Sprite& dragon::getdraw() {
	return _sp_dragon;
}

void dragon::cargar_textura() {
	_tex_personaje.loadFromFile("imagenes/enemigos/dragon.png");
}

void dragon::cmd() {

}

void dragon::setframe() {
	sf::IntRect posicion((int)frame_size.x * frame_actual.x, (int)frame_size.y * frame_actual.y, (int)frame_size.x, (int)frame_size.y);
	_sp_dragon.setTextureRect(uvRect);
}


