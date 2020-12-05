#include "troll.h"

troll::troll() {
	cargar_textura();
	_sp_troll.setTexture(_tex_personaje);
	_sp_troll.setScale(1, 1);
	_sp_troll.setPosition(550, 350);
	cant_x = 9;
	cant_y = 9;
	frame_actual = { 0, 0 };
	frame_size = sf::Vector2f(_tex_personaje.getSize().x / cant_x, _tex_personaje.getSize().y / cant_y);
	_sp_troll.setTextureRect(sf::IntRect(frame_actual.x * frame_size.x, frame_actual.y * frame_size.x, frame_size.x, frame_size.y));
	totaltime = 0.0f;
	switchtime = 0.025f;
	uvRect.width = _tex_personaje.getSize().x / cant_x;
	uvRect.height = _tex_personaje.getSize().y / cant_y;
	this->imagecount.x = 9;
	this->imagecount.y = 9;
}

void troll::update(float deltatime) {
	frame_actual.y = 5;
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



sf::Sprite& troll::getdraw() {
	return _sp_troll;
}

void troll::cargar_textura() {
	_tex_personaje.loadFromFile("imagenes/enemigos/troll1.png");
}

void troll::cmd() {

}

void troll::setframe() {
	sf::IntRect posicion((int)frame_size.x * frame_actual.x, (int)frame_size.y * frame_actual.y, (int)frame_size.x, (int)frame_size.y);
	_sp_troll.setTextureRect(uvRect);
}

