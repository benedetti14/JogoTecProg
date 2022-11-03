#include "Personagem.h"


Entidades::Personagens::Personagem::Personagem(sf::Vector2f posi, sf::Vector2f velo, sf::Vector2f tam) : Entidade(posi, tam) {
	velocidade = velo;
}

Entidades::Personagens::Personagem::~Personagem() {}

void Entidades::Personagens::Personagem::atualizar(float t) {
	move();
	corpo.move(velocidade * t);
}