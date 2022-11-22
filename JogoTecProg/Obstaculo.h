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
			virtual void colisaoObstaculo(sf::Vector2f ds, Personagens::Personagem* pPersonagem);
			void desenhar();
			void setPosicao(sf::Vector2f posi);
		};
	}
}

