#include "Personagem.h"


Entidades::Personagens::Personagem::Personagem(sf::Vector2f posi, sf::Vector2f tam, sf::Vector2f velo, const IDs::IDs ID) 
	: Entidade(posi, tam, ID), podeAndar(false), esquerda(false), relogio(), dt(0.0f), velocidade(velo) 
{

}

Entidades::Personagens::Personagem::~Personagem() {}

sf::Vector2f Entidades::Personagens::Personagem::getVelocidade() {
	return velocidade;
}

void Entidades::Personagens::Personagem::setVelocidade(sf::Vector2f velo) {
	velocidade = velo;
}

void Entidades::Personagens::Personagem::andar(const bool esquerda) {
	podeAndar = true;
	this->esquerda = esquerda;
}

void Entidades::Personagens::Personagem::parar(){
	podeAndar = false;
}

void Entidades::Personagens::Personagem::atualizar() {
	dt = relogio.getElapsedTime().asSeconds();
	relogio.restart();
	sf::Vector2f ds(0.0f, 0.0f);

	if (podeAndar) {
		ds.x = velocidade.x * dt;
		if (esquerda) {
			ds.x *= -1;
		}
	}

	/*velocidade.y += dt * GRAVIDADE;
	ds.y = velocidade.y * GRAVIDADE;*/

	setPosicao(sf::Vector2f(posicao.x + ds.x, posicao.y + ds.y));

	desenhar();
}