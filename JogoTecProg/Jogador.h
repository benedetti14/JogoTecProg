#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Entidade.h"
#include "Personagem.h"

#define VELOCIDADE_JOGADOR 200.0f
#define TAMANHO_PULO 0.18f

namespace Entidades {
	namespace Personagens {
		class Jogador : public Personagem {
		private:
			bool noChao;
			void inicializa();
		public:
			Jogador(sf::Vector2f posi, sf::Vector2f tam);
			~Jogador();
			void move();
			void atualizarAnimacao();
			void pular();
			void podePular();
			void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
		};
	}
};