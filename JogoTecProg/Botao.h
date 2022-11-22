#pragma once

#include "Animacao.h"
#include "Texto.h"

namespace ElementosGraficos {

	class Botao : public Animacao {
	private:
		Texto texto;
		sf::Texture texturaOriginal;
		sf::Texture texturaSelecionado;
	public:
		Botao(sf::Vector2f pos, std::string info);
		~Botao();
		void selecionar(const bool selecionado);
		void desenhar();

	};
}