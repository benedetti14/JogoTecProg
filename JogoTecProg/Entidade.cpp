#include "Entidade.h"
#include <SFML/Graphics.hpp>

Entidades::Entidade::Entidade(sf::Vector2f posi, sf::Vector2f tam) {
	posicao = posi;
	tamanho = tam;
	corpo.setSize(tamanho);
	corpo.setPosition(posicao);
}

Entidades::Entidade::~Entidade() {};

sf::RectangleShape Entidades::Entidade::getCorpo() {
	return corpo;
}
