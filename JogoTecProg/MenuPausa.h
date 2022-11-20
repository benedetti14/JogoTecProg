#pragma once

#include "Menu.h"
#include "Fase.h"
#include "Estado.h"

namespace Menus {
	class MenuPausa : public Menu, public Estados::Estado {
	private:
		//Fases::Fase* pFase;
		Estados::IdEstado IdFase;
		int pontos;
	public:
		MenuPausa(Estados::MaquinaEstado* pM = nullptr, Estados::IdEstado id = Estados::IdEstado::vazio);
		~MenuPausa();
		void executar();
		void desenhar();
		void atualizar();
		void resetarEstado();
		void setPontos(int p);
		int getPontos() const;
		Estados::IdEstado getIDfase() const;
	};
}
