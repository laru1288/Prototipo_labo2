#include "Menu.h"
#include <SFML\Graphics.hpp>

Menu::Menu(float width, float height){
	//cargar_textura("imagenes/Interfaz/fondo.jpg");
	if (!font.loadFromFile("fuente/fuente.ttf")) {

	}
	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Magenta);
	menu[0].setString("NUEVA PARTIDA");
	menu[0].setPosition(325, 100);

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("PARTIDA GUARDADA");
	menu[1].setPosition(300, 150);

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("COMO JUGAR");
	menu[2].setPosition(350, 200);

	menu[3].setFont(font);
	menu[3].setColor(sf::Color::White);
	menu[3].setString("SALIR");
	menu[3].setPosition(400, 250);

	selecteditemindex = 0;


	//_spfondo.setTexture(_texturafondo);
	//_spfondo.setScale(2, 2);

}

//{
//	_texturafondo.loadFromFile(texto);
//}

void Menu::Moveup() {
	if (selecteditemindex - 1 >= 0) {
		menu[selecteditemindex].setColor(sf::Color::White);
		selecteditemindex--;
		menu[selecteditemindex].setColor(sf::Color::Magenta);
	}
}

void Menu::MoveDown() {
	if (selecteditemindex + 1 < MAX_NUMBER_OF_ITEMS) {
		menu[selecteditemindex].setColor(sf::Color::White);
		selecteditemindex++;
		menu[selecteditemindex].setColor(sf::Color::Magenta);
	}
}