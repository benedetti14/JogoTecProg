#include "Jogo.h"

Jogo::Jogo() : faseFloresta(), gGrafico(nullptr), MaquinaEstado() {
	gGrafico = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
	Ente::setGerenciadorGrafico(Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico());
	//faseFloresta->setGerenciadorGrafico(gGrafico);
	criaFase();

	Estados::Estado* estado;

	estado = static_cast<Estados::Estado*>(faseFloresta);
	incluiEstado(estado);

	estado = static_cast<Estados::Estado*>(new Menus::MenuPrincipal(this));
	incluiEstado(estado);

	estado = static_cast<Estados::Estado*>(new Menus::MenuFimJogo(this, fase));
	incluiEstado(estado);

	estado = static_cast<Estados::Estado*>(new Menus::MenuRanking(this));
	incluiEstado(estado);

	estado = static_cast<Estados::Estado*>(new Menus::MenuPausa(this, fase));
	incluiEstado(estado);

	mudarEstadoAtual(Estados::IdEstado::menuPrincipal);

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
}

void Jogo::executar(){
	Gerenciadores::GerenciadorEventos* pEventos = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();
	while (gGrafico->janelaAberta()) {
		pEventos->executar();
		gGrafico->limpaJanela();
		//jogador.move();
		//inimigo.move();
		//plataforma.atualizar();
		//colisor.executar();
		//pGrafico->mostrar();
		//faseFloresta->executar();
		atualizarEstadoAtual();
		desenharEstadoAtual();
		gGrafico->mostrar();
	}
}

void Jogo::terminarJogo(){
	gGrafico->fechaJanela();
}
