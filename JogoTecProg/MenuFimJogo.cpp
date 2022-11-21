#include "MenuFimJogo.h"

#define C_RANKING "..JogoTecProg/arquivos/Ranking.txt"

Menus::MenuFimJogo::MenuFimJogo(Estados::MaquinaEstado* pME, Fases::Fase* pF):
	Menu(), Estado(pME, Estados::IdEstado::fimJogo), titulo(), nome(), pControle(new Controle::ControleTexto()), 
	pontosIncrementar(0), pFase(pF), pontos(), nomeLegenda()
{
	ElementosGraficos::Botao* botao = nullptr;

	botao = new ElementosGraficos::Botao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f - 200, pGrafico->getTamanhoJanela().y - 100), "JOGAR NOVAMENTE");
	botao->selecionar(true);
	botoes.push_back(botao);

	botao = new ElementosGraficos::Botao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f + 200, pGrafico->getTamanhoJanela().y - 100), "MENU PRINCIPAL");
	botoes.push_back(botao);

	selecionado = 0;
	maximo = 1;

	titulo.setPosicao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f, pGrafico->getTamanhoJanela().y / 2 - 200));
	titulo.setTamanhoFonte(100);
	titulo.setCor(77, 68, 44);

	pontos.setPosicao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f - 100, pGrafico->getTamanhoJanela().y / 2));
	pontos.setTamanhoFonte(40);
	pontos.setCor(77, 68, 44);

	nomeLegenda.setPosicao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f - 200, pGrafico->getTamanhoJanela().y / 2 + 100));
	nomeLegenda.setTamanhoFonte(40);
	nomeLegenda.setCor(77, 68, 44);

	nome.setPosicao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f + nomeLegenda.getTamanho().x - 200, pGrafico->getTamanhoJanela().y / 2 + 100 - nomeLegenda.getTamanho().y));
	nome.setTamanhoFonte(100);
	nome.setCor(77, 68, 44);

}

Menus::MenuFimJogo::~MenuFimJogo()
{
}

void Menus::MenuFimJogo::atualizar(){
	nome.setInfo(pControle->getString());
	if (pMaquinaEstado->getIDUltimoEstado() == Estados::IdEstado::menuPausa) {
		Menus::MenuPausa* menu = dynamic_cast<Menus::MenuPausa*>(pMaquinaEstado->getUltimoEstado());
		if (pontosIncrementar < menu->getPontos()) {
			pontosIncrementar += 10;
		}
		pontos.setInfo("Pontos: " + std::to_string(menu->getPontos()));
	}
	else {
		if (pontosIncrementar < pFase->getPontosJogador()) {
			pontosIncrementar += 10;
		}
		pontos.setInfo("Pontos: " + std::to_string(pFase->getPontosJogador()));
	}
}

void Menus::MenuFimJogo::desenhar(){
	pGrafico->centralizaCamera();
	fundo.desenhar();
	for (int i = 0; i < botoes.size(); i++) {
		botoes[i]->desenhar();
	}
	titulo.desenhar();
	pontos.desenhar();
	nome.desenhar();
	nomeLegenda.desenhar();
}

void Menus::MenuFimJogo::executar(){
	if (ativo) {
		ativo = false;
		switch (selecionado) {
		case 0:
			mudaEstado(pFase->getIDfase());
			break;
		case 1:
			mudaEstado(Estados::IdEstado::menuPrincipal);
			break;
		}
		incluirNoRanking();
	}
}

void Menus::MenuFimJogo::resetarEstado(){
	for (int i = 0; i < botoes.size(); i++) {
		botoes[i]->selecionar(false);
	}
	selecionado = 0;
	ativo = true;
	pControle->resetar();
}

void Menus::MenuFimJogo::incluirNoRanking(){
	unsigned int pontosJogador;

	if (pMaquinaEstado->getIDUltimoEstado() == Estados::IdEstado::menuPausa) {
		Menus::MenuPausa* menu = dynamic_cast<Menus::MenuPausa*>(pMaquinaEstado->getUltimoEstado());
		pontosJogador = menu->getPontos();
	}
	else {
		pontosJogador = pFase->getPontosJogador();
	}

	// ler o arquivo

	std::ifstream lerArquivo;

	lerArquivo.open(C_RANKING, std::ios::in);

	std::multimap<int, std::string> mapaPontosNome;

	if (lerArquivo) {
		unsigned int pontos;
		std::string nome;
		std::string stringPontos;

		for (int i = 0; i < 10; i++) {
			std::getline(lerArquivo, stringPontos);
			std::getline(lerArquivo, nome);
			if (stringPontos.length() > 0) {
				mapaPontosNome.insert(std::pair<int, std::string>(std::stoi(stringPontos), nome));
			}
		}
		lerArquivo.close();
	}

	// escrevendo no arquivo
	if (pontosJogador != 0 && pControle->getString().length() > 1) {
		mapaPontosNome.insert(std::pair<int, std::string>(pontosJogador, pControle->getString()));
	}

	std::ofstream escreveArquivo;
	escreveArquivo.open(C_RANKING, std::ios::out | std::ios::trunc);

	if (!escreveArquivo) {
		std::cout << "Menu FimJogo: erro ao escrever no arquivo " << std::endl;
	}

	while (mapaPontosNome.size() > 10) {
		mapaPontosNome.erase(mapaPontosNome.begin());
	}

	for (auto it = mapaPontosNome.rbegin(); it != mapaPontosNome.rend(); it++) {
		escreveArquivo << (*it).first << std::endl;
		escreveArquivo << (*it).second << std::endl;
	}

	escreveArquivo.close();

}
