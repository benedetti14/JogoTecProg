#include "Animacao.h"

namespace ElementosGraficos {

	Gerenciadores::GerenciadorGrafico* Animacao::pGrafico = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();

	ElementosGraficos::Animacao::Animacao(sf::RectangleShape pCorpo): corpo(pCorpo) {
	}

	ElementosGraficos::Animacao::~Animacao() {
	}

}