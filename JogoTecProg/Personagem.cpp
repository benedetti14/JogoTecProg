#include "Personagem.h"


Entidades::Personagens::Personagem::Personagem(sf::Vector2f posi, sf::Vector2f velo, sf::Vector2f tam) : Entidade(posi, tam) {
	velocidade = velo;
	podeAndar = false;
	podeSubir = false;
}

Entidades::Personagens::Personagem::~Personagem() {}

void Entidades::Personagens::Personagem::parar(){
	podeAndar = false;
	podeSubir = false;
}

void Entidades::Personagens::Personagem::atualizar() {
	move();
	//corpo.move(velocidade * t);
}