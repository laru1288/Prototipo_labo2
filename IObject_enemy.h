#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class IObject_enemy{


public:
	virtual void update(float)					 = 0;
	virtual sf::Sprite& getdraw() = 0;
	virtual void cargar_textura()			  =0;
	virtual void cmd()						  =0;
	virtual void setframe()					  =0;
	sf::Sprite _sp;
	

};

