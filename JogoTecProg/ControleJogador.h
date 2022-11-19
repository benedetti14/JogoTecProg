#pragma once

#include "Jogador.h"
#include "Observer.h"

namespace Controle {
	class ControleJogador : public Observer {
	private:
		Entidades::Personagens::Jogador* pJogador;
		std::string direita;
		std::string esquerda;
		std::string pula;
		std::string empodera;
		std::string ataca;
		//std::string corre;
		
	public:
		ControleJogador();
		~ControleJogador();
		void setJogador(Entidades::Personagens::Jogador* pJ);
		void notificaTeclaPressionada(std::string tecla);
		void notificaTeclaSolta(std::string tecla);
	};
}