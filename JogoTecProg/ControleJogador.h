#pragma once

#include "Jogador.h"
#include "Observer.h"

#include <map>

namespace Entidades {
	namespace Personagens {
		class Jogador;
	}
}

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
		std::map<std::string, bool> mapaTeclas;
		
	public:
		ControleJogador(Entidades::Personagens::Jogador* pJ = nullptr);
		~ControleJogador();
		void setJogador(Entidades::Personagens::Jogador* pJ);
		void notificaTeclaPressionada(std::string tecla);
		void notificaTeclaSolta(std::string tecla);
		void setTecla(std::string direita, std::string esquerda, std::string pula, std::string empodera, std::string ataca);
	};
}