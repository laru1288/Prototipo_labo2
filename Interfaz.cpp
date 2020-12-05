#include "Interfaz.h"

void Interfaz::cargar_textura(std::string texto)
{
	_texturafondo.loadFromFile(texto);
}

void Interfaz::cargar_fuente(std::string texto)
{
	_fuente.loadFromFile(texto);
}

Interfaz::Interfaz()
{    
	_opcion_elegida = false;
	_opcion_m = NuevaPartida;
	_opcion = 0;
	cargar_textura("imagenes/Interfaz/fondo.jpg");
	cargar_fuente("fuente/fuente.ttf");

	_text = new sf::Text[maxtext];
	
	for (int x = 0; x < maxtext;x++)_text[x].setFont(_fuente);


	_text[NuevaPartida].setString("NUEVA PARTIDA");
	_text[NuevaPartida].setPosition(325,100);
	_text[NuevaPartida].setFillColor(sf::Color::Magenta);
	_text[PartidaGuardada].setString("PARTIDA GUARDADA");
	_text[PartidaGuardada].setPosition(300,150);
	_text[ComoJugar].setString("COMO JUGAR");
	_text[ComoJugar].setPosition(350,200);
	_text[Salir].setString("SALIR");
	_text[Salir].setPosition(400,250);
	_spfondo.setTexture(_texturafondo);
	_spfondo.setScale(2, 2);

}

opcion_menu Interfaz::get_opcion(){
	return _opcion_m;
}

bool Interfaz::get_opcion_elegida()
{
	return _opcion_elegida;
}

void Interfaz::set_opcion_elegida(bool valor){
	_opcion_elegida = valor;
}



sf::Sprite& Interfaz::getdrawfondo()
{
	return _spfondo;// TODO: Insertar una instrucción "return" aquí
}

sf::Text* Interfaz::getdrawtextos()
{
	return _text;
}


void Interfaz::cmd(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		_text[_opcion].setFillColor(sf::Color::White);
		if (_opcion > 0) {
			_opcion--;
		}
		else _opcion = 3;
		_text[_opcion].setFillColor(sf::Color::Magenta);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		_text[_opcion].setFillColor(sf::Color::White);
		if (_opcion < 3) {
			_opcion++;
		}
		else _opcion = 0;
		_text[_opcion].setFillColor(sf::Color::Magenta);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) _opcion_elegida=true;

}

void Interfaz::update()
{
	switch (_opcion) {

	case 0: _opcion_m = NuevaPartida;
		break;

	case 1: _opcion_m = PartidaGuardada;
		break;
	
	case 2: _opcion_m = ComoJugar;
		break;

	case 3: _opcion_m = Salir;
		break;
	}
}
