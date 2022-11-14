#include "FaseFloresta.h"

Fases::FaseFloresta::FaseFloresta() : Fase(), 
fundo("../imagens/fase1/fundo.png", (sf::Vector2f)pGrafico->getJanela()->getSize()) {
	
	pGrafico = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
	pEventos = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();
	inicializa();
	//colisor = new Gerenciadores::GerenciadorColisao(jogador, &inimigo, &plataforma);
}

Fases::FaseFloresta::~FaseFloresta()
{
}

void Fases::FaseFloresta::inicializa(){
	Entidades::Personagens::Inimigo inimigo(sf::Vector2f(500.0f, 370.0f), sf::Vector2f(50.0f, 90.0f), jogador);
	Entidades::Obstaculos::Plataforma plataforma(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(800.0f, 50.0f)); //chao

	listaEntidades.incluiEntidade(static_cast<Entidades::Entidade*>(jogador));
	listaEntidades.incluiEntidade(static_cast<Entidades::Entidade*>(&inimigo));
	listaEntidades.incluiEntidade(static_cast<Entidades::Entidade*>(&plataforma));
}

void Fases::FaseFloresta::executar(){
	while (pGrafico->janelaAberta()) {
		pEventos->executar();
		pGrafico->limpaJanela();

		fundo.desenhar();
		//jogador->move();
		//inimigo.move();
		//plataforma.atualizar();
		listaEntidades.executar();
		//colisor->executar();
		pGrafico->mostrar();
	}
}
