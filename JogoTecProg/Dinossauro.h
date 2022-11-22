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
			};
		}
	}
}


