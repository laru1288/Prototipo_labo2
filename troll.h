#pragma once
#include "enemigo.h"
#include "IObject_enemy.h"
#include <SFML/Graphics.hpp>

class troll : public IObject_enemy {
private:
	sf::Texture _tex_personaje;
	sf::Sprite _sp_troll;
	sf::Vector2f frame_size;
	sf::Vector2i frame_actual;
	sf::Vector2u imagecount;
	int numero, cant_x, cant_y;
	float deltatime, totaltime, switchtime;
	sf::IntRect uvRect;
public:
	troll();
	void update(float deltatime);
	sf::Sprite& getdraw();
	void cargar_textura();
	void cmd();
	void setframe();
	

};

