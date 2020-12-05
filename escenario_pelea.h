#pragma once
#include <SFML\Graphics.hpp>
#include "dados.h"
#include"enemigo.h"
#include"Personaje.h"
#include "PJ.h"
#include"vida_enemigo.h"
#include"vida_personaje.h"
#include "elementos.h";
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Window\Window.hpp>
#include <SFML\Window\Mouse.hpp>
#include <SFML\Window\Touch.hpp>
#include <SFML\Graphics.hpp>
#define Max_Fondos 4


enum turnos{
	Turno_pj,
	Turno_enemigo
};

class escenario_pelea{
private:
	vida_enemigo life_enemy;
	vida_personaje life_personaje;
	elementos _elemento;
	Dados _dado;
	turnos _turno;
	int _defensa;
	int _mirror;
	sf::Texture papiro;
	sf::Texture* _fondos;
	sf::Sprite _fondo;
	sf::Texture _avatar_pj;
	sf::Texture _avatar_enemigo;
	sf::Sprite _pj;
	sf::Sprite _enemigo;
	std::string _path;
	sf::Sprite _papiro;
	int _danio;
public:
	escenario_pelea();
	void seleccionar_elemento();
	void seleccionar_elemento_aleatorio();
	void pelea();
	void cmd();
	void update();
	void cargar_texturas();
	void cargar_sprite_fondo(int);
	void turno_pj();
	void turno_enemigo();
	sf::Sprite& get_draw_fondo();
	sf::Sprite& get_draw_avatar_pj();
	sf::Sprite& get_draw_avatar_enemigo();
	sf::Sprite& get_draw_papiro();
	void restaurar_elemento();	
	bool get_muerte();
	
};

