#pragma once

#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {

		class Caixa : public Obstaculo {
		public:
			Caixa(const sf::Vector2f posi, const sf::Vector2f tam);
			~Caixa();
			void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
		};
	} //namespace obstaculos
} //namespace entidades
