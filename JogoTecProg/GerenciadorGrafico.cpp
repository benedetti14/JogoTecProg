#include "GerenciadorGrafico.h"
#include <iostream>

#define TELA_X 800.0f
#define TELA_Y 600.0f

Gerenciadores::GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::pGrafico = nullptr;

Gerenciadores::GerenciadorGrafico::GerenciadorGrafico() : 
janela(new sf::RenderWindow(sf::VideoMode(TELA_X, TELA_Y), "Jogo")),
camera(sf::Vector2f(TELA_X/2.0f, TELA_Y/2.0f), sf::Vector2f(TELA_X,TELA_Y)) {

	if (janela == nullptr) {
		std::cout << "Erro na criação da janela!";
		exit(1);
	}
}

Gerenciadores::GerenciadorGrafico::~GerenciadorGrafico() {
	if (janela) {
		delete (janela);
		janela = nullptr;
	}
}

Gerenciadores::GerenciadorGrafico* Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico() {
	if (pGrafico == nullptr) {
		pGrafico = new GerenciadorGrafico();
	}
	return pGrafico;
}				

sf::RenderWindow* Gerenciadores::GerenciadorGrafico::getJanela() {
	if (janela == nullptr) {
		std::cout << "Erro na criação da janela!";
		exit(1);
	}
	return janela;
}

const bool Gerenciadores::GerenciadorGrafico::janelaAberta() {
	if (janela->isOpen()) {
		return true;
	}
	return false;
}

void Gerenciadores::GerenciadorGrafico::fechaJanela() {
	janela->close();
}

void Gerenciadores::GerenciadorGrafico::limpaJanela() {
	janela->clear();
}

void Gerenciadores::GerenciadorGrafico::mostrar() {
	janela->display();
}

sf::Vector2f Gerenciadores::GerenciadorGrafico::fimJanela() {
	return static_cast<sf::Vector2f>(janela->getSize());
}

sf::Texture Gerenciadores::GerenciadorGrafico::setTextura(const char* cTextura){
	sf::Texture textura;
	
	if (!textura.loadFromFile(cTextura)){
		std::cout << "Gerenciador Grafico:: erro ao carregar textura " << cTextura << std::endl;
		exit(1);
	}

	return textura;
}

const sf::View Gerenciadores::GerenciadorGrafico::getCamera()
{
	return camera;
}

void Gerenciadores::GerenciadorGrafico::atualizaCamera(sf::Vector2f posJogador){
	camera.setCenter(posJogador.x, 300.0f);
	janela->setView(camera);
}

