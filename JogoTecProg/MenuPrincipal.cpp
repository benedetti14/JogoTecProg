#include "MenuPrincipal.h"

Menus::MenuPrincipal::MenuPrincipal(Jogo* pJ): pJogo(pJ), Menu(), pontos(0),
Estado(pJogo, Estados::IdEstado::menuPrincipal), titulo(), iniciouFloresta(false), iniciouDeserto(false)
{
	ElementosGraficos::Botao* botao;

	botao = new ElementosGraficos::Botao(sf::Vector2f(pGrafico->getTamanhoJanela().x/2.0f, 200.0f), "FASE 1");
	botao->selecionar(true);
	botoes.push_back(botao);

	botao = new ElementosGraficos::Botao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f, 200.0f + 100), "FASE 2");
	botoes.push_back(botao);

	botao = new ElementosGraficos::Botao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f, 200.0f + 200), "RANKING");
	botoes.push_back(botao);

	botao = new ElementosGraficos::Botao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f, 200.0f + 300), "SAIR");
	botoes.push_back(botao);

	titulo.setInfo("JOGO");
	titulo.setTamanhoFonte(140);
	titulo.setCor(77.6, 68.2, 44.3);
	titulo.setPosicao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f, 100.0f));
	maximo = 3;

	ultimaFase = Estados::IdEstado::vazio;
}

Menus::MenuPrincipal::~MenuPrincipal()
{
}


void Menus::MenuPrincipal::executar(){
	if (ativo) {
		ativo = false;
		switch (selecionado) {
		case 0:
			if (iniciouFloresta) {
				mudaEstado(Estados::IdEstado::jogandoFloresta);
			} else {
				iniciouFloresta = true;
				mudaEstado(Estados::IdEstado::jogandoFloresta);
			}			
			break;
		case 1:
			if (iniciouDeserto) {
				mudaEstado(Estados::IdEstado::jogandoDeserto);
			} else {
				iniciouDeserto = true;
				mudaEstado(Estados::IdEstado::jogandoDeserto);
			}			
			break;
		case 2:
			mudaEstado(Estados::IdEstado::ranking);
			break;
		case 3:
			pJogo->terminarJogo();
			break;
		}
	}
}

void Menus::MenuPrincipal::resetarEstado(){
	botoes[selecionado]->selecionar(false);
	selecionado = 0;
	botoes[selecionado]->selecionar(true);
	
}

Estados::IdEstado Menus::MenuPrincipal::getUltimaFase() const {
	return ultimaFase;
}

int Menus::MenuPrincipal::getPontos() const {
	return pontos;
}

void Menus::MenuPrincipal::desenhar(){
	pGrafico->centralizaCamera();
	fundo.desenhar();

	for (int i = 0; i < (int)botoes.size(); i++) {
		botoes[i]->desenhar();
	}
	titulo.desenhar();
}

void Menus::MenuPrincipal::atualizar(){
	ativo = true;
}
