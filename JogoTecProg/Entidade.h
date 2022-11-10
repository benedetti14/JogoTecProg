#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Ente.h"

namespace Entidades {
	class Entidade: public Ente
	{
	protected:
		sf::RectangleShape corpo;
		sf::Vector2f posicao;
		sf::Vector2f tamanho;
	public:
		Entidade(sf::Vector2f posi, sf::Vector2f tam);
		~Entidade();
		sf::RectangleShape getCorpo();
		void desenhar();
		virtual void atualizar() = 0;
	};
};

