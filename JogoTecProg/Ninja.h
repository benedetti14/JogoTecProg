#pragma once
#include "Inimigo.h"
#include "Projetil.h"
#include "ListaEntidades.h"
#include "Entidade.h"


namespace Entidades {
	class Projetil;
	namespace Personagens {
		namespace Inimigos {
			class Ninja : public Inimigo {
			private:
				int faixa;
				bool atirando;
				bool atirou;
				Listas::ListaEntidades* listaObstaculos;
				void inicializa();
			public:
				Ninja(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* jogador, Listas::ListaEntidades* listaObstaculos);
				~Ninja();
				void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
				void atualizarAnimacao();
				void atira(const bool esquerda);
				void move() override;
			};
		}
	}
}


