#include "Personagem.h"


Entidades::Personagens::Personagem::Personagem(sf::Vector2f posi, sf::Vector2f tam, int v,const float velo, const IDs::IDs ID) :
	Entidade(posi, tam, ID), podeAndar(false), esquerda(false), atacando(false), relogio(), dt(0.0f), 
	velocidadeFinal(sf::Vector2f(velo, 0.0f)), velocidadeMaxima(velo), animacao(&corpo), vivo(true), vida(v)
{

}

Entidades::Personagens::Personagem::~Personagem() {}

sf::Vector2f Entidades::Personagens::Personagem::getVelocidadeFinal() {
	return velocidadeFinal;
}

const int Entidades::Personagens::Personagem::getVida() const {
	return vida;
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

const bool Entidades::Personagens::Personagem::estaAtacando() {
	return atacando;
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
	//animacao.setPosicao(sf::Vector2f(posicao.x + ds.x, posicao.y + ds.y));

	velocidadeFinal.x = velocidadeMaxima;

	desenhar();
}

void Entidades::Personagens::Personagem::danoRecebido(const int dano) {
	vida -= dano;
	if (vida <= 0) {
		vivo = false;
	}
}

void Entidades::Personagens::Personagem::atualizarAnimacao(){
	if (podeAndar) {
		animacao.atualizar(ElementosGraficos::anda, esquerda);
	} else {
		animacao.atualizar(ElementosGraficos::parado, esquerda);
	}
}


void Entidades::Personagens::Personagem::desenhar(){
	animacao.desenhar();
}

void Entidades::Personagens::Personagem::setPosicao(sf::Vector2f posi){
	posicao = posi;
	animacao.setPosicao(posicao);
}

bool Entidades::Personagens::Personagem::estaVivo() {
	if (vivo) {
		return true;
	} else {
		return false;
	}
}

