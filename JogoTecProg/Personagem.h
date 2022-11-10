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
			sf::Vector2f velocidade;
			bool podeAndar;
			bool esquerda;
			bool cima;
			sf::Clock relogio;
			float dt;
		public:
			Personagem(sf::Vector2f posi, sf::Vector2f tam, sf::Vector2f velo, const IDs::IDs ID);
			~Personagem();
			sf::Vector2f getVelocidade();
			void setVelocidade(sf::Vector2f velo);
			void andar(const bool esquerda);
			void parar();
			void atualizar();
			virtual void move() = 0;
		};
	};
}

