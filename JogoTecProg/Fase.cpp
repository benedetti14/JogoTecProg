#include "Fase.h"

namespace Fases {

	Fase::Fase(IDs::IDs id) : Ente(id), //pEventos(Gerenciadores::GerenciadorEventos::getGerenciadorEventos()), 
	jogador(), listaObstaculos(), listaPersonagens(), fundo(), iniciou(false), pontosJogador(0), faseTerminada(false),
	pColisor(new Gerenciadores::GerenciadorColisao(&listaPersonagens, &listaObstaculos)) {
		jogador = new Entidades::Personagens::Jogador({ 200.0f, 300.0f }, { 35.0f, 75.0f });
		//pEventos->setJogador(jogador);
	}

	Fase::~Fase() {
		if (pColisor) {
			delete pColisor;
			pColisor = nullptr;
		}
		//listaObstaculos.limparLista();
		//listaPersonagens.limparLista();
	}


	void Fase::terminarFase() {
		faseTerminada = true;
		listaObstaculos.limparLista();
		listaPersonagens.limparLista();
	}

	int Fase::getPontosJogador() const {
		return pontosJogador;
	}
	
}
