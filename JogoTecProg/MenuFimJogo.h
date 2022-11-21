#pragma once

#include "Jogo.h"
#include "Menu.h"
#include "Estado.h"
#include "GerenciadorEntrada.h"
#include "Texto.h"
#include "Botao.h"
#include "ControleTexto.h"

namespace Controle {
	class ControleTexto;
};

namespace Menus {
	class MenuFimJogo: public Menu, public Estados::Estado{
	private:
		ElementosGraficos::Texto titulo;
		ElementosGraficos::Texto nome;
		ElementosGraficos::Texto nomeLegenda;
		ElementosGraficos::Texto pontos;
		Controle::ControleTexto* pControle;
		unsigned int pontosIncrementar;
		//Estados::IdEstado Idfase;
		Fases::Fase* pFase;

	public:
		MenuFimJogo(Estados::MaquinaEstado *pME, Fases::Fase* pF);
		~MenuFimJogo();
		void atualizar();
		void desenhar();
		void executar();
		void resetarEstado();
		void incluirNoRanking();
	};
}
