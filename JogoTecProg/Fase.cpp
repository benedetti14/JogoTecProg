#include "Fase.h"

namespace Fases {

	Fase::Fase() : Ente(ID), pEventos(), colisor(), jogador() {
		jogador = new Entidades::Personagens::Jogador({ 90.0f, 300.0f }, { 50.0f, 90.0f });
	}

	Fase::~Fase() {
		if (pEventos) {
			delete pEventos;
			pEventos = nullptr;
		}
		if (colisor) {
			delete colisor;
			colisor = nullptr;
		}
		delete (&jogador);

	}

}