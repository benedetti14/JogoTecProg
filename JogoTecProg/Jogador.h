#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Entidade.h"
#include "Personagem.h"
#include  "ControleJogador.h"


namespace Controle {
	class ControleJogador;
}

namespace Entidades {
	namespace Personagens {
		class Jogador : public Personagem {
		private:
			Controle::ControleJogador* pControle;
			bool noChao;
			void inicializa();
			int pontos;
		public:
			Jogador(sf::Vector2f posi, sf::Vector2f tam);
			~Jogador();
			void move();
			void atualizarAnimacao();
			void pular();
			void podePular();
			void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
			void empoderar();
			int getPontos() const;
		};
	}
};