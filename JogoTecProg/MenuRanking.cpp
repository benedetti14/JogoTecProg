#include "MenuRanking.h"
#include <fstream>

#define C_RANKING1 "..JogoTecProg/arquivos/Ranking1.txt"
#define C_RANKING2 "..JogoTecProg/arquivos/Ranking2.txt"


Menus::MenuRanking::MenuRanking(Estados::MaquinaEstado* pME): Menu(), 
Estado(pME, Estados::IdEstado::ranking), pontosFloresta(), pontosDeserto() {
	ElementosGraficos::Botao* botao = nullptr;

	botao = new ElementosGraficos::Botao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2, pGrafico->getTamanhoJanela().y - 100), "VOLTAR");
	botao->selecionar(true);
	botoes.push_back(botao);

	maximo = 0;

}

Menus::MenuRanking::~MenuRanking()
{
}

void Menus::MenuRanking::atualizar(){
	ativo = true;
}

void Menus::MenuRanking::desenhar(){
	pGrafico->centralizaCamera();
	fundo.desenhar();

	for (int i = 0; i < botoes.size(); i++) {
		botoes[i]->desenhar();
	}

	for (it = pontosFloresta.begin(); it != pontosFloresta.end(); ++it) {
		(*it)->desenhar();
	}

	for (it = pontosDeserto.begin(); it != pontosDeserto.end(); ++it) {
		(*it)->desenhar();
	}
}

void Menus::MenuRanking::executar(){
	if (ativo) {
		ativo = false;
		mudaEstado(Estados::IdEstado::menuPrincipal);
	}
}

void Menus::MenuRanking::resetarEstado(){
	botoes[0]->selecionar(true);
	for (it = pontosFloresta.begin(); it != pontosFloresta.end(); ++it) {
		delete (*it);
	}
	for (it = pontosDeserto.begin(); it != pontosDeserto.end(); ++it) {
		delete (*it);
	}
	pontosFloresta.clear();
	pontosDeserto.clear();
	criarRanking();
}

void Menus::MenuRanking::criarRanking(){
	
	std::ifstream arquivo;

	int pontos;
	std::string nome;
	std::string stringPontos;
	std::string stringTexto;

	ElementosGraficos::Texto* texto;
	// fase 1

	arquivo.open(C_RANKING1, std::ios::binary | std::ios::in);

	if (!arquivo) {
		std::ofstream escreveArquivo(C_RANKING1, std::ios::out | std::ios::trunc);
		escreveArquivo.close();
	}

	texto = new ElementosGraficos::Texto("Fase Floresta", sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f, 90));

	for (int i = 0; i < 5; i++) {
		nome = "";
		pontos = 0;
		stringPontos = "";

		std::getline(arquivo, stringPontos);
		std::getline(arquivo, nome);

		stringTexto = nome + " - " + stringPontos;
		pontos = std::stoi(stringPontos);

		texto = new ElementosGraficos::Texto(stringTexto, sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f, 100 + 10 * i));
		texto->setTamanhoFonte(48);
		texto->setCor(77, 68, 44);
		pontosFloresta.push_back(texto);
	}

	arquivo.close();

	// fase 2

	arquivo.open(C_RANKING2, std::ios::binary | std::ios::in);

	if (!arquivo) {
		std::ofstream escreveArquivo(C_RANKING2, std::ios::out | std::ios::trunc);
		escreveArquivo.close();
	}

	texto = new ElementosGraficos::Texto("Fase Deserto", sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f, 150));

	for (int i = 0; i < 5; i++) {
		nome = "";
		pontos = 0;
		stringPontos = "";

		std::getline(arquivo, stringPontos);
		std::getline(arquivo, nome);

		stringTexto = nome + " - " + stringPontos;
		pontos = std::stoi(stringPontos);

		texto = new ElementosGraficos::Texto(stringTexto, sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f, 160 + 10 * i));
		texto->setTamanhoFonte(48);
		texto->setCor(77, 68, 44);
		pontosDeserto.push_back(texto);
	}

	arquivo.close();

}
