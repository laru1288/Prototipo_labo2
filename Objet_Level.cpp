#include "Objet_Level.h"


void Objet_Level::cargar_sonidos() {
	atack_1_buff.loadFromFile("sonidos/melee_atack_pj.ogg");
	atack_2_buff.loadFromFile("sonidos/sword.ogg");
	atack_3_buff.loadFromFile("sonidos/pistol.ogg");
	atack_4_buff.loadFromFile("sonidos/crash.ogg");
	atack_5_buff.loadFromFile("sonidos/golpe.ogg");
	atack_6_buff.loadFromFile("sonidos/lazer.ogg");

	m_atack_1.setBuffer(atack_1_buff);
	m_atack_2.setBuffer(atack_2_buff);
	m_atack_3.setBuffer(atack_3_buff);
	m_atack_4.setBuffer(atack_4_buff);
	m_atack_5.setBuffer(atack_5_buff);
	m_atack_6.setBuffer(atack_6_buff);
}
