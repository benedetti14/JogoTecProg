#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include "GerenciadorGrafico.h"

namespace ElementosGraficos {

	class Animacao {
	protected:
		sf::RectangleShape corpo;
		static Gerenciadores::GerenciadorGrafico* pGrafico;
	public:
		Animacao();
		virtual ~Animacao();
		void desenhar();
		void setPosicao(sf::Vector2f pos);
	};
}
