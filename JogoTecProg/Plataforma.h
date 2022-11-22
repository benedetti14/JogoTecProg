#pragma once
#include "Obstaculo.h"
#include "Personagem.h"

#define ESCALA_PLATAFORMA_X 1
#define ESCALA_PLATAFORMA_Y 1

namespace Entidades {
	namespace Obstaculos {
		class Plataforma : public Obstaculo {
		public:
			Plataforma(const sf::Vector2f posi, const sf::Vector2f tam);
			~Plataforma();
			virtual void move();
			void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
		};
	}
}
