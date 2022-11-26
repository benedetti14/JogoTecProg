#pragma once
#include "Entidade.h"
#include "AnimacaoObstaculo.h"
#include "Ninja.h"

namespace Entidades {
	class Projetil : public Entidade {
	private: 
		ElementosGraficos::AnimacaoObstaculo animacao;
		sf::Vector2f velocidade;
		sf::Clock relogio;
		float dt;
		bool ativo;
		bool esquerdaNinja;
		bool caindo;
	public:
		Projetil(sf::Vector2f posi, const IDs::IDs ID, const bool esquerda);
		~Projetil();
		void atualizar();
		void move();
		void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
		void desenhar();
		void setPosicao(sf::Vector2f posi);
		void ativar(const bool a);
	};
	

}