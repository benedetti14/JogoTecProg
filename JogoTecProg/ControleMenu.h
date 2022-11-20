#pragma once

#include "Menu.h"
#include "Observer.h"

namespace Menus {
	class Menu;
}

namespace Controle {

	class ControleMenu : public Observer {
	private:
		Menus::Menu* menu;
	public:
		ControleMenu(Menus::Menu* pM = nullptr);
		~ControleMenu();
		void notificaTeclaPressionada(std::string tecla);
		void notificaTeclaSolta(std::string tecla);
		void setMenu(Menus::Menu* pM);
	};
}
