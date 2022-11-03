#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>

namespace Entidades {
	class Entidade
	{
	protected:
		sf::RectangleShape corpo;
		sf::Vector2f posicao;
		sf::Vector2f tamanho;
	public:
		Entidade(sf::Vector2f posi, sf::Vector2f tam);
		~Entidade();
		sf::RectangleShape getCorpo();
		virtual void atualizar() = 0;
	};
};

