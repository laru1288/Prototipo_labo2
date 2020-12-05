#pragma once
#include "Personaje.h"
#include <SFML\Graphics\Transformable.hpp>
#include <SFML\Window\Window.hpp>
#include <SFML\Window\Mouse.hpp>
#include <SFML\Window\Touch.hpp>
#include <SFML\Graphics.hpp>
using namespace sf;


enum estados {
	quieto,
	caminando_derecha,
	caminando_izquierda
};

enum skills_pj {
	Ojota_Mordida = uno,
	Ojota_Playa = dos,
	Ojota_Hawaina = tres,
	Sueco_madera = cuatro,
	Crocs = cinco,
	LaChancla = seis
};

class PJ :public Personaje {
private:
	skills_pj _arma;
	estados _estado;
	//const float movementspeed;
	float dt;
	sf::Clock clock;
	sf::Vector2i _numeroframe, _cantidad;	
	int walk = 0;	
	///sf::Vector2f position;
public:
	PJ();
	void cargar_textura(std::string);
	void cmd( );
	void update();
	//sf::Sprite _sp_personaje;
	sf::Sprite& get_draw_pj();
	void setframe();
	float bottom, left, right, top;
	sf::Texture _tex_personaje;
	sf::Sprite _sp_personaje;
	sf::Vector2f velocity;
	void set_arma(int);
	skills_pj get_arma();
		

	//sf::Vector2f GetPosition() { return _sp_personaje.getPosition(); }
	//sf::Vector2f SetPosition(int, int);
	
};

