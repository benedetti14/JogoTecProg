#include "Jogador.h"


namespace Entidades {
	namespace Personagens {
		Jogador::Jogador(sf::Vector2f posi, sf::Vector2f velo, sf::Vector2f tam) : Personagem(posi, velo, tam) {
			corpo.setFillColor(sf::Color::Blue);
		}
		Jogador::~Jogador() {};
		void Jogador::move() {
			corpo.move(velocidade);
		}
	}
}