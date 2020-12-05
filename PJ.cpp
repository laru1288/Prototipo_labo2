#include "PJ.h"

PJ::PJ():Personaje(){
	
	cargar_textura("imagenes/PJ/pj.png");
	_sp_personaje.setTexture(_tex_personaje);
	_sp_personaje.setPosition(0,400);
	// position =_sp_personaje.getPosition();
	_sp_personaje.setTextureRect(sf::IntRect(0, 0, 40, 47));
	//movementspeed = 100.f;
	

	 walk = 0;
	
	_estado = estados::quieto;
	
}
void PJ::cargar_textura(std::string textura) {
	_tex_personaje.loadFromFile(textura);
	
}

void PJ::cmd() {
	const float movementspeed = 50.f;
	velocity.y = 0.f;
	velocity.x = 0.f;
	dt = clock.restart().asSeconds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		_estado = caminando_derecha;
		velocity.x += movementspeed * dt;
		//_sp_personaje.move(velocity);
		_sp_personaje.move(1, 0);
		_sp_personaje.setTextureRect(sf::IntRect(walk * 44, 48 * 2, 46, 48));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		_estado = caminando_izquierda;
		velocity.x += -movementspeed * dt;
		//_sp_personaje.move(velocity);
		_sp_personaje.move(-1, 0);
		_sp_personaje.setTextureRect(sf::IntRect(walk * 46, 48 * 1, 44, 48));
	}

	if (walk == 2) {
		walk = 0;
	}

	if (_sp_personaje.getPosition().x < 0) _sp_personaje.setPosition(0, _sp_personaje.getPosition().y);
	if (_sp_personaje.getPosition().x + _sp_personaje.getGlobalBounds().width > 900) _sp_personaje.setPosition(900 - _sp_personaje.getGlobalBounds().width, _sp_personaje.getPosition().y);
	
	walk++;

}

void PJ::update() {
	bottom = _sp_personaje.getPosition().y + _sp_personaje.getOrigin().y;
	left = _sp_personaje.getPosition().x;
	right = _sp_personaje.getPosition().x + _sp_personaje.getOrigin().x;
	top = _sp_personaje.getPosition().y;
}

sf::Sprite& PJ::get_draw_pj(){
	return _sp_personaje;
}

void PJ::setframe(){
	

}

void PJ::set_arma(int num){
	
	
}

skills_pj PJ::get_arma(){

	return skills_pj();
}



