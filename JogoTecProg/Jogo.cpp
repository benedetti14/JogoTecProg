#include "Jogo.h"

Jogo::Jogo() : pGrafico(pGrafico->getGerenciadorGrafico()), pEventos(pEventos->getGerenciadorEventos()),
jogador(sf::Vector2f(100.0f, 400.0f), sf::Vector2f(50.0f, 90.0f)), inimigo(sf::Vector2f(500.0f, 100.0f), sf::Vector2f(50.0f, 90.0f), &jogador) {
	
	pEventos->setJogador(&jogador);
	executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar(){
	while (pGrafico->janelaAberta()) {
		pEventos->executar();
		pGrafico->limpaJanela();
		jogador.move();
		inimigo.move();
		pGrafico->mostrar();
	}
}
