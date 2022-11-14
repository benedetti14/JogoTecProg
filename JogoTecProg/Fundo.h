#pragma once

#include "Ente.h"

class Fundo : public Ente {
private:
	sf::Texture textura;
	sf::RectangleShape fundo;
	sf::Vector2f pAntCamera;
	const sf::Vector2f tamJanela;
public:
	Fundo(const char* cTextura, sf::Vector2f tJanela);
	~Fundo();
	void atualizar();
	void desenhar();
};