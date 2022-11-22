#include "Fase.h"

namespace Fases {

	Fase::Fase(IDs::IDs id) : Ente(id), //pEventos(Gerenciadores::GerenciadorEventos::getGerenciadorEventos()), 
	jogador(), listaObstaculos(), listaPersonagens(), fundo(), iniciou(false), pontosJogador(0), faseTerminada(false),
	pColisor(new Gerenciadores::GerenciadorColisao(&listaPersonagens, &listaObstaculos)) {
		jogador = new Entidades::Personagens::Jogador({ 90.0f, 0.0f }, { 35.0f, 75.0f });
		//pEventos->setJogador(jogador);
	}

	Fase::~Fase() {
		if (pColisor) {
			delete pColisor;
			pColisor = nullptr;
		}
		listaObstaculos.limparLista();
		listaPersonagens.limparLista();
	}

	void Fase::criaPlataforma(sf::Vector2f pos, sf::Vector2f tam){

		Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(pos, tam); 
		if (plataforma) {
			listaObstaculos.incluiEntidade(static_cast<Entidades::Entidade*>(plataforma));
		}

	}

	void Fase::criaCaixa(sf::Vector2f pos, sf::Vector2f tam){
		Entidades::Obstaculos::Caixa* caixa = new Entidades::Obstaculos::Caixa(pos, tam);
		if (caixa) {
			listaObstaculos.incluiEntidade(static_cast<Entidades::Entidade*>(caixa));
		}
	}

	void Fase::criaInimigo(sf::Vector2f pos, sf::Vector2f tam){

		Entidades::Personagens::Inimigos::Dinossauro* dino = new Entidades::Personagens::Inimigos::Dinossauro(pos, tam, jogador);
		if (dino) {
			listaPersonagens.incluiEntidade(static_cast<Entidades::Entidade*>(dino));
		}
		
	}

	void Fase::criarEntidades(char letra, sf::Vector2f pos) {
		{
			switch (letra) {
			case 'P':
				criaPlataforma(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f), { 300.0f, 50.0f });
				break;
			case 'C':
				criaCaixa(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f), { 50.0f, 50.0f });
				break;
			case 'I':
				criaInimigo(sf::Vector2f(pos.x * 50.0f, pos.y * 50.0f), { 35.0f, 75.0f });
				break;
			default:
				break;
			}
		}
}
	void Fase::terminarFase() {
		pontosJogador = jogador->getPontos();
		faseTerminada = true;
		//listaObstaculos.limparLista();
		//listaPersonagens.limparLista();
	}

	int Fase::getPontosJogador() const {
		return pontosJogador;
	}
	
}
