#include "FaseDeserto.h"
#include "Estado.h"

Fases::FaseDeserto::FaseDeserto(Estados::MaquinaEstado* pME) :
	Fase(IDs::IDs::faseDeserto), Estado(pME, Estados::IdEstado::jogandoDeserto), mundo(&listaPersonagens, &listaObstaculos) {
	fundo = new Fundo("../JogoTecProg/imagens/fase2/fundo.png", (sf::Vector2f)pGrafico->getJanela()->getSize());

	//pGrafico = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
	//pEventos = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();
	//pColisor = new Gerenciadores::GerenciadorColisao(listaPersonagens, listaObstaculos);

}

Fases::FaseDeserto::~FaseDeserto() {

}

void Fases::FaseDeserto::desenhar() {
	if (jogador->getPosicao().x >= proximaPosicao.x) {
		mundo.criar(&proximaPosicao, jogador, IDs::IDs::faseDeserto);
	}
}

void Fases::FaseDeserto::inicializa() {
	//Entidades::Personagens::Jogador* jogador = new Entidades::Personagens::Jogador({ 200.0f, 300.0f }, { 35.0f, 75.0f });
	listaPersonagens.incluiEntidade(jogador);
	mundo.voltaPraOrigem();
	mundo.criar(&proximaPosicao, jogador, IDs::IDs::faseDeserto);
}

void Fases::FaseDeserto::executar() {

}

void Fases::FaseDeserto::atualizar() {
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
	else {
		faseTerminada = true;
		mudaEstado(Estados::IdEstado::menuPrincipal);
	}
	//terminarFase();
}

void Fases::FaseDeserto::resetarEstado() {
	// só reseta se o jogador perdeu, se não, continua de onde parou
	if (faseTerminada) {
		jogador = new Entidades::Personagens::Jogador({ 200.0f, 300.0f }, { 35.0f, 75.0f });
		inicializa();
		faseTerminada = false;
	}
}

Estados::IdEstado Fases::FaseDeserto::getIDfase() const {
	return Estados::IdEstado::jogandoDeserto;
}
