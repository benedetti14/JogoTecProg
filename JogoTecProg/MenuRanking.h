#pragma once

#include <SFML\Graphics.hpp>
#include "Menu.h"
#include "Texto.h"
#include "Estado.h"
#include "Botao.h"
#include <vector>
#include <iostream>

namespace ElementosGraficos {
	class Texto;
}

namespace Menus {
	class MenuRanking : public Menu, public Estados::Estado {
	private:
		std::vector<ElementosGraficos::Texto*> todosPontos;
		std::vector<ElementosGraficos::Texto*>::iterator it;
	public:
		MenuRanking(Estados::MaquinaEstado* pME = nullptr);
		~MenuRanking();
		void atualizar();
		void desenhar();
		void executar();
		void resetarEstado();
		void criarRanking();
	};
}
