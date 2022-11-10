#include "Jogador.h"


namespace Entidades {
	namespace Personagens {
		Jogador::Jogador(sf::Vector2f posi, sf::Vector2f tam) : Personagem(posi, tam, sf::Vector2f(VELOCIDADE_JOGADOR, VELOCIDADE_JOGADOR), IDs::IDs::jogador), noChao(false) {
			inicializa();
		}

		Jogador::~Jogador() {}
		
		void Jogador::inicializa() {
			corpo.setOrigin(sf::Vector2f(tamanho.x / 2.5f, tamanho.y / 2.0f));
			corpo.setFillColor(sf::Color::Blue);
		}

		void Jogador::move() {
			atualizar();
		}

		void Entidades::Personagens::Jogador::pular() {
			if (noChao) {
				float AUX = TAMANHO_PULO * GRAVIDADE;
				velocidade.y = -sqrt(2.0f * AUX);
				noChao = false;
			}
		}

		void Entidades::Personagens::Jogador::podePular() {
			noChao = true;
		}
	}
}