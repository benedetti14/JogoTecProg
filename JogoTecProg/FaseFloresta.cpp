#include "FaseFloresta.h"

Fases::FaseFloresta::FaseFloresta() : Fase(), 
fundo("../JogoTecProg/imagens/fase1/fundo.png", (sf::Vector2f)pGrafico->getJanela()->getSize()), listaPersonagens(), listaObstaculos(), pColisor(new Gerenciadores::GerenciadorColisao(&listaPersonagens, &listaObstaculos)) {
	
	pGrafico = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
	pEventos = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();
	inicializa();
	//colisor = new Gerenciadores::GerenciadorColisao(jogador, &inimigo, &plataforma);
}

Fases::FaseFloresta::~FaseFloresta()
{
	if (pColisor) {
		delete(pColisor);
		pColisor = nullptr;
	}
}

void Fases::FaseFloresta::desenhar() {
	fundo.desenhar();
}

void Fases::FaseFloresta::inicializa(){
	Entidades::Personagens::Inimigo* inimigo = new Entidades::Personagens::Inimigo(sf::Vector2f(500.0f, 270.0f), sf::Vector2f(50.0f, 90.0f), jogador);
	Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(sf::Vector2f(0.0f, 500.0f), sf::Vector2f(2000.0f, 50.0f)); //chao

	listaPersonagens.incluiEntidade(static_cast<Entidades::Entidade*>(jogador));
	listaPersonagens.incluiEntidade(static_cast<Entidades::Entidade*>(inimigo));
	listaObstaculos.incluiEntidade(static_cast<Entidades::Entidade*>(plataforma));
}

void Fases::FaseFloresta::executar(){
	while (pGrafico->janelaAberta()) {
		pEventos->executar();
		pGrafico->limpaJanela();

		desenhar();

		listaPersonagens.executar();
		listaObstaculos.executar();

		pGrafico->mostrar();
		pColisor->executar();
	}
}
