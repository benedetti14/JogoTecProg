#include "FaseFloresta.h"

Fases::FaseFloresta::FaseFloresta() : Fase(IDs::IDs::faseFloresta) {
	
	pGrafico = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();
	//pEventos = Gerenciadores::GerenciadorEventos::getGerenciadorEventos();
	inicializa();
	//pColisor = new Gerenciadores::GerenciadorColisao(listaPersonagens, listaObstaculos);
	
}

Fases::FaseFloresta::~FaseFloresta(){
	
}

void Fases::FaseFloresta::desenhar() {
	fundo->desenhar();
}

void Fases::FaseFloresta::inicializa(){

	//fundo = new Fundo("../JogoTecProg/imagens/fase1/fundo.png", (sf::Vector2f)pGrafico->getJanela()->getSize());
	/*listaPersonagens = new Listas::ListaEntidades();
	listaObstaculos = new Listas::ListaEntidades();*/

	//listaPersonagens->incluiEntidade(jogador);

	//chao
	//criaPlataforma(sf::Vector2f(0.0f, 550.0f), sf::Vector2f(2000.0f, 50.0f)); 
	//
	//for (int i = 0; i < 4; i++) { //cria Inimigos 
	//	criaInimigo({ 300.0f + (i*150), 150.0f}, {50.0f, 90.0f});
	//}
	//
	//criaPlataforma(sf::Vector2f(150.0f, 420.0f), sf::Vector2f(200.0f, 50.0f)); 
	//criaPlataforma(sf::Vector2f(200.0f, 350.0f), sf::Vector2f(200.0f, 50.0f));
	//criaPlataforma(sf::Vector2f(300.0f, 290.0f), sf::Vector2f(200.0f, 50.0f));
	//criaPlataforma(sf::Vector2f(350.0f, 420.0f), sf::Vector2f(200.0f, 50.0f));
	//criaPlataforma(sf::Vector2f(400.0f, 350.0f), sf::Vector2f(200.0f, 50.0f));
	//criaPlataforma(sf::Vector2f(600.0f, 420.0f), sf::Vector2f(200.0f, 50.0f));
	//criaPlataforma(sf::Vector2f(750.0f, 420.0f), sf::Vector2f(200.0f, 50.0f));
	

}

void Fases::FaseFloresta::executar(){
	//jogador->getPosicao().x < pGrafico->getJanela()->getSize().x
	while (jogador->estaVivo()) {
		pEventos->executar();
		pGrafico->limpaJanela();

		desenhar();

		listaPersonagens.executar();
		listaObstaculos.executar();

		pGrafico->mostrar();
		pColisor->executar();
	}
}

void Fases::FaseFloresta::criarMapa() {
	fundo = new Fundo("../JogoTecProg/imagens/fase1/fundo.png", (sf::Vector2f)pGrafico->getJanela()->getSize());

	std::ifstream arquivo;
	std::string linha;
	
	arquivo.open("../JogoTecProg/mapa/faseFloresta/mapa.txt");

	listaPersonagens.incluiEntidade(jogador);

	if (!arquivo.is_open()) {
		std::cout << "nao foi possivel abrir o arquivo" << std::endl;
		exit(1);
	}
	int j = 0;
	while (std::getline(arquivo, linha)) {
		for (int i = 0; i < linha.size(); i++) {
			if (linha[i] != ' ') {
				criarEntidades(linha[i], sf::Vector2f(i, j));
			}
		}
		j++;
	}
	arquivo.close();
}
