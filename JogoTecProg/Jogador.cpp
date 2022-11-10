#include "Jogador.h"


namespace Entidades {
	namespace Personagens {
		Jogador::Jogador(sf::Vector2f posi, sf::Vector2f tam) : Personagem(posi, tam, VELOCIDADE_JOGADOR, IDs::IDs::jogador), noChao(false) {
			inicializa();
		}

		Jogador::~Jogador() {}
		
		void Jogador::inicializa() {
			corpo.setFillColor(sf::Color::Blue);
		}

		void Jogador::move() {
			atualizar();
		}

		void Entidades::Personagens::Jogador::pular() {
			if (noChao) {
				float AUX = TAMANHO_PULO * GRAVIDADE;
				velocidadeFinal.y = -sqrt(2.0f * AUX);
				noChao = false;
			}
		}

		void Entidades::Personagens::Jogador::podePular() {
			noChao = true;
		}
		
		void Jogador::colisao(Entidade* outraEntidade, sf::Vector2f ds) {
			
		}
	}
}

