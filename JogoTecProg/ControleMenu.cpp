#include "ControleMenu.h"


Controle::ControleMenu::ControleMenu(Menus::Menu* pM) : Observer(), menu(pM) {
}

Controle::ControleMenu::~ControleMenu(){
	menu = nullptr;
}

void Controle::ControleMenu::notificaTeclaPressionada(std::string tecla){
	if (menu == nullptr) {
		std::cout << "Controle Menu: ponteiro para menu nulo!" << std:: endl;
		exit(1);
	}

	if (tecla == "Down") {
		menu->paraBaixo();
	} else if (tecla == "Up") {
		menu->paraCima();
	} else if (tecla == "Enter") {
		menu->executar();
	} else if (tecla == "Escape") {
		/*if (dynamic_cast<Menus::MenuPausa*>(menu) != nullptr) {
			dynamic_cast<Menus::MenuPausa*>(menu)->abreMenuPausa();
		}*/
	}
}

void Controle::ControleMenu::notificaTeclaSolta(std::string tecla){
}

void Controle::ControleMenu::setMenu(Menus::Menu* pM){
	menu = pM;
}
