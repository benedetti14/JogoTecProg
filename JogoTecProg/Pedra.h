#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Pedra: public Obstaculo {
		private:
			int dureza;
		public:
			Pedra(const sf::Vector2f posi, const sf::Vector2f tam);
			~Pedra();
			virtual void move();
			void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
			void reageColisaoPersonagem(sf::Vector2f ds, Entidades::Personagens::Personagem* pPersonagem);
			void reageColisaoObstaculo(sf::Vector2f ds, Entidades::Obstaculos::Obstaculo* pObstaculo);
		};
	}
}


