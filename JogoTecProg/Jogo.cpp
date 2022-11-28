#include "Jogo.h"

Jogo::Jogo() : faseFloresta(), faseDeserto(), gGrafico(nullptr), MaquinaEstado() {
	gGrafico = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
	Ente::setGerenciadorGrafico(Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico());
	criaFase();

	Estados::Estado* estado;

	estado = static_cast<Estados::Estado*>(faseFloresta);
	incluiEstado(estado);

	estado = static_cast<Estados::Estado*>(faseDeserto);
	incluiEstado(estado);

	estado = static_cast<Estados::Estado*>(new Menus::MenuPrincipal(this));
	incluiEstado(estado);

	estado = static_cast<Estados::Estado*>(new Menus::MenuPausa(this, faseFloresta));
	incluiEstado(estado);

	mudarEstadoAtual(Estados::IdEstado::menuPrincipal);

	executar();
}

Jogo::~Jogo(){
	if (faseFloresta) {
		delete (faseFloresta);
		faseFloresta = nullptr;
	}

	if (faseDeserto) {
		delete (faseDeserto);
		faseDeserto = nullptr;
	}

	if (gGrafico) {
		delete gGrafico;
		gGrafico = nullptr;
	}

}

void Jogo::criaFase() {
	faseFloresta = new Fases::FaseFloresta(this);
	faseDeserto = new Fases::FaseDeserto(this);
	
	faseFloresta->inicializa();
	faseDeserto->inicializa();
}

void Jogo::executar(){
	Gerenciadores::GerenciadorEventos* pEventos = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();
	while (gGrafico->janelaAberta()) {
		pEventos->executar();
		
		gGrafico->limpaJanela();
		
		atualizarEstadoAtual();
		desenharEstadoAtual();
	}
}

void Jogo::terminarJogo(){
	gGrafico->fechaJanela();
}
