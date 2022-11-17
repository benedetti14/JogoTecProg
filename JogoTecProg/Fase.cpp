#include "Fase.h"

namespace Fases {

	Fase::Fase() : Ente(ID), pEventos(Gerenciadores::GerenciadorEventos::getGerenciadorEventos()), jogador() {
		jogador = new Entidades::Personagens::Jogador({ 90.0f, 0.0f }, { 50.0f, 90.0f });
		pEventos->setJogador(jogador);
	}

	Fase::~Fase() {
		if (pEventos) {
			delete pEventos;
			pEventos = nullptr;
		}
		delete (&jogador);

	}

}