#pragma once

#include "Obstaculo.h"
#include "Personagem.h"

namespace Entidades {
	namespace Obstaculos {

		class Caixa : public Obstaculo	{
		private: 
			const float lentidao;
		public:
			Caixa(const sf::Vector2f posi, const sf::Vector2f tam);
			~Caixa();
			virtual void move();
			void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
			void colisaoObstaculo(sf::Vector2f ds, Entidades::Personagens::Personagem* pPersonagem);
		};
	}
}

