#include "vida_enemigo.h"

vida_enemigo::vida_enemigo() {
	life__enemy_bar.loadFromFile("imagenes/enemy_bar.png");
	_life_enemy.setTexture(life__enemy_bar);
	_life_enemy.setPosition(750, 0.5);
	_life_enemy.setTextureRect(sf::IntRect(0, 65*7, 147, 64));
	_life_enemy.setScale(1,1);
	reallife = 5000;
	
}
sf::Sprite& vida_enemigo::getdraw() {
	return _life_enemy;
}

void vida_enemigo::cmd() {
	int real = reallife;
	if (real == 5000) { aux_frame = 7; }
	if (real == 4500) { aux_frame=6; }
	if (real == 4000) { aux_frame=5; }
	if (real == 3500) { aux_frame=4;}
	if (real == 3500) { aux_frame=3;}
	if (real == 300)  { aux_frame=2; }
	if (real == 2500) { aux_frame=1; }
	if (real == 2500) { aux_frame = 0; }
		if (real = 0 || real < 0) murio = true;
	
}


void vida_enemigo::setvida(int num) {
	reallife = num;
}

int vida_enemigo::getvida() {
	return reallife;
}

void vida_enemigo::setframe(){
	sf::IntRect posicion(0, aux_frame * 65, 147, 64);

	_life_enemy.setTextureRect(posicion);
}

