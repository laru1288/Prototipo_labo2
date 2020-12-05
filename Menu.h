#pragma once
#include <SFML\Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 4
class Menu{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow& window);
	void Moveup();
	void MoveDown();
	int GetPressedItem() { return selecteditemindex };

private:
	int selecteditemindex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Texture _texturafondo;
	sf::Sprite _spfondo;
	//sf::Sprite& getdrawfondo();
	void cargar_textura(std::string);
};

