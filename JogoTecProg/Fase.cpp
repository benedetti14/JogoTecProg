#include "Fase.h"

namespace Fases {

	Fase::Fase(IDs::IDs id) : Ente(id), pEventos(Gerenciadores::GerenciadorEventos::getGerenciadorEventos()), jogador(),
	listaObstaculos(), listaPersonagens(), fundo(), pColisor() {
		jogador = new Entidades::Personagens::Jogador({ 90.0f, 0.0f }, { 50.0f, 90.0f });
		pEventos->setJogador(jogador);
	}

	Fase::~Fase() {
		if (pColisor) {
			delete pColisor;
			pColisor = nullptr;
		}
		listaObstaculos->limparLista();
		listaPersonagens->limparLista();
	}

	void Fase::criaPlataforma(sf::Vector2f pos, sf::Vector2f tam){

		Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(pos, tam); 
		if (plataforma) {
			listaObstaculos->incluiEntidade(static_cast<Entidades::Entidade*>(plataforma));
		}

	}

	void Fase::criaCaixa(sf::Vector2f pos, sf::Vector2f tam){

	}

	void Fase::criaInimigo(sf::Vector2f pos, sf::Vector2f tam){

		Entidades::Personagens::Inimigo* inimigo = new Entidades::Personagens::Inimigo(pos, tam, jogador);
		if (inimigo) {
			listaPersonagens->incluiEntidade(static_cast<Entidades::Entidade*>(inimigo));
		}
		
	}

}