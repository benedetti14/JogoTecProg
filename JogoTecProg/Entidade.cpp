#include "Entidade.h"
#include <SFML/Graphics.hpp>

Entidades::Entidade::Entidade(sf::Vector2f posi, sf::Vector2f tam, const IDs::IDs ID) : Ente(ID), corpo(sf::RectangleShape(tam)), posicao(posi), tamanho(tam) {
	corpo.setPosition(posicao);
}

Entidades::Entidade::~Entidade() {};

sf::RectangleShape Entidades::Entidade::getCorpo() {
	return corpo;
}

void Entidades::Entidade::setPosicao(sf::Vector2f posi) {
	corpo.setPosition(posi);
	posicao = posi;
}

const sf::Vector2f Entidades::Entidade::getPosicao() {
	return posicao;
}

const sf::Vector2f Entidades::Entidade::getTamanho() {
	return tamanho;
}

void Entidades::Entidade::desenhar() {
	pGrafico->desenhar(corpo);
}