#pragma once
#include <SFML/Graphics.hpp>
#define Max_Fondos 4


class Nueva_Partida{
private:
	sf::Texture*_tex_fondos;
	sf::Sprite _sp_fondo;
	std::string _path;
	
public:
	Nueva_Partida();
	void cargarfondo();
	void cmd();
	void update();
	sf::Sprite& get_draw();
};

