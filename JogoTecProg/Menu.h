#pragma once

#include <vector>
#include "Ente.h"
#include "Botao.h"
#include "ControleMenu.h"
#include "Fundo.h"

namespace Controle {
	class ControleMenu;
}

namespace Menus {
	class Menu : public Ente {
	protected:
		std::vector<ElementosGraficos::Botao*> botoes;
		std::vector<ElementosGraficos::Botao*> iterador;
		int minimo;
		int maximo;
		int selecionado;
		Controle::ControleMenu* controleMenu;
		bool ativo;
		Fundo fundo;
	public:
		Menu();
		~Menu();
		void paraBaixo();
		void paraCima();
		virtual void executar() = 0;
	};
}

class Menu
{
};
