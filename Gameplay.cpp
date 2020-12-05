#include "Gameplay.h"

Gameplay::Gameplay(float deltatime){
	_Nivel_Actual = Nivel1;
	_nivel_creado = false;
	colisiono = false;
	dibujar_cartel = false;
	_deltatime = deltatime;
}

void Gameplay::cmd(){
	if (!_i.get_opcion_elegida())  _i.cmd();
	if (_i.get_opcion() == NuevaPartida && _i.get_opcion_elegida()) {
		switch (_Nivel_Actual){
		case Nivel1:

			if (_nivel_creado==false) {
				_nivel_creado = create_Object_Level(1);
				_Level->cargar_textura("imagenes/Fondojuego/fondo0.jpeg");
				_Level->cargar_sprite_fondo();
				_Level->createObject(1);
			}

			if (colisiono) {
				_Level->cargar_textura("imagenes/FondosPelea/fondo0.jpeg");
				_Level->cargar_sprite_fondo();
				_Level->reset_pos_personajes();
				
			}
			break;

		case Nivel2:

			if (_nivel_creado==false) {
				_nivel_creado = create_Object_Level(2);
				_Level->cargar_textura("imagenes/Fondojuego/fondo1.jpeg");
				_Level->cargar_sprite_fondo();
				_Level->createObject(2);
			}

			if (colisiono) {
				_Level->cargar_textura("imagenes/FondosPelea/fondo1.jpeg");
				_Level->cargar_sprite_fondo();
				_Level->reset_pos_personajes();
			}
		

			break;

		case Nivel3:

			if (_nivel_creado==false) {
				_nivel_creado = create_Object_Level(3);
				_Level->cargar_textura("imagenes/Fondojuego/fondo2.jpeg");
				_Level->cargar_sprite_fondo();
				_Level->createObject(3);
			}

			if (colisiono) {
				_Level->cargar_textura("imagenes/FondosPelea/fondo2.jpeg");
				_Level->cargar_sprite_fondo();
				_Level->reset_pos_personajes();
			}

			break;

		case Nivel4:

			if (_nivel_creado==false) {
				_nivel_creado = create_Object_Level(4);
				_Level->cargar_textura("imagenes/Fondojuego/fondo3.jpeg");
				_Level->cargar_sprite_fondo();
				_Level->createObject(4);
			}

			if (colisiono) {
				_Level->cargar_textura("imagenes/FondosPelea/fondo3.jpeg");
				_Level->cargar_sprite_fondo();
				_Level->reset_pos_personajes();
			}

			break;

		default:

			break;
		}
		if (colisiono == false) { colisiono = collision(); }
		
		_Level->cmd(colisiono);

		if (_Level->get_muerte()==2 || _Level->get_muerte() == 1) {
			
			if (_Level->get_muerte() == 1) Game_Over();
			else Next_Level();
			delete(_Level);
		}

}
}

void Gameplay::update(sf::RenderWindow& window){
	
	if (_i.get_opcion_elegida()) {
		_i.update();
		if (_i.get_opcion() == Salir) window.close();
	}
	
	if(_i.get_opcion() == NuevaPartida && _i.get_opcion_elegida()){
		
		_Level->update();
		_Level->setDeltatime(_deltatime);
		
		
	}
	

}

void Gameplay::draw(sf::RenderWindow& window) {
	if (!_i.get_opcion_elegida()) {
		sf::Text* vec = _i.getdrawtextos();
		window.draw(_i.getdrawfondo());
		for (int x = 0; x < maxtext; x++) {
			window.draw(vec[x]);
		}

	}
	if (_i.get_opcion() == NuevaPartida && _i.get_opcion_elegida()) {
		if (colisiono) {
			
			window.draw(_Level->get_draw_avatar_enemigo());
			window.draw(_Level->get_draw_avatar_pj());
			window.draw(_Level->get_draw_fondo());
			window.draw(_Level->get_draw_life_pj());
			window.draw(_Level->get_draw_life_enemy());

			if (_Level->dibujar_ataque_enemy())  window.draw(_Level->get_draw_ataque_pj());

			if (_Level->dibujar_ataque_pj())     window.draw(_Level->get_draw_ataque_enemy());

			if(_Level->dibujar_elemento())       window.draw(_Level->get_draw_elemento());

			if (_Level->dibujar_dado())          window.draw(_Level->get_draw_dado());
	
			if (dibujar_cartel) {
				window.clear();
				window.draw(_cartel);
				
			}
		}
		else {
			window.draw(_Level->get_draw_pj());
			window.draw(_Level->get_draw_enemy());
		
		}
	}
}


bool Gameplay::collision(){
	
	if (_pj.get_draw_pj().getGlobalBounds().intersects(_Level->get_draw_enemy().getGlobalBounds())) {
		
		return true;		
	}
		
	return false;
	
}

bool Gameplay::create_Object_Level(int numero){
	
	switch (numero)
	{
	case 1:
		_Level = new Nivel_1;
		break;
	case 2:
		_Level = new Nivel_2;
		break;
	case 3:
		_Level = new Nivel_3;
		break;

	case 4:
		_Level = new Nivel_4;
		break;
	default:
		_Level = new Nivel_1;
		break;
	}

	return true;
}

void Gameplay::Next_Level(){
	switch(_Nivel_Actual){

	case Nivel1:
		_Nivel_Actual = Nivel2;
		break;

	case Nivel2:
		_Nivel_Actual = Nivel3;
		break;

	case Nivel3:
		_Nivel_Actual = Nivel4;
		break;

	case Nivel4:
		Congratuletion();
		break;

	default:
		break;

	}
}

void Gameplay::Game_Over(){
	_tex_cartel.loadFromFile("imagenes/GameOver1.jpeg");
	_cartel.setTexture(_tex_cartel);
	_cartel.setScale(2, 2);
	dibujar_cartel = true;
	_i.set_opcion_elegida(false);
}

void Gameplay::Congratuletion(){
	_tex_cartel.loadFromFile("imagenes/Congratuletion.jpeg");
	_cartel.setTexture(_tex_cartel);
	_cartel.setScale(2, 2);
	dibujar_cartel = true;

}









