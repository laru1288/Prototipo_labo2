#include "Nivel_3.h"


Nivel_3::Nivel_3() {

	_turno = Turno_pj;
	_avatar_pj.loadFromFile("imagenes/FondosPelea/Avatar_pj.png");
	_avatar_enemigo.loadFromFile("imagenes/FondosPelea/dragon.png");
	papiro.loadFromFile("imagenes/papiro.png");
	_pj.setTexture(_avatar_pj);
	_enemigo.setTexture(_avatar_enemigo);
	_enemigo.setPosition(490, 0.20);
	_pj.setPosition(0, 50);
	_papiro.setTexture(papiro);
	_papiro.setPosition(0, 200);
	_papiro.setScale(280.f / papiro.getSize().x, 280.f / papiro.getSize().y);
	life_enemy.reallife = 7000;
	life_personaje.reallife = 6600;
	cargar_sonidos();
	cargar_sonidos_enemigos();
	_dibujar_ataque_enemy = false;
	_dibujar_ataque_pj = false;
	_dibujar_dado = false;
	_dibujar_elemento = false;
}


void Nivel_3::seleccionar_elemento() {

	_elemento.cmd();

}

void Nivel_3::seleccionar_elemento_aleatorio() {


	_elemento.setelemento(1 + rand() % 4);






}

void Nivel_3::pelea() {
	_mirror = 0;
	_danio = 0;
	_defensa = 0;

	///Preguntamos si es Turno del PJ
	if (_turno == Turno_pj) {

		turno_pj();
		if (_dado.get_numero_dado() != 0) {
			if (_mirror == 0) {
				if (_defensa < _danio) life_enemy.reallife -= (_danio - _defensa);

			}
			else
			{
				life_personaje.reallife -= _mirror;
				_mirror = 0;
			}


			_turno = Turno_enemigo;
		}
	}

	///Preguntamos si es Turno del enemigo
	if (_turno == Turno_enemigo) {

		turno_enemigo();
		if (_dado.get_numero_dado() != 0) {
			if (_mirror == 0) {
				if (_defensa < _danio) life_personaje.reallife -= (_danio - _defensa);

			}
			else
			{
				life_enemy.reallife -= _mirror;
				_mirror = 0;
			}

			_turno = Turno_pj;

		}
	}



}

void Nivel_3::reset_pos_personajes() {
	_PJ.get_draw_pj().setPosition(250, 400);
	_enemies->getdraw().setPosition(600, 350);
}

void Nivel_3::cmd(bool colision) {
	if (colision) {
		pelea();
		_dado.cmd();
		if (_dado.get_dadolanzado() == false)_dado.movimiento_dado();
		life_enemy.cmd();
		life_personaje.cmd();
	}
	else {
		_PJ.cmd();
		_enemies->update(_deltatime);
	}
}

void Nivel_3::update() {
	_PJ.update();
	_dado.update();
	_elemento.update();
	_elemento.setframe();
	if (_dado.get_dadolanzado() == false)_dado.setframe_movimiento();
	else _dado.setframe_cara_dado();
	_enemies->setframe();
	_PJ.setframe();

}

void Nivel_3::cargar_textura(std::string archivo) {
	_fondos.loadFromFile(archivo);


}

void Nivel_3::cargar_sprite_fondo() {
	_fondo.setTexture(_fondos);
	_fondo.setScale(2, 2);

}

void Nivel_3::turno_pj() {
	_dibujar_ataque_pj = false;
	_dibujar_elemento = true;
	seleccionar_elemento();
	_dado.set_numero_dado(0);

	if (_elemento.getelemento() != 0) {
		_dibujar_dado = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))_dado.lanzar_dado();
	}


	if (_dado.get_numero_dado() != 0) {

		switch (_dado.get_numero_dado()) {
		case 1: if (_elemento.getelemento() == 1) {
			_danio = Ojota_Mordida * 4;
			m_atack_1.play();
		}
			  else {
			_danio = Ojota_Mordida;
			m_atack_1.play();
		}
			  break;
		case 2:if (_elemento.getelemento() == 4) {
			_danio = Ojota_Playa * 4;
			m_atack_2.play();
		}
			  else {
			_danio = Ojota_Playa;
			m_atack_2.play();
		}
			  break;
		case 3:if (_elemento.getelemento() == 4) {
			_danio = Ojota_Hawaina * 4;
			m_atack_3.play();
		}
			  else {
			_danio = Ojota_Hawaina;
			m_atack_3.play();
		}
			  break;
		case 4:if (_elemento.getelemento() == 2) {
			_danio = Sueco_madera * 4;
			m_atack_4.play();
		}
			  else {
			_danio = Sueco_madera;
			m_atack_4.play();
		}

			  break;
		case 5:if (_elemento.getelemento() == 1) {
			_danio = Crocs * 4;
			m_atack_5.play();
		}
			  else {
			_danio = Crocs;
			m_atack_5.play();
		}

			  break;
		case 6:if (_elemento.getelemento() == 3) {
			_danio = LaChancla * 4;
			m_atack_6.play();
		}
			  else {
			_danio = LaChancla;
			m_atack_6.play();
		}
			  break;
		}

		_Ataque.cargar_textura_pj(_dado.get_numero_dado());
	
		_Ataque.update(_deltatime);

		restaurar_elemento();
		_dado.reset_movimiento();

		seleccionar_elemento_aleatorio();
		_dado.lanzar_dado();

		switch (_dado.get_numero_dado()) {
		case 1: if (_elemento.getelemento() == 1) { _defensa = Paraguas * 2; }
			  else _defensa = Paraguas;

			break;
		case 2:if (_elemento.getelemento() == 4) { _defensa = Cortina * 2; }
			  else _defensa = Cortina;

			break;
		case 3:if (_elemento.getelemento() == 4) { _defensa = Señora * 2; }
			  else _defensa = Señora;

			break;
		case 4:if (_elemento.getelemento() == 2) { _defensa = Maletin * 2; }
			  else _defensa = Maletin;

			break;
		case 5:if (_elemento.getelemento() == 1) { _defensa = Escudo * 2; }
			  else _defensa = Escudo;

			break;
		case 6:if (_elemento.getelemento() == 3) { _mirror = _danio * 2; }
			  else  _mirror = _danio;

			break;
		}
		restaurar_elemento();
		_dado.reset_movimiento();
	}
	_dibujar_dado = false;
	_dibujar_elemento = false;
	_dibujar_ataque_pj = true;
}

void Nivel_3::turno_enemigo() {
	_dibujar_ataque_enemy = false;
	_dibujar_elemento = true;
	seleccionar_elemento_aleatorio();
	_dibujar_dado = true;
	_dado.lanzar_dado();


	switch (_dado.get_numero_dado()) {
	case 1: if (_elemento.getelemento() == 1) { 
		_danio = llama_bebe * 2; 
		sound_1_enemy.play();
		}
		  else {
			_danio = llama_bebe;
			sound_1_enemy.play();
			}
		break;
	case 2:if (_elemento.getelemento() == 4) { 
		_danio = tormenta_cenizas * 2; 
		sound_2_enemy.play();
		}
		  else {
			_danio = tormenta_cenizas;
			sound_2_enemy.play();
			}

		break;
	case 3:if (_elemento.getelemento() == 4) { 
		_danio = mal_aliento * 2; 
		sound_3_enemy.play();
		}
		  else {
		_danio = mal_aliento;
		sound_3_enemy.play();
		}

		break;
	case 4:if (_elemento.getelemento() == 2) { 
		_danio = llama_hielo * 2; 
		sound_4_enemy.play();
		}
		  else {
			_danio = llama_hielo;
			sound_4_enemy.play();
			}

		break;
	case 5:if (_elemento.getelemento() == 1) { 
		_danio = encanto * 2; 
		sound_5_enemy.play();
		}
		  else {
		_danio = encanto; 
		sound_5_enemy.play();
			}
	

		break;
	case 6:if (_elemento.getelemento() == 3) { 
		_danio = super_llama * 2;
		sound_6_enemy.play();
		}
		  else {
			_danio = super_llama; 
			sound_6_enemy.play();
			}
			break;
	}
	_Ataque.cargar_textura_en(_dado.get_numero_dado());
	_Ataque.update(_deltatime);

	restaurar_elemento();
	_dado.reset_movimiento();


	seleccionar_elemento();
	_dado.set_numero_dado(0);

	if (_elemento.getelemento() != 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))_dado.lanzar_dado();
	}
	if (_dado.get_numero_dado() != 0) {

		switch (_dado.get_numero_dado()) {
		case 1: if (_elemento.getelemento() == 4) { _defensa = Paraguas * 2; }
			  else _defensa = Paraguas;

			break;
		case 2:if (_elemento.getelemento() == 4) { _defensa = Cortina * 2; }
			  else _defensa = Cortina;

			break;
		case 3:if (_elemento.getelemento() == 2) { _defensa = Señora * 2; }
			  else _defensa = Señora;

			break;
		case 4:if (_elemento.getelemento() == 1) { _defensa = Maletin * 2; }
			  else _defensa = Maletin;

			break;
		case 5:if (_elemento.getelemento() == 3) { _defensa = Escudo * 2; }
			  else _defensa = Escudo;

			break;
		case 6:if (_elemento.getelemento() == 3) { _mirror = _danio * 2; }
			  else  _mirror = _danio;

			break;
		}
		restaurar_elemento();
		_dado.reset_movimiento();
	}
	_dibujar_dado = false;
	_dibujar_elemento = false;
	_dibujar_ataque_enemy = true;
}

bool Nivel_3::dibujar_elemento() {

	return _dibujar_elemento;
}

bool Nivel_3::dibujar_dado() {
	return _dibujar_dado;
}

bool Nivel_3::dibujar_ataque_pj() {
	return _dibujar_ataque_pj;
}

bool Nivel_3::dibujar_ataque_enemy() {
	return _dibujar_ataque_enemy;
}

sf::Sprite& Nivel_3::get_draw_fondo() { return _fondo; }

sf::Sprite& Nivel_3::get_draw_avatar_pj() { return _pj; }

sf::Sprite& Nivel_3::get_draw_avatar_enemigo() { return _enemigo; }

sf::Sprite& Nivel_3::get_draw_papiro() { return _papiro; }

sf::Sprite& Nivel_3::get_draw_pj() { return _PJ.get_draw_pj(); }

sf::Sprite& Nivel_3::get_draw_enemy() { return _enemies->getdraw(); }

sf::Sprite& Nivel_3::get_draw_life_enemy() { return life_enemy.getdraw(); }

sf::Sprite& Nivel_3::get_draw_life_pj() { return life_personaje.getdraw(); }

sf::Sprite& Nivel_3::get_draw_elemento() { return _elemento.getdraw(); }

sf::Sprite& Nivel_3::get_draw_dado() { return _dado.getdraw(); }

sf::Sprite& Nivel_3::get_draw_ataque_pj() { return _Ataque.getdraw_ataque_pj(); }

sf::Sprite& Nivel_3::get_draw_ataque_enemy() { return _Ataque.getdraw_ataque_en(); }


void Nivel_3::restaurar_elemento() {
	_elemento.setelemento(0);
	_elemento.set_elemento_seleccionado(false);


}

void Nivel_3::createObject(int nivel) {

	switch (nivel) {
	case 0:  this->_enemies = new orco;
		break;
	case 1: this->_enemies = new troll;
		break;
	case 2: this->_enemies = new dragon;
		break;
	case 3: this->_enemies = new balrog;
		break;
	default: this->_enemies = new orco;
		break;
	}


}

int Nivel_3::get_muerte() {


	if (life_personaje.murio) {


		return 1;
	}
	if (life_enemy.murio) {

		return 2;
	}
	return 0;
}

void Nivel_3::setDeltatime(float deltatime) {
	_deltatime = deltatime;
}

void Nivel_3::cargar_sonidos_enemigos() {
	atack_1_buf.loadFromFile("sonidos/enemigos/dragon/grito.ogg");
	atack_2_buf.loadFromFile("sonidos/enemigos/dragon/rex.ogg");
	atack_3_buf.loadFromFile("sonidos/enemigos/dragon/atack.ogg");
	atack_4_buf.loadFromFile("sonidos/enemigos/dragon/electro.ogg");
	atack_5_buf.loadFromFile("sonidos/enemigos/dragon/granada.ogg");
	atack_6_buf.loadFromFile("sonidos/enemigos/dragon/dragon_atack.ogg");

	sound_1_enemy.setBuffer(atack_1_buf);
	sound_2_enemy.setBuffer(atack_2_buf);
	sound_3_enemy.setBuffer(atack_3_buf);
	sound_4_enemy.setBuffer(atack_4_buf);
	sound_5_enemy.setBuffer(atack_5_buf);
	sound_6_enemy.setBuffer(atack_6_buf);
}
