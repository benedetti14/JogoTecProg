#include "Texto.h"

#define TAM_TEXTO 24

Gerenciadores::GerenciadorGrafico* ElementosGraficos::Texto::pGrafico = Gerenciadores::GerenciadorGrafico::getGerenciadorGrafico();

ElementosGraficos::Texto::Texto(std::string info, sf::Vector2f pos, const char* cFonte) : info(info){
	texto.setString(info);
	texto.setFont(pGrafico->setFonte(cFonte));
	texto.setCharacterSize(TAM_TEXTO);
	texto.setOrigin(getTamanho().x / 2, getTamanho().y); // alinhamento no centro 
	//texto.setPosition(sf::Vector2f(pos.x, pos.y));
	texto.setPosition(pos);
	texto.setFillColor(sf::Color::White);

}

ElementosGraficos::Texto::~Texto()
{
}

void ElementosGraficos::Texto::setInfo(std::string info){
	this->info = info;
	texto.setString(info);
}

void ElementosGraficos::Texto::setPosicao(sf::Vector2f pos){
	texto.setPosition(pos);
}

void ElementosGraficos::Texto::setTamanhoFonte(const unsigned int tam) {
	texto.setCharacterSize(tam);
}

std::string ElementosGraficos::Texto::getInfo() const {
	return info;
}

sf::Vector2f ElementosGraficos::Texto::getPosicao() const {
	return sf::Vector2f();
}

sf::Vector2f ElementosGraficos::Texto::getTamanho() const {

	sf::FloatRect tamTexto = texto.getLocalBounds();
	return sf::Vector2f(tamTexto.width, tamTexto.height);
}

void ElementosGraficos::Texto::desenhar(){
	pGrafico->getJanela()->draw(texto);
}

void ElementosGraficos::Texto::setCor(const unsigned int R, const unsigned int G, const unsigned int B){
	texto.setFillColor(sf::Color(R, G, B));
}


