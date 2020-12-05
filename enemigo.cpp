#include "enemigo.h"

/*

orco::orco():Personaje(){

	
	
	
		
}

void orco::cargar_textura(std::string textura) {
	
}

void orco::cmd(){
	

}

void orco::update(bool move) {
	if (move == false) {
		frame_actual.x ++;
		if (frame_actual.x == cant_1 - 1) {
			frame_actual.x = 0;
		}

	}

}

void orco::update(int row, float deltatime){

	
}

sf::Sprite& orco::get_draw_pj()
{
	return *_sp_test;
	//return _sp_dragon;
}

sf::Sprite& orco::get_draw_orco(){
	return _sp_orco;
}

void orco::seleccionar_frame(){
	IntRect rectangulo(frame_actual.x * frame_size.x, frame_actual.y * frame_size.x, frame_size.x, frame_size.y);
	_sp_test->setTextureRect(rectangulo);

}

void orco::set_sprite(int n_sp, int cant_x, int cant_y, Vector2i sp_actual){
	int numero;
	cant_1 = cant_x;
	cant_2 = cant_y;
	numero = n_sp;
	test = new Texture();
	String path = "imagenes/enemigos/" + std::to_string(numero) + ".png";
	test->loadFromFile(path);
	_sp_test = new Sprite(*test);		
	frame_size = sf::Vector2f (test->getSize().x / cant_x, test->getSize().y / cant_y);
	
	seleccionar_frame();
	_sp_test->setPosition(500, 315);
	_sp_test->setScale(2, 2);

	//if (_sp_test->getPosition().x < 0) _sp_test->setPosition(0, _sp_test->getPosition().y);
	//if (_sp_test->getPosition().x + _sp_test->getGlobalBounds().width > 900) _sp_test->setPosition(900 - _sp_test->getGlobalBounds().width, _sp_test->getPosition().y);
	//totaltime = 0.0f;
}

void orco::animar_frame(){
		

}


*/