#pragma once

//#include <SFML\Graphics.hpp>
//#include <iostream>
#include <map>
#include "Animacao.h"
#include "Imagem.h"

namespace ElementosGraficos {

	enum IdAnimacao {
		vazio = 0,
		anda,
		corre,
		pula,
		parado,
		ataca,
		morre, 
		atira
	};

	class AnimacaoPersonagem: public Animacao {
	private:
		std::map<IdAnimacao, Imagem*> mapaImagem;
		sf::Clock relogio;
		IdAnimacao imgAtual;
	public:
		AnimacaoPersonagem(sf::Vector2f pos, sf::Vector2f tam);
		~AnimacaoPersonagem();
		void atualizar(IdAnimacao imgAtual, const bool esquerda);
		void incluiAnimacao(IdAnimacao id, const char* cTextura, unsigned int qtdImagens, const float tempoTroca, sf::Vector2f escala);
		void setOrigin(sf::Vector2f origem);
	};
}
