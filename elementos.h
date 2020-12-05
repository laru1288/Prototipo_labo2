#pragma once
#include <SFML\Graphics.hpp>

class elementos{
private:
	sf::Texture element_text;
	sf::Sprite _element;
	sf::Vector2f _origen;
	sf::Vector2f _limite;
	int _elemento;
	bool _elemento_seleccionado;
public:
	elementos();
	sf::Sprite& getdraw();
	void cmd();
	void update();
	void setelemento(int);
	void setframe();
	int getelemento();
	bool get_elemento_seleccionado();
	void set_elemento_seleccionado(bool);

};

