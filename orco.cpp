#include "orco.h"

orco::orco()  {
	cargar_textura();
	_sp.setTexture(_tex_personaje);
	_sp.setScale(1, 1);
	_sp.setPosition(750, 350);
	cant_x = 6;
	cant_y = 1;
	frame_actual = { 0, 0 };
	frame_size = sf::Vector2f(_tex_personaje.getSize().x / cant_x, _tex_personaje.getSize().y / cant_y);
	_sp.setTextureRect(sf::IntRect(frame_actual.x * frame_size.x, frame_actual.y * frame_size.x, frame_size.x, frame_size.y));
	totaltime = 0.0f;
	switchtime = 0.025f;
	uvRect.width = _tex_personaje.getSize().x / cant_x;
	uvRect.height = _tex_personaje.getSize().y / cant_y;
	
}

void orco::update(float deltatime){
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



sf::Sprite& orco::getdraw(){
	return _sp;
}

void orco::cargar_textura() {
	_tex_personaje.loadFromFile("imagenes/enemigos/orco1.png");
	
}

void orco::cmd(){
	

}

void orco::setframe(){
	sf::IntRect posicion((int)frame_size.x * frame_actual.x,(int)frame_size.y *frame_actual.y, (int)frame_size.x, (int)frame_size.y );
	_sp.setTextureRect(uvRect);
}









