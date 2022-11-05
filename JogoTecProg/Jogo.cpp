#include "Jogo.h"

Jogo::Jogo() : pGrafico(pGrafico->getGerenciadorGrafico()), pEventos(pEventos->getGerenciadorEventos()),
jogador({ 0.0f , 100.0f }, { 1.5f, 1.5f }, { 50.0f, 50.0f }) {
	
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
		//desenhaJogador
		pGrafico->desenhar(jogador.getCorpo());
		pGrafico->mostrar();
	}
}
