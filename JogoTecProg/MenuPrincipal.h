#pragma once

#include "Menu.h"
#include "Estado.h"
#include "Jogo.h"

class Jogo;


namespace Menus {
	class MenuPrincipal : public Menu, public Estados::Estado {
	private: 
		Jogo* pJogo;
		Estados::IdEstado ultimaFase;
		int pontos;
	public:
		MenuPrincipal(Jogo* pJ = nullptr);
		~MenuPrincipal();
		void desenhar();
		void atualizar();
		virtual void executar();
		void resetarEstado();
		Estados::IdEstado getUltimaFase() const;
		int getPontos() const;
	};
}

class MenuPrincipal
{
};
