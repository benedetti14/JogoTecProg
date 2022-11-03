#include "GerenciadorGrafico.h"
#include <stdlib.h>
#include <iostream>

Gerenciadores::GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::pGrafico = NULL;

Gerenciadores::GerenciadorGrafico::GerenciadorGrafico() {

	janela = new sf::RenderWindow(sf::VideoMode(700, 700), "janela");
	if (janela == NULL) {
		std::cout << "Erro na criação da janela!";
		return;
	}
}

Gerenciadores::GerenciadorGrafico::~GerenciadorGrafico() {
	if (janela) {
		delete (janela);
		janela = NULL;
	}
}

Gerenciadores::GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico() {
	if (pGrafico == NULL) {
		return new GerenciadorGrafico();
	}
	return pGrafico;
}				

sf::RenderWindow* Gerenciadores::GerenciadorGrafico::getJanela() {
	return pGrafico->janela;
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
