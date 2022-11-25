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
		/*
		std::vector<ElementosGraficos::Texto*> pontosFloresta;
		std::vector<ElementosGraficos::Texto*> pontosDeserto;
		std::vector<ElementosGraficos::Texto*>::iterator it;*/

		std::vector<sf::Text> pontosFloresta1;
		std::vector<sf::Text> pontosDeserto1;
		std::vector<sf::Text>::iterator it1;
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
