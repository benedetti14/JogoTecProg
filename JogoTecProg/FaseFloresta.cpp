#include "FaseFloresta.h"
#include "Estado.h"

Fases::FaseFloresta::FaseFloresta(Estados::MaquinaEstado* pME) : 
	Fase(IDs::IDs::faseFloresta), Estado(pME, Estados::IdEstado::jogandoFloresta), mundo(&listaPersonagens, &listaObstaculos) {
	fundo = new Fundo("../JogoTecProg/imagens/fase1/fundo.png", (sf::Vector2f)pGrafico->getJanela()->getSize());
	
}

Fases::FaseFloresta::~FaseFloresta(){
	
}

void Fases::FaseFloresta::desenhar() {
	if (jogador->getPosicao().x >= proximaPosicao.x) {
		mundo.criar(&proximaPosicao, jogador, IDs::IDs::faseFloresta);
	}
}

void Fases::FaseFloresta::inicializa(){
	listaPersonagens.incluiEntidade(jogador);
	mundo.voltaPraOrigem();
	mundo.criar(&proximaPosicao, jogador, IDs::IDs::faseFloresta);
}

void Fases::FaseFloresta::executar() {

}

void Fases::FaseFloresta::atualizar() {
	if (jogador->estaVivo()) {
		fundo->desenhar();
		
		listaPersonagens.executar();

		listaObstaculos.executar();

		pColisor->executar();
		pGrafico->mostrar();
	}
	else {
		faseTerminada = true;
		mudaEstado(Estados::IdEstado::menuPrincipal);
	}
}

void Fases::FaseFloresta::resetarEstado(){
	// só reseta se o jogador perdeu, se não, continua de onde parou
	if (faseTerminada) {
		jogador = new Entidades::Personagens::Jogador({ 200.0f, 300.0f }, { 35.0f, 75.0f });
		inicializa();
		faseTerminada = false;
	}
}

Estados::IdEstado Fases::FaseFloresta::getIDfase() const {
	return Estados::IdEstado::jogandoFloresta;
}
