#include "MenuPrincipal.h"
#define fase1 "../JogoTecProg/imagens/menu/Fase1.jpeg"
#define fase1S "../JogoTecProg/imagens/menu/Fase1_Selecionada.jpeg"
#define fase2 "../JogoTecProg/imagens/menu/Fase2.jpeg"
#define fase2S "../JogoTecProg/imagens/menu/Fase2_Selecionada.jpeg"
#define sair "../JogoTecProg/imagens/menu/Sair.jpeg"
#define sairS "../JogoTecProg/imagens/menu/Sair_Selecionado.jpeg"

Menus::MenuPrincipal::MenuPrincipal(Jogo* pJ): pJogo(pJ), Menu(), pontos(0),
Estado(pJ, Estados::IdEstado::menuPrincipal), titulo()//, iniciouFloresta(false), iniciouDeserto(false)
{
	ElementosGraficos::Botao* botao;

	botao = new ElementosGraficos::Botao(sf::Vector2f(pGrafico->getTamanhoJanela().x/2.0f, 200.0f), fase1, fase1S);
	botao->selecionar(true);
	botoes.push_back(botao);

	botao = new ElementosGraficos::Botao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f, 200.0f + 100), fase2, fase2S);
	botoes.push_back(botao);

	//botao = new ElementosGraficos::Botao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f, 200.0f + 200), "RANKING");
	//botoes.push_back(botao);

	botao = new ElementosGraficos::Botao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f, 200.0f + 300), sair, sairS);
	botoes.push_back(botao);

	/*titulo.setInfo("JOGO");
	titulo.setTamanhoFonte(140);
	titulo.setCor(77, 68, 44);
	titulo.setPosicao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f, 100.0f));*/
	maximo = 2;

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
			mudaEstado(Estados::IdEstado::jogandoFloresta);		
			break;
		case 1:
			mudaEstado(Estados::IdEstado::jogandoDeserto);			
			break;
		//case 2:
			//mudaEstado(Estados::IdEstado::ranking);
			//break;
		case 2:
			pJogo->terminarJogo();
			break;
		}
	}
}

void Menus::MenuPrincipal::resetarEstado(){
	for (int i = 0; i < botoes.size(); i++) {
		botoes[i]->selecionar(false);
	}
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
	//titulo.desenhar();
}

void Menus::MenuPrincipal::atualizar(){
	ativo = true;
	desenhar();
	pGrafico->mostrar();
}
