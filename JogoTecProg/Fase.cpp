#include "Fase.h"

namespace Fases {

	Fase::Fase(IDs::IDs id) : Ente(id),
	jogador(), listaObstaculos(), listaPersonagens(), fundo(), iniciou(false), pontosJogador(0), faseTerminada(false),
	pColisor(new Gerenciadores::GerenciadorColisao(&listaPersonagens, &listaObstaculos)) {
		jogador = new Entidades::Personagens::Jogador({ 200.0f, 300.0f }, { 35.0f, 75.0f });
	}

	Fase::~Fase() {
		if (pColisor) {
			delete pColisor;
			pColisor = nullptr;
		}
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
