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
				void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
				void atualizarAnimacao();
				void move() override;
			};
		}
	}
}




