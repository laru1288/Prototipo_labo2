#include "ataques.h"

ataques::ataques(){
	_tex_ataque_comun.loadFromFile("imagenes/enemigos/ataques_orco/32.png");
	_text_ataque_esp.loadFromFile("imagenes/enemigos/23.png");
	_tex_ataque_pj.loadFromFile("imagenes/PJ/ataque.png");
	_tex_ataque_pj_esp.loadFromFile("imagenes/PJ/201.png");
		
	totaltime = 0.0f;
	switchtime = 0.025f;
}

ataques::~ataques(){}

void ataques::update(float deltatime) {
	frame_actual_ataque.y = 0;
	totaltime = deltatime;
	if (totaltime >= switchtime) {
		totaltime -= switchtime;
		frame_actual_ataque.x++;
		if (frame_actual_ataque.x >= cant_x_ataque) {
			frame_actual_ataque.x = 0;
		}


	}
	uvRect.left = frame_actual_ataque.x * uvRect.width;
	uvRect.top = frame_actual_ataque.y * uvRect.height;
	
}

void ataques::cargar_textura_en(int num_dado){
	//ataque comun
	
	if (num_dado == 6) {
		_sp_ataque_enemigo.setTexture(_tex_ataque_comun);
		_sp_ataque_enemigo.setScale(1, 1);
		_sp_ataque_enemigo.setPosition(400, 400);
		cant_x_ataque = 6;
		cant_y_ataque = 1;
		frame_actual_ataque = { 0, 0 };
		frame_size_ataque = sf::Vector2f(_tex_ataque_comun.getSize().x / cant_x_ataque, _tex_ataque_comun.getSize().y / cant_y_ataque);
		_sp_ataque_enemigo.setTextureRect(sf::IntRect(frame_actual_ataque.x * frame_size_ataque.x, frame_actual_ataque.y * frame_size_ataque.x, frame_size_ataque.x, frame_size_ataque.y));
		uvRect.width = _tex_ataque_comun.getSize().x / cant_x_ataque;
		uvRect.height = _tex_ataque_comun.getSize().y / cant_y_ataque;
	}

	//ataque especial
	if (num_dado != 6) {
		_sp_ataque_enemigo.setTexture(_text_ataque_esp);
		_sp_ataque_enemigo.setScale(1, 1);
		_sp_ataque_enemigo.setPosition(400, 400);
		cant_x_ataque = 5;
		cant_y_ataque = 1;
		frame_actual_ataque = { 0, 0 };
		frame_size_ataque = sf::Vector2f(_text_ataque_esp.getSize().x / cant_x_ataque, _text_ataque_esp.getSize().y / cant_y_ataque);
		_sp_ataque_enemigo.setTextureRect(sf::IntRect(frame_actual_ataque.x * frame_size_ataque.x, frame_actual_ataque.y * frame_size_ataque.x, frame_size_ataque.x, frame_size_ataque.y));
		uvRect.width = _text_ataque_esp.getSize().x / cant_x_ataque;
		uvRect.height = _text_ataque_esp.getSize().y / cant_y_ataque;
	}






}

void ataques::cargar_textura_pj(int num_dado){
	//ataque comun
	if (num_dado != 6) {
		_sp_ataque_pj.setTexture(_tex_ataque_pj);
		_sp_ataque_pj.setScale(1, 1);
		_sp_ataque_pj.setPosition(400, 400);
		cant_x_ataque = 5;
		cant_y_ataque = 1;
		frame_actual_ataque = { 0, 0 };
		frame_size_ataque = sf::Vector2f(_tex_ataque_pj.getSize().x / cant_x_ataque, _tex_ataque_pj.getSize().y / cant_y_ataque);
		_sp_ataque_pj.setTextureRect(sf::IntRect(frame_actual_ataque.x * frame_size_ataque.x, frame_actual_ataque.y * frame_size_ataque.x, frame_size_ataque.x, frame_size_ataque.y));
		uvRect.width = _tex_ataque_pj.getSize().x / cant_x_ataque;
		uvRect.height = _tex_ataque_pj.getSize().y / cant_y_ataque;
	}
	//ataque especial
	if (num_dado == 6) {
		_sp_ataque_pj.setTexture(_tex_ataque_pj_esp);
		_sp_ataque_pj.setScale(1, 1);
		_sp_ataque_pj.setPosition(400, 400);
		cant_x_ataque = 4;
		cant_y_ataque = 1;
		frame_actual_ataque = { 0, 0 };
		frame_size_ataque = sf::Vector2f(_tex_ataque_pj_esp.getSize().x / cant_x_ataque, _tex_ataque_pj_esp.getSize().y / cant_y_ataque);
		_sp_ataque_pj.setTextureRect(sf::IntRect(frame_actual_ataque.x * frame_size_ataque.x, frame_actual_ataque.y * frame_size_ataque.x, frame_size_ataque.x, frame_size_ataque.y));
		uvRect.width = _tex_ataque_pj_esp.getSize().x / cant_x_ataque;
		uvRect.height = _tex_ataque_pj_esp.getSize().y / cant_y_ataque;

	}

}

void ataques::setframe(){
	_sp_ataque_enemigo.setTextureRect(uvRect);
	_sp_ataque_pj.setTextureRect(uvRect);
	_sp_ataque_enemigo.move(2, 0);
	_sp_ataque_pj.move(2, 0);

}

sf::Sprite& ataques::getdraw_ataque_en(){
	return  _sp_ataque_enemigo;
}

sf::Sprite& ataques::getdraw_ataque_pj() {
	return _sp_ataque_pj;
}