#include "Personagem.h"


Entidades::Personagens::Personagem::Personagem(sf::Vector2f posi, sf::Vector2f tam, const float velo, const IDs::IDs ID) :
	Entidade(posi, tam, ID), podeAndar(false), esquerda(false), atacando(false), relogio(), dt(0.0f), 
	velocidadeFinal(sf::Vector2f(velo, 0.0f)), velocidadeMaxima(velo), animacao(&corpo), vivo(true)
{

}

Entidades::Personagens::Personagem::~Personagem() {}

sf::Vector2f Entidades::Personagens::Personagem::getVelocidadeFinal() {
	return velocidadeFinal;
}

void Entidades::Personagens::Personagem::setVelocidadeFinal(sf::Vector2f veloFinal) {
	velocidadeFinal = veloFinal;
}

void Entidades::Personagens::Personagem::andar(const bool esquerda) {
	atacando = false;
	podeAndar = true;
	this->esquerda = esquerda;
}

void Entidades::Personagens::Personagem::parar(){
	podeAndar = false;
}

void Entidades::Personagens::Personagem::atacar(const bool atacando) {
	podeAndar = false;
	this->atacando = atacando;
}

void Entidades::Personagens::Personagem::atualizar() {
	dt = relogio.getElapsedTime().asSeconds();
	relogio.restart();
	sf::Vector2f ds(0.0f, 0.0f);

	if (podeAndar) {
		ds.x = velocidadeFinal.x * dt;
		if (esquerda) {
			ds.x *= -1;
		}
	}

	velocidadeFinal.y += dt * GRAVIDADE;
	ds.y = velocidadeFinal.y * GRAVIDADE;

	setPosicao(sf::Vector2f(posicao.x + ds.x, posicao.y + ds.y));

	velocidadeFinal.x = velocidadeMaxima;

	desenhar();
}

void Entidades::Personagens::Personagem::atualizarAnimacao(){
	if (podeAndar) {
		animacao.atualizar(ElementosGraficos::anda, esquerda);
	} else {
		animacao.atualizar(ElementosGraficos::parado, esquerda);
	}
}

bool Entidades::Personagens::Personagem::estaVivo() {
	if (vivo) {
		return true;
	} else {
		return false;
	}
}

