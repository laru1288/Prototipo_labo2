#pragma once
#include <SFML/Graphics.hpp>
#define uno 50
#define dos 100
#define tres 300
#define cuatro 600
#define cinco 800
#define seis 1000



//Defensa Global, para todos los jugadores
enum defensa {
	Paraguas=uno,
	Cortina=dos,
	Se�ora=tres,
	Maletin=cuatro,
	Escudo=cinco,
	Mirror
};

class Personaje {

protected:
	int _vida;
	int _ataque;
	defensa _defensa;
	//sf::Texture _tex_personaje;
	//sf::Sprite _sp_personaje;
	//sf::Sprite _sp_dragon;
	
public:
	Personaje();
	void cmd();
	void update();
	int get_vida();
	void set_vida(int da�o);
	void set_tama�odevida(int vida);
};

