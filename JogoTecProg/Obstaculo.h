#pragma once
#include "Entidade.h"
#include "Personagem.h"
#include "Jogador.h"
#include "AnimacaoObstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Obstaculo : public Entidade {
		protected:
			ElementosGraficos::AnimacaoObstaculo animacao;
		public:
			Obstaculo(const sf::Vector2f posi, const sf::Vector2f tama, const IDs::IDs ID);
			~Obstaculo();
			void atualizar();
			void move() = 0;
			virtual void reageColisaoPersonagem(sf::Vector2f ds, Personagens::Personagem* pPersonagem);
			void reageColisaoObstaculo(sf::Vector2f ds, Entidades::Obstaculos::Obstaculo* pObstaculo);
			void desenhar();
			void setPosicao(sf::Vector2f posi);
			virtual void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f)) = 0;
		};
	}
}

