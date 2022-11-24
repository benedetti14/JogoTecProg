#pragma once

#include "Menu.h"
#include "Texto.h"
#include "Estado.h"
#include "Fase.h" 

namespace Menus {
	class MenuPausa : public Menu, public Estados::Estado {
	private:
		int pontos;
		Fases::Fase* pFase;
	public:
		MenuPausa(Estados::MaquinaEstado* pME, Fases::Fase* pF = nullptr);
		~MenuPausa();
		void desenhar();
		void executar();
		void atualizar();
		Estados::IdEstado getIDfase() const;
		void resetarEstado();
		void abreMenuPausa();
		int getPontos() const;
	};
}

