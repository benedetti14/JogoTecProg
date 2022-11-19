#pragma once
#include "GerenciadorGrafico.h"

namespace ElementosGraficos {

	class Imagem {
	private:
		sf::Texture textura;
		sf::IntRect tamanho;
		const sf::Vector2f escala;
		float tempoTotal;
		const float tempoTroca;
		const unsigned int qtdImagens;
		unsigned int imagemAtual;
		//Gerenciadores::GerenciadorGrafico* pGrafico;
	public:
		Imagem(const char* cTextura, const unsigned int qtdImg, const float tTroca, sf::Vector2f escala);
		~Imagem();
		void atualizar(const float dT, const bool esquerda);
		void reseta();
		const sf::IntRect getTamanho() const;
		const sf::Vector2f getEscala() const;
		const sf::Texture* getTexture() const;

	};
}// namespace ElementosGraficos