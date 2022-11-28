#include "Entidade.h"
#include <SFML/Graphics.hpp>


Entidades::Entidade::Entidade(sf::Vector2f posi, sf::Vector2f tam, const IDs::IDs ID) : Ente(ID), 
posicao(posi), tamanho(tam), vivo(true) {
}

Entidades::Entidade::~Entidade() {};

const sf::Vector2f Entidades::Entidade::getPosicao() {
	return posicao;
}

const sf::Vector2f Entidades::Entidade::getTamanho() {
	return tamanho;
}

bool Entidades::Entidade::estaVivo() {
	return vivo;
}

