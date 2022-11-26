#include "MenuPausa.h"

Menus::MenuPausa::MenuPausa(Estados::MaquinaEstado* pME, Fases::Fase* pF): Menu(), Estado(pME,Estados::IdEstado::menuPausa),
pFase(pF), pontos(0) {
	ElementosGraficos::Botao* botao = nullptr;

	botao = new ElementosGraficos::Botao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f - 200, pGrafico->getTamanhoJanela().y - 100), "CONTINUAR");
	botao->selecionar(true);
	botoes.push_back(botao);

	botao = new ElementosGraficos::Botao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f + 200, pGrafico->getTamanhoJanela().y - 100), "SAIR");
	botoes.push_back(botao);

	selecionado = 0;
	maximo = 1;
}

Menus::MenuPausa::~MenuPausa(){
}

void Menus::MenuPausa::desenhar(){
	pGrafico->centralizaCamera();
	fundo.desenhar();
	for (int i = 0; i < botoes.size(); i++) {
		botoes[i]->desenhar();
	}
}

void Menus::MenuPausa::executar(){
	if (ativo) {
		ativo = false;
		switch (selecionado) {
		case 0:
			mudaEstado(pFase->getIDfase());
			break;
		case 1:
			//mudaEstado(Estados::IdEstado::fimJogo);
			mudaEstado(Estados::IdEstado::menuPrincipal);
			break;
		default:
			break;
		}
	}
}

void Menus::MenuPausa::atualizar(){
	ativo = true;
	desenhar();
	pGrafico->mostrar();
}

Estados::IdEstado Menus::MenuPausa::getIDfase() const {
	return pFase->getIDfase();
}

void Menus::MenuPausa::resetarEstado(){
	for (int i = 0; i < botoes.size(); i++) {
		botoes[i]->selecionar(false);
	}
	selecionado = 0;
	botoes[selecionado]->selecionar(true);
	ativo = true;
}

void Menus::MenuPausa::abreMenuPausa(){
	if (pMaquinaEstado->getIDEstadoAtual() == Estados::IdEstado::jogandoFloresta ||
		pMaquinaEstado->getIDEstadoAtual() == Estados::IdEstado::jogandoDeserto) {
		pontos = pFase->getPontosJogador();
		mudaEstado(Estados::IdEstado::menuPausa);
	}
}

int Menus::MenuPausa::getPontos() const {
	return pontos;
}
