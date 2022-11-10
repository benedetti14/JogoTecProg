#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Entidade.h"

#define GRAVIDADE 0.7f;

namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade
		{
		protected:
			sf::Vector2f velocidadeFinal;
			const float velocidadeMaxima;
			bool podeAndar;
			bool esquerda;
			sf::Clock relogio;
			float dt;
		public:
			Personagem(sf::Vector2f posi, sf::Vector2f tam, const float velo, const IDs::IDs ID);
			~Personagem();
			sf::Vector2f getVelocidadeFinal();
			void setVelocidadeFinal(sf::Vector2f veloFinal);
			void andar(const bool esquerda);
			void parar();
			void atualizar();
			virtual void move() = 0;
			virtual void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
		};
	};
}

