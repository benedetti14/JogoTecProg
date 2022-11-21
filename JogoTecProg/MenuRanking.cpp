#include "MenuRanking.h"

#define C_RANKING "..JogoTecProg/arquivos/Ranking.txt"


Menus::MenuRanking::MenuRanking(Estados::MaquinaEstado* pME): Menu(), 
Estado(pME, Estados::IdEstado::ranking), todosPontos(){
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

	for (it = todosPontos.begin(); it != todosPontos.end(); ++it) {
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
	for (it = todosPontos.begin(); it != todosPontos.end(); ++it) {
		delete (*it);
	}
	todosPontos.clear();
	criarRanking();
}

void Menus::MenuRanking::criarRanking(){
	
	std::ifstream arquivo;

	arquivo.open(C_RANKING, std::ios::binary | std::ios::in);

	if (!arquivo) {
		std::ofstream escreveArquivo(C_RANKING, std::ios::out | std::ios::trunc);
		escreveArquivo.close();
	}

	int pontos;
	std::string nome;
	std::string stringPontos;
	std::string stringTexto;

	ElementosGraficos::Texto* texto;

	for (int i = 0; i < 10; i++) {
		nome = "";
		pontos = 0;
		stringPontos = "";

		std::getline(arquivo, stringPontos);
		std::getline(arquivo, nome);

		stringTexto = std::to_string((i + 1) / 10) + std::to_string((i + 1) % 10) + " - " + nome + " ";

		if (stringPontos.length() > 0) {
			pontos = std::stoi(stringPontos);

			stringPontos += std::to_string(pontos / 1000000);
			pontos %= 1000000;

			stringPontos += std::to_string(pontos / 100000);
			pontos %= 100000;

			stringPontos += std::to_string(pontos / 10000);
			pontos %= 10000;

			stringPontos += std::to_string(pontos / 1000);
			pontos %= 1000;

			stringPontos += std::to_string(pontos / 100);
			pontos %= 100;

			stringPontos += std::to_string(pontos / 10);
			pontos %= 10;

			stringPontos += std::to_string(pontos);
		}

		while (stringTexto.length() + stringPontos.length() < 50) {
			stringTexto += ".";
		}

		texto = new ElementosGraficos::Texto(stringTexto, sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f, 100 + 40 * i));
		texto->setTamanhoFonte(48);
		texto->setCor(77, 68, 44);
		todosPontos.push_back(texto);
	}

	arquivo.close();

}
