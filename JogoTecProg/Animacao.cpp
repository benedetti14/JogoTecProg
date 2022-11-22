#include "Animacao.h"

namespace ElementosGraficos {

	Gerenciadores::GerenciadorGrafico* Animacao::pGrafico = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();

	ElementosGraficos::Animacao::Animacao(): corpo() {
	}

	ElementosGraficos::Animacao::~Animacao() {
	}
	
	void ElementosGraficos::Animacao::desenhar() {
		pGrafico->getJanela()->draw(corpo);
	}
	void Animacao::setPosicao(sf::Vector2f pos)	{
		corpo.setPosition(pos);
	}
}