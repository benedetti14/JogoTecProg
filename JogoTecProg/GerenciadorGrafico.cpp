#include "GerenciadorGrafico.h"
#include <stdlib.h>
#include <iostream>

GerenciadorGrafico* GerenciadorGrafico::pGrafico = NULL;

GerenciadorGrafico::GerenciadorGrafico() {

	janela = new sf::RenderWindow(sf::VideoMode(700, 700), "janela");
	if (janela == NULL) {
		std::cout << "Erro na criação da janela!";
		return;
	}
}

GerenciadorGrafico::~GerenciadorGrafico() {
	if (janela) {
		delete (janela);
		janela = NULL;
	}
}

GerenciadorGrafico* GerenciadorGrafico::getGerenciadorGrafico() {
	if (pGrafico == NULL) {
		return new GerenciadorGrafico();
	}
	return pGrafico;
}

sf::RenderWindow* GerenciadorGrafico::getJanela() {
	return pGrafico->janela;
}

const bool GerenciadorGrafico::janelaAberta() {
	if (janela->isOpen()) {
		return true;
	}
	return false;
}

void GerenciadorGrafico::fechaJanela() {
	janela->close();
}

void GerenciadorGrafico::limpaJanela() {
	janela->clear();
}

void GerenciadorGrafico::mostrar() {
	janela->display();
}
