#pragma once

#include "Animacao.h"

namespace ElementosGraficos {
	class AnimacaoObstaculo : public Animacao {
	private:
		sf::Texture textura;
	public:
		AnimacaoObstaculo();
		~AnimacaoObstaculo();
		void inicializa(sf::Vector2f pos, sf::Vector2f tam, const char* cTextura);
	};
}
