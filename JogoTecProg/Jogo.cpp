#include "Jogo.h"

Jogo::Jogo() : faseFloresta() {
	criaFase();
	executar();
}

Jogo::~Jogo(){
	if (faseFloresta) {
		delete (faseFloresta);
		faseFloresta = nullptr;
	}

}

void Jogo::criaFase() {
	faseFloresta = new Fases::FaseFloresta();
}

void Jogo::executar(){
	Gerenciadores::GerenciadorGrafico * pGrafico = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
	Gerenciadores::GerenciadorEventos* pEventos = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();
	while (pGrafico->janelaAberta()) {
		//pEventos->executar();
		//pGrafico->limpaJanela();
		//jogador.move();
		//inimigo.move();
		//plataforma.atualizar();
		//colisor.executar();
		//pGrafico->mostrar();
		faseFloresta->executar();
	}
}
