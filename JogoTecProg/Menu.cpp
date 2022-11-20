#include "Menu.h"
#define FUNDO_MENU "../JogoTecProc/imagens/menu/Fundo_Menu.png"

Menus::Menu::Menu() : Ente(IDs::IDs::menu), botoes(), minimo(0), maximo(2), selecionado(1), ativo(false),
 fundo(FUNDO_MENU, (sf::Vector2f)pGrafico->getJanela()->getSize()) {
	controleMenu = new Controle::ControleMenu(this);
}

Menus::Menu::~Menu(){

	ElementosGraficos::Botao* pB = nullptr;
	while (botoes.size() != 0) {
		pB = botoes.back();
		delete(pB);
		botoes.pop_back();
	}
	botoes.clear();
}

void Menus::Menu::paraBaixo(){
	if (ativo) {
		botoes[selecionado]->selecionar(false);
		selecionado++;
		if (selecionado > maximo) {
			selecionado = minimo;
		}
		botoes[selecionado]->selecionar(true);
	}
}

void Menus::Menu::paraCima() {
	if (ativo) {
		botoes[selecionado]->selecionar(false);
		selecionado--;
		if (selecionado < minimo) {
			selecionado = maximo;
		}
		botoes[selecionado]->selecionar(true);
	}
}
