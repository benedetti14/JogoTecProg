#include "ControleJogador.h"

Controle::ControleJogador::ControleJogador(): pJogador(nullptr) {
}

Controle::ControleJogador::~ControleJogador(){
}

void Controle::ControleJogador::setJogador(Entidades::Personagens::Jogador* pJ){
	pJogador = pJ;
}

void Controle::ControleJogador::notificaTeclaPressionada(std::string tecla){

}

void Controle::ControleJogador::notificaTeclaSolta(std::string tecla)
{
}

