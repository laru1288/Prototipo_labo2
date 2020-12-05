#include "balrog.h"

balrog::balrog() {
	cargar_textura();
	_sp_balrog.setTexture(_tex_personaje);
	_sp_balrog.setScale(1, 1);
	_sp_balrog.setPosition(600, 275);
	cant_x = 2;
	cant_y = 1;
	frame_actual = { 0, 0 };
	frame_size = sf::Vector2f(_tex_personaje.getSize().x / cant_x, _tex_personaje.getSize().y / cant_y);
	_sp_balrog.setTextureRect(sf::IntRect(frame_actual.x * frame_size.x, frame_actual.y * frame_size.x, frame_size.x, frame_size.y));
	totaltime = 0.3f;
	switchtime = 0.1f;
	uvRect.width = _tex_personaje.getSize().x / cant_x;
	uvRect.height = _tex_personaje.getSize().y / cant_y;
	

}

void balrog::update(float deltatime) {
	//deltatime = clock.restart().asSeconds();
	frame_actual.y = 0;
	totaltime = deltatime;
	if (totaltime >= switchtime) {
		totaltime -= switchtime;
		frame_actual.x++;
		if (frame_actual.x >= cant_x) {
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



sf::Sprite& balrog::getdraw() {
	return _sp_balrog;
}

void balrog::cargar_textura() {
	_tex_personaje.loadFromFile("imagenes/enemigos/balrog1.png");
}

void balrog::cmd() {

}

void balrog::setframe() {
	sf::IntRect posicion((int)frame_size.x * frame_actual.x, (int)frame_size.y * frame_actual.y, (int)frame_size.x, (int)frame_size.y);
	_sp_balrog.setTextureRect(uvRect);
}

