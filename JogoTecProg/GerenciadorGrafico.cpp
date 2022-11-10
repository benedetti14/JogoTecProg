#include "GerenciadorGrafico.h"
#include <stdlib.h>
#include <iostream>

Gerenciadores::GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::pGrafico = nullptr;

Gerenciadores::GerenciadorGrafico::GerenciadorGrafico() : janela(new sf::RenderWindow(sf::VideoMode(700, 700), "Jogo")) {

	if (janela == NULL) {
		std::cout << "Erro na criação da janela!";
		exit(1);
	}
}

Gerenciadores::GerenciadorGrafico::~GerenciadorGrafico() {
	if (janela) {
		delete (janela);
		janela = NULL;
	}
}

Gerenciadores::GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico() {
	if (pGrafico == nullptr) {
		pGrafico = new GerenciadorGrafico();
	}
	return pGrafico;
}				

sf::RenderWindow* Gerenciadores::GerenciadorGrafico::getJanela() {
	return janela;
}

const bool Gerenciadores::GerenciadorGrafico::janelaAberta() {
	if (janela->isOpen()) {
		return true;
	}
	return false;
}

void Gerenciadores::GerenciadorGrafico::fechaJanela() {
	janela->close();
}

void Gerenciadores::GerenciadorGrafico::limpaJanela() {
	janela->clear();
}

void Gerenciadores::GerenciadorGrafico::mostrar() {
	janela->display();
}
/*
void Gerenciadores::GerenciadorGrafico::desenhar(sf::RectangleShape corpo) {
	janela->draw(corpo);
}*/
