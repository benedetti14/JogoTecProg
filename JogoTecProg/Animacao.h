#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include "GerenciadorGrafico.h"

namespace ElementosGraficos {

	class Animacao {
	protected:
		sf::RectangleShape* corpo;
		static Gerenciadores::GerenciadorGrafico* pGrafico;
	public:
		Animacao(sf::RectangleShape* corpo);
		virtual ~Animacao();

	};
}
