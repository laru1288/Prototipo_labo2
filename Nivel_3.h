#pragma once
#include "Objet_Level.h"
#include "dados.h"
#include"IObject_enemy.h"
#include "dragon.h"
#include"Personaje.h"
#include "PJ.h"
#include"vida_enemigo.h"
#include"vida_personaje.h"
#include "elementos.h";
#include "balrog.h"
#include "orco.h"
#include "troll.h"
#include "ataques.h"
#define Max_Fondos 4






class Nivel_3 :public Objet_Level {

	vida_enemigo life_enemy;
	vida_personaje life_personaje;
	PJ _PJ;
	IObject_enemy* _enemies;
	elementos _elemento;
	Dados _dado;
	ataques _Ataque;
	turnos _turno;
	int _defensa;
	int _mirror;
	sf::Texture papiro;
	sf::Texture _fondos;
	sf::Sprite _fondo;
	sf::Texture _avatar_pj;
	sf::Texture _avatar_enemigo;
	std::string _path;
	sf::Sprite _pj;
	sf::Sprite _enemigo;
	sf::Sprite _papiro;
	int _danio;
	bool _dibujar_elemento;
	bool _dibujar_dado;
	bool _dibujar_ataque_pj;
	bool _dibujar_ataque_enemy;
	sf::SoundBuffer atack_1_buf, atack_2_buf, atack_3_buf, atack_4_buf, atack_5_buf, atack_6_buf;
	sf::Sound sound_1_enemy, sound_2_enemy, sound_3_enemy, sound_4_enemy, sound_5_enemy, sound_6_enemy;
	float _deltatime;
public:
	Nivel_3();
	void seleccionar_elemento();
	void seleccionar_elemento_aleatorio();
	void pelea();
	void reset_pos_personajes();
	void cmd(bool);
	void update();
	void cargar_textura(std::string);
	void cargar_sprite_fondo();
	void turno_pj();
	void turno_enemigo();
	bool dibujar_elemento();
	bool dibujar_dado();
	bool dibujar_ataque_pj();
	bool dibujar_ataque_enemy();
	sf::Sprite& get_draw_fondo();
	sf::Sprite& get_draw_avatar_pj();
	sf::Sprite& get_draw_avatar_enemigo();
	sf::Sprite& get_draw_papiro();
	sf::Sprite& get_draw_pj();
	sf::Sprite& get_draw_enemy();
	sf::Sprite& get_draw_life_enemy();
	sf::Sprite& get_draw_life_pj();
	sf::Sprite& get_draw_elemento();
	sf::Sprite& get_draw_dado();
	sf::Sprite& get_draw_ataque_pj();
	sf::Sprite& get_draw_ataque_enemy();
	void restaurar_elemento();
	void createObject(int);
	int get_muerte();
	void setDeltatime(float);
	void cargar_sonidos_enemigos();
};
