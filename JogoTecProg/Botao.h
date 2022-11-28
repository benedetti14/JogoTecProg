#pragma once

#include "Animacao.h"

namespace ElementosGraficos {

	class Botao : public Animacao {
	private:
		sf::Texture texturaOriginal;
		sf::Texture texturaSelecionado;
	public:
		Botao(sf::Vector2f pos, const char* original, const char* selecionado);
		~Botao();
		void selecionar(const bool selecionado);
		void desenhar();

	};
}