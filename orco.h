#pragma once
#include "enemigo.h"
#include "IObject_enemy.h"
#include <SFML/Graphics.hpp>

class orco :  public IObject_enemy{
private:
	sf::Texture _tex_personaje, _tex_ataque_1, _tex_defensa;
	sf::Sprite _sp_orco, _sp_ataque_1, _sp_defensa;
	sf::Vector2f frame_size, frame_size_ataque;
	sf::Vector2i frame_actual, frame_actual_ataque;
	sf::Vector2u imagecount;
	int numero, cant_x, cant_y, numero_ataque, cant_x_ataque , cant_y_ataque;
	float deltatime, totaltime, switchtime;
	sf::IntRect uvRect;
public:
	orco();
	void update(float deltatime) ;
	sf::Sprite& getdraw();
	void cargar_textura();
	void cmd();
	void setframe();
	sf::Sprite _sp;
	
};

