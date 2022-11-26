#include "FaseFloresta.h"
#include "Estado.h"

Fases::FaseFloresta::FaseFloresta(Estados::MaquinaEstado* pME) : 
	Fase(IDs::IDs::faseFloresta), Estado(pME, Estados::IdEstado::jogandoFloresta), mundo(&listaPersonagens, &listaObstaculos) {
	fundo = new Fundo("../JogoTecProg/imagens/fase1/fundo.png", (sf::Vector2f)pGrafico->getJanela()->getSize());

	//pGrafico = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
	//pEventos = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();
	//pColisor = new Gerenciadores::GerenciadorColisao(listaPersonagens, listaObstaculos);
	
}

Fases::FaseFloresta::~FaseFloresta(){
	
}

void Fases::FaseFloresta::desenhar() {
	if (jogador->getPosicao().x >= proximaPosicao.x) {
		mundo.criar(&proximaPosicao, jogador);
	}
}

void Fases::FaseFloresta::inicializa(){
	//Entidades::Personagens::Jogador* jogador = new Entidades::Personagens::Jogador({ 200.0f, 300.0f }, { 35.0f, 75.0f });
	listaPersonagens.incluiEntidade(jogador);
	mundo.voltaPraOrigem();
	mundo.criar(&proximaPosicao, jogador);
}

void Fases::FaseFloresta::executar() {

}

void Fases::FaseFloresta::atualizar() {
	//jogador->getPosicao().x < pGrafico->getJanela()->getSize().x
	if (jogador->estaVivo()) {
		//pEventos->executar();
		//pGrafico->limpaJanela();
		fundo->desenhar();
		
		listaPersonagens.executar();

		listaObstaculos.executar();

		//pGrafico->mostrar();
		pColisor->executar();
		pGrafico->mostrar();
	}
	//terminarFase();
	//mudaEstado(Estados::IdEstado::fimJogo);
}

void Fases::FaseFloresta::resetarEstado(){
	// só reseta se o jogador perdeu, se não, continua de onde parou
	if (faseTerminada) {
		inicializa();
		faseTerminada = false;
	}
}

Estados::IdEstado Fases::FaseFloresta::getIDfase() const {
	return Estados::IdEstado::jogandoFloresta;
}
