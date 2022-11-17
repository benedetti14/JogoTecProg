#include "Jogo.h"

Jogo::Jogo() : faseFloresta(), gGrafico(gGrafico->getGerenciadorGrafico()) {
	//Ente::setGerenciadorGrafico(gGrafico);
	//faseFloresta->setGerenciadorGrafico(gGrafico);
	criaFase();
	executar();
}

Jogo::~Jogo(){
	if (faseFloresta) {
		delete (faseFloresta);
		faseFloresta = nullptr;
	}

	if (gGrafico) {
		delete gGrafico;
		gGrafico = nullptr;
	}

}

void Jogo::criaFase() {
	faseFloresta = new Fases::FaseFloresta();
}

void Jogo::executar(){
	Gerenciadores::GerenciadorEventos* pEventos = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();
	while (gGrafico->janelaAberta()) {
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
