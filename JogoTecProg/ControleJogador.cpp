#include "ControleJogador.h"

Controle::ControleJogador::ControleJogador(Entidades::Personagens::Jogador* pJ) : pJogador(pJ),
direita("Right"), esquerda("Left"), pula("Up"), ataca("X"), empodera("P"), mapaTeclas() {

	mapaTeclas.insert(std::pair<std::string, bool>(direita,false));
	mapaTeclas.insert(std::pair<std::string, bool>(esquerda, false));
	mapaTeclas.insert(std::pair<std::string, bool>(pula, false));
	mapaTeclas.insert(std::pair<std::string, bool>(ataca, false));
	mapaTeclas.insert(std::pair<std::string, bool>(empodera, false));
}

Controle::ControleJogador::~ControleJogador(){
}

void Controle::ControleJogador::setJogador(Entidades::Personagens::Jogador* pJ){
	pJogador = pJ;
}

void Controle::ControleJogador::notificaTeclaPressionada(std::string tecla){
	if (tecla == direita) {
		pJogador->andar(false);
		mapaTeclas[direita] = true;
	} else if (tecla == esquerda) {
		pJogador->andar(true);
		mapaTeclas[esquerda] = true;
	} else if (tecla == pula) {
		pJogador->pular();
		mapaTeclas[pula] = true;
	} else if (tecla == ataca) {
		pJogador->atacar(true);
		mapaTeclas[ataca] = true;
	} else if (tecla == empodera) {
		pJogador->empoderar();
		mapaTeclas[empodera] = true;
	} else {
		pJogador->parar();
	}

}

void Controle::ControleJogador::notificaTeclaSolta(std::string tecla){
	if (tecla == direita) {
		pJogador->parar();
		mapaTeclas[direita] = false;
	} else if (tecla == esquerda) {
		pJogador->parar();
		mapaTeclas[esquerda] = false;
	} else if (tecla == pula) {
		
		mapaTeclas[pula] = false;
	} else if (tecla == ataca) {
		
		mapaTeclas[ataca] = false;
	}
	else if (tecla == empodera) {
		
		mapaTeclas[empodera] = false;
	}
}

void Controle::ControleJogador::setTecla(std::string direita, std::string esquerda, std::string pula, std::string empodera, std::string ataca)
{
	this->direita = direita;
	this->esquerda = esquerda;
	this->pula = pula;
	this->ataca = ataca;
	this->empodera = empodera;
}

