#pragma once
#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		namespace Inimigos {
			class Cowboy : public Inimigo {
			public:
				Cowboy(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* jogador);
				~Cowboy();
				void inicializa();
			};
		}
	}
}




