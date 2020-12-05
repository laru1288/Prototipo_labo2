#pragma once
#include <SFML/Graphics.hpp>
class ataques{
private:
	sf::Texture  _tex_ataque_comun, _text_ataque_esp, _tex_ataque_pj, _tex_ataque_pj_esp;
	sf::Sprite _sp_ataque_pj, _sp_ataque_enemigo ;
	sf::Vector2f  frame_size_ataque;
	sf::Vector2i  frame_actual_ataque;
	int numero, numero_ataque, cant_x_ataque, cant_y_ataque;
	float deltatime, totaltime, switchtime;
	sf::IntRect uvRect, Rect_pj;
	
public:
	ataques();
	~ataques();
	void update(float deltatime);
	void cargar_textura_en(int num_dado);
	void cargar_textura_pj(int num_dado);
	void cmd();
	void setframe();
	void draw_ataque();
	sf::Sprite& getdraw_ataque_en();
	sf::Sprite& getdraw_ataque_pj();
	
};

