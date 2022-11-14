#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include <map>
#include "Imagem.h"

namespace ElementosGraficos {

	enum IdAnimacao {
		vazio = 0,
		anda,
		corre,
		pula,
		parado,
		ataca,
		morre
	};

	class Animacao {
	private:
		sf::RectangleShape* corpo;
		std::map<IdAnimacao, Imagem*> mapaImagem;
		sf::Clock relogio;
		IdAnimacao imgAtual;
	public:
		Animacao(sf::RectangleShape* corpo);
		~Animacao();
		void atualizar(IdAnimacao imgAtual, const bool esquerda);
		void incluiAnimacao(IdAnimacao id, const char* cTextura, unsigned int qtdImagens, const float tempoTroca, sf::Vector2f escala);

	};
}
