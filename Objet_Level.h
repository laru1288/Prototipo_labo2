#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#define uno 50
#define dos 100
#define tres 300
#define cuatro 600
#define cinco 800
#define seis 1000


enum skills_orco {
	grunido = uno,
	mordida = dos,
	faca = tres,
	punietazo = cuatro,
	hacha = cinco,
	espada = seis
};

enum skills_troll {
	lanza_palangana = uno,
	golpe = dos,
	roca_gigante = tres,
	lavarropa = cuatro,
	colectivo = cinco,
	yunque = seis
};

enum skills_dragon {
	llama_bebe = uno,
	tormenta_cenizas = dos,
	mal_aliento = tres,
	llama_hielo = cuatro,
	encanto = cinco,
	super_llama = seis
};

enum skills_balrog {
	llamarada = uno,
	regeneracion = dos,
	ataque_orcos = tres,
	ataque_trolls = cuatro,
	ataque_dragones = cinco,
	latigo = seis
};

enum turnos {
	Turno_pj,
	Turno_enemigo
};


class Objet_Level{
protected:
		sf::SoundBuffer atack_1_buff, atack_2_buff, atack_3_buff, atack_4_buff, atack_5_buff, atack_6_buff;
		sf::Sound m_atack_1, m_atack_2, m_atack_3, m_atack_4, m_atack_5, m_atack_6;
public:
	
	virtual void seleccionar_elemento()=0;
	virtual void seleccionar_elemento_aleatorio()=0;
	virtual void pelea() = 0;
    virtual	void reset_pos_personajes()=0;
	virtual void cmd(bool) =0;
	virtual void update()=0;
	virtual void cargar_textura(std::string)=0;
	virtual void cargar_sprite_fondo()=0;
	virtual void turno_pj()=0;
	virtual void turno_enemigo()=0;
	virtual bool dibujar_elemento()=0;
	virtual bool dibujar_dado()=0;
	virtual bool dibujar_ataque_pj()=0;
	virtual bool dibujar_ataque_enemy() = 0;
	virtual sf::Sprite& get_draw_fondo()=0;
	virtual sf::Sprite& get_draw_avatar_pj()=0;
	virtual sf::Sprite& get_draw_avatar_enemigo()=0;
	virtual sf::Sprite& get_draw_papiro()=0;
	virtual sf::Sprite& get_draw_pj()=0;
	virtual sf::Sprite& get_draw_enemy()=0;
	virtual sf::Sprite& get_draw_life_enemy()=0;
	virtual sf::Sprite& get_draw_life_pj()=0;
	virtual sf::Sprite& get_draw_elemento()=0;
	virtual sf::Sprite& get_draw_dado()=0;
	virtual sf::Sprite& get_draw_ataque_pj()=0;
	virtual sf::Sprite& get_draw_ataque_enemy()=0;
	virtual void restaurar_elemento()=0;
    virtual	void createObject(int)=0;
	virtual int get_muerte()=0;
	virtual void setDeltatime(float)=0;
	virtual void cargar_sonidos_enemigos() = 0;
	void cargar_sonidos();
};

