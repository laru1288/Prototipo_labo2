#pragma once
#include "Interfaz.h"
#include "NuevaPartida.h"
#include "PJ.h"
#include "enemigo.h"
#include "vida_personaje.h"
#include"vida_enemigo.h"
#include "elementos.h"
#include"Dados.h"
#include "Nivel_1.h"
#include "Nivel_2.h"
#include "Nivel_3.h"
#include "Nivel_4.h"

#include<iostream>


enum Niveles {
	Nivel1,
	Nivel2,
	Nivel3,
	Nivel4
};



enum Estado_Gameplay{

	Ejecutando,
	Pausa
};


class Gameplay{
private:
	Interfaz _i;
	PJ _pj;
	Nueva_Partida juego;
	FloatRect  enemybounds, playerbounds;
	vida_personaje pj_life;
	vida_enemigo enemy_life;
	elementos element;
	Dados dado;
	bool colisiono;
	Niveles _Nivel_Actual;
	Objet_Level* _Level;
	bool _nivel_creado;
	Texture _tex_cartel;
	Sprite _cartel;
	bool dibujar_cartel;
	float _deltatime;
	
public:
	Gameplay(float);
	void cmd();
	void update(sf::RenderWindow&);
	void draw(sf::RenderWindow &);
	bool collision();
	bool collision_pared(sf::Sprite& _pj, sf::Sprite& _enemy);
	bool create_Object_Level(int);
	void Next_Level();
	void Game_Over();
	void Congratuletion();

};

