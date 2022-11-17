#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Ente.h"

namespace Entidades {
	class Entidade : public Ente
	{
	protected:
		sf::RectangleShape corpo;
		sf::Vector2f posicao;
		sf::Vector2f tamanho;
	public:
		Entidade(sf::Vector2f posi, sf::Vector2f tam, const IDs::IDs ID);
		~Entidade();
		sf::RectangleShape getCorpo();
		void setPosicao(sf::Vector2f posi);
		const sf::Vector2f getPosicao();
		const sf::Vector2f getTamanho();
		virtual void atualizar() = 0;
		virtual void move() = 0;
		virtual void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
		void desenhar();
	};
};

