#include "NuevaPartida.h"

Nueva_Partida::Nueva_Partida(){
	
	
	_tex_fondos = new sf::Texture[Max_Fondos];
	cargarfondo();
	_sp_fondo.setTexture(_tex_fondos[0]);
	_sp_fondo.setScale(2, 2);

}

void Nueva_Partida::cargarfondo(){
	for (int i = 0; i < Max_Fondos; i++){
		_path = "imagenes/Fondojuego/fondo" + std::to_string (i) + ".jpeg";
		_tex_fondos[i].loadFromFile(_path);
	}
}

void Nueva_Partida::cmd(){

}

void Nueva_Partida::update(){

}

sf::Sprite& Nueva_Partida::get_draw(){
	return _sp_fondo;
}
