#pragma once
#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		namespace Inimigos {
			class Dinossauro : public Inimigo {
			public:
				Dinossauro(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* jogador);
				~Dinossauro();
				void inicializa();
				void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
			};
		}
	}
}


