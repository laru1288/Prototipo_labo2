#pragma once
#include <SFML/Graphics.hpp>
#define ancho_sprite 6
#define alto_sprite 2
#include <ctime>


class Dados{
private:
	sf::Texture _dados;
	sf::Font _fuente;
	sf::Sprite  _dado;
	sf::Text _texto;
	int _numero_dado;
	sf::Vector2i _frame_cara_dado;
	sf::Vector2i _frame_movimiento;
		
	bool _dado_lanzado;
public:
	Dados();
	void cmd();
	void update();
	void setframe_movimiento();
	void setframe_cara_dado();
	void reset_movimiento();
	void movimiento_dado();
	void lanzar_dado(); 
	sf::Sprite& getdraw();
	sf::Text& getdrawtext();
	void carga_textura(std::string);
	int get_numero_dado();
	void set_numero_dado(int);
	bool get_dadolanzado();


};

