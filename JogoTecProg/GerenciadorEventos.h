#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"
#include "GerenciadorEntrada.h"
//#include "Jogador.h"

namespace Gerenciadores {
	class GerenciadorEventos {
	private:
		GerenciadorEntrada* pEntrada;
		GerenciadorGrafico* pGrafico;
		static GerenciadorEventos* pEventos;
		//Entidades::Personagens::Jogador* pJogador;
		GerenciadorEventos();
	public:
		~GerenciadorEventos();
		static GerenciadorEventos* getGerenciadorEventos();
		//void setJogador(Entidades::Personagens::Jogador* jogador);
		//void verificaTeclaPressionada(sf::Keyboard::Key tecla);
		//void verificaTeclaSolta(sf::Keyboard::Key tecla);
		void executar();
	};
}