#pragma once
#include "Entidade.h"
#include "Personagem.h"
#include "Entidade.h"
#include "Jogador.h"

namespace Entidades {
	namespace Obstaculos {
		class Obstaculo : public Entidade
		{
		protected:
			sf::Texture textura;
		public:
			Obstaculo(const sf::Vector2f posi, const sf::Vector2f tama, const IDs::IDs ID, const char* cTextura);
			~Obstaculo();
			void atualizar();
			virtual void colisaoObstaculo(sf::Vector2f ds, Personagens::Personagem* pPersonagem);
		};
	}
}

