#pragma once

#include "Menu.h"
#include "Estado.h"
#include "MaquinaEstados.h"
#include "Fase.h"


namespace Menus {
	class MenuPausa : public Menu, public Estados::Estado {
	private:
		Fases::Fase* pFase;
		int pontos;
	public:
		MenuPausa(Estados::MaquinaEstado* pME = nullptr, Fases::Fase* pF = nullptr);
		~MenuPausa();
		void executar();
		void desenhar();
		void atualizar();
		void resetarEstado();
		void setPontos(int p);
		int getPontos() const;
		Estados::IdEstado getIDfase() const;
		void abreMenuPausa();
	};
}
