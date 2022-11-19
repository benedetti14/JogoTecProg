#include "Imagem.h"
#include <iostream>

using namespace Gerenciadores;

ElementosGraficos::Imagem::Imagem(const char* cTextura, const unsigned int qtdImg, const float tTroca, sf::Vector2f escala) :
	textura(GerenciadorGrafico::getGerenciadorGrafico()->setTextura(cTextura)), qtdImagens(qtdImg),
	tempoTroca(tTroca), escala(escala), tempoTotal(0.0f), imagemAtual(0), tamanho(0,0,0,0)
{
	tamanho.width = textura.getSize().x / (float) qtdImagens;
	tamanho.height = textura.getSize().y;

}

ElementosGraficos::Imagem::~Imagem(){
}

void ElementosGraficos::Imagem::atualizar(const float dT, const bool esquerda){
	tempoTotal += dT;

	if (tempoTotal >= tempoTroca) {
		tempoTotal -= tempoTroca;
		imagemAtual++;

		if (imagemAtual >= qtdImagens) {
			imagemAtual = 0;
		}
	}

	if (esquerda) {
		tamanho.left = (imagemAtual + 1) * abs(tamanho.width);
		tamanho.width = -abs(tamanho.width);
	} else {
		tamanho.left = imagemAtual * tamanho.width;
		tamanho.width = abs(tamanho.width);
	}

}

void ElementosGraficos::Imagem::reseta(){
	imagemAtual = 0;
	tempoTotal = 0.0f;
}

const sf::IntRect ElementosGraficos::Imagem::getTamanho() const { 
	return tamanho;
}

const sf::Vector2f ElementosGraficos::Imagem::getEscala() const {
	return escala;
}

const sf::Texture* ElementosGraficos::Imagem::getTexture() const {
	return &textura;
}
