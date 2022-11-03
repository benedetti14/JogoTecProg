#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Entidade.h"

namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade
		{
		protected:
			sf::Vector2f velocidade;
		public:
			Personagem(sf::Vector2f posi, sf::Vector2f velo, sf::Vector2f tam);
			~Personagem();
			virtual void move() = 0;
			void atualizar(float t);
		};
	};
}

