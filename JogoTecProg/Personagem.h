#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Entidade.h"
#include "AnimacaoPersonagem.h"


#define GRAVIDADE 0.7f;

namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade
		{
		protected:
			ElementosGraficos::AnimacaoPersonagem animacao;
			sf::Vector2f velocidadeFinal;
			const float velocidadeMaxima;
			bool podeAndar;
			bool esquerda;
			bool atacando;
			sf::Clock relogio;
			sf::Clock relogioAtaque;
			float dt;
			bool recebeuDano;
			int vida;
		public:
			Personagem(sf::Vector2f posi, sf::Vector2f tam, int v, const float velo, const IDs::IDs ID);
			~Personagem();
			sf::Vector2f getVelocidadeFinal();
			const int getVida() const;
			void setVelocidadeFinal(sf::Vector2f veloFinal);
			void andar(const bool esquerda);
			void parar();
			void atacar(const bool atacar);
			const bool estaAtacando();
			void atualizar();
			void danoRecebido(const int dano);
			bool estaVivo();
			virtual void atualizarAnimacao();
			void desenhar();
			void setPosicao(sf::Vector2f posi);
			bool getEsquerda() const;
			virtual void move() = 0;
			virtual void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
			void operator--(const int dano);
		};
	};
}

