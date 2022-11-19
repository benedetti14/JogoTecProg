#include "Jogo.h"

Jogo::Jogo() : faseFloresta(), gGrafico(nullptr), MaquinaEstado() {
	gGrafico = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
	Ente::setGerenciadorGrafico(Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico());
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
	faseFloresta = new Fases::FaseFloresta(this);
	
	fase = static_cast<Fases::Fase*>(faseFloresta);
	fase->criarMapa();

	Estados::Estado* estado = faseFloresta;
	estado = static_cast<Estados::Estado*>(faseFloresta);
	incluiEstado(estado);

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
		//faseFloresta->executar();
		executarEstadoAtual();
	}
}
