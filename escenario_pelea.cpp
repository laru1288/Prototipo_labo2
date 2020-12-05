#include "escenario_pelea.h"



escenario_pelea::escenario_pelea(){
	_fondos = new sf::Texture[4];
	_turno = Turno_pj;
	_avatar_pj.loadFromFile("imagenes/FondosPelea/Avatar_pj.png");
	_avatar_enemigo.loadFromFile("imagenes/FondosPelea/Avatar_dragon.png");
	papiro.loadFromFile("imagenes/papiro.png");
	}

void escenario_pelea::seleccionar_elemento(){
		
		_elemento.cmd();
		
}

void escenario_pelea::seleccionar_elemento_aleatorio(){
	

		_elemento.setelemento(1 + rand() % 4);
		
	
	
	


}

void escenario_pelea::pelea(){
	 	_mirror = 0;
		_danio = 0;
		_defensa = 0;
		
          ///Preguntamos si es Turno del PJ
		if (_turno == Turno_pj) {
			
			turno_pj();
			if(_dado.get_numero_dado()!=0){
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

void escenario_pelea::cmd(){
	

}

void escenario_pelea::update(){

}

void escenario_pelea::cargar_texturas(){
	for (int i = 0; i < Max_Fondos; i++) {
		_path = "imagenes/FondosPelea/fondo" + std::to_string(i) + ".jpeg";
		_fondos[i].loadFromFile(_path);
	}

	

}

void escenario_pelea::cargar_sprite_fondo(int nivel){
	_fondo.setTexture(_fondos[nivel - 1]);
	_fondo.setScale(2, 2);
	_pj.setTexture(_avatar_pj);
	_enemigo.setTexture(_avatar_enemigo);
	_enemigo.setPosition(490, 0.20);
	_pj.setPosition(0, 50);
	_papiro.setTexture(papiro);
	_papiro.setPosition(0, 200);
	_papiro.setScale(280.f / papiro.getSize().x, 280.f / papiro.getSize().y);
}

void escenario_pelea::turno_pj(){
	seleccionar_elemento();
	_dado.set_numero_dado(0);
	
	if (_elemento.getelemento()!=0){

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))_dado.lanzar_dado();
	}
	
		
	if(_dado.get_numero_dado() != 0){

	switch (_dado.get_numero_dado()) {
	case 1: if (_elemento.getelemento() == 1) { _danio = Ojota_Mordida * 4; }
		  else _danio = Ojota_Mordida;
		
		break;
	case 2:if (_elemento.getelemento() == 4) { _danio = Ojota_Playa * 4; }
		  else _danio = Ojota_Playa;
		
		break;
	case 3:if (_elemento.getelemento() == 4) { _danio = Ojota_Hawaina * 4; }
		  else _danio = Ojota_Hawaina;
		
		break;
	case 4:if (_elemento.getelemento() == 2) { _danio = Sueco_madera * 4; }
		  else _danio = Sueco_madera;
		
		break;
	case 5:if (_elemento.getelemento() == 1) { _danio = Crocs * 4; }
		  else _danio = Crocs;
		
		break;
	case 6:if (_elemento.getelemento() == 3) { _danio = LaChancla * 4; }
		  else _danio = LaChancla;
		
		break;
	}
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

}

void escenario_pelea::turno_enemigo() {


	seleccionar_elemento_aleatorio();

	_dado.lanzar_dado();


	switch (_dado.get_numero_dado()) {
	case 1: if (_elemento.getelemento() == 1) { _danio = Ojota_Mordida * 2; }
		  else _danio = Ojota_Mordida;

		break;
	case 2:if (_elemento.getelemento() == 4) { _danio = Ojota_Playa * 2; }
		  else _danio = Ojota_Playa;

		break;
	case 3:if (_elemento.getelemento() == 4) { _danio = Ojota_Hawaina * 2; }
		  else _danio = Ojota_Hawaina;

		break;
	case 4:if (_elemento.getelemento() == 2) { _danio = Sueco_madera * 2; }
		  else _danio = Sueco_madera;

		break;
	case 5:if (_elemento.getelemento() == 1) { _danio = Crocs * 2; }
		  else _danio = Crocs;

		break;
	case 6:if (_elemento.getelemento() == 3) { _danio = LaChancla * 2; }
		  else _danio = LaChancla;
	std:
		break;
	}
	restaurar_elemento();
	_dado.reset_movimiento();


	seleccionar_elemento();
	_dado.set_numero_dado(0);

	if (_elemento.getelemento() != 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))_dado.lanzar_dado();
	}
	if (_dado.get_numero_dado() != 0){

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
}

sf::Sprite& escenario_pelea::get_draw_fondo() {	return _fondo;}

sf::Sprite& escenario_pelea::get_draw_avatar_pj() {	return _pj;}

sf::Sprite& escenario_pelea::get_draw_avatar_enemigo() {return _enemigo;}

sf::Sprite& escenario_pelea::get_draw_papiro() { return _papiro; }

void escenario_pelea::restaurar_elemento(){
	_elemento.setelemento(0);
	_elemento.set_elemento_seleccionado(false);

	
}

bool escenario_pelea::get_muerte(){
	life_enemy.cmd();
	life_personaje.cmd();

	if (life_personaje.murio) {
		
		
		return true;
	}
	if(life_enemy.murio) {
		
		return true;
     }
	return false;
}

