#include "Jogador.h"


namespace Entidades {
	namespace Personagens {
		Jogador::Jogador(sf::Vector2f posi, sf::Vector2f velo, sf::Vector2f tam) : Personagem(posi, velo, tam), andar(false), subir(false) {
			corpo.setFillColor(sf::Color::Blue);
		}

		Jogador::~Jogador() {}

		void Jogador::setAndar(bool a){
			podeAndar = true;
			this->andar = a;
		}

		void Jogador::setSubir(bool s) {
			podeAndar = false;
			podeSubir = true;
			this->subir = s;
		}

		void Jogador::move() {
			if (podeAndar) {
				if (andar) {
					corpo.move(velocidade.x, 0.0f);
				}
				else if (!andar) {
					corpo.move(-velocidade.x, 0.0f);
				}
			}
			if (podeSubir) {
				if (subir) {
					corpo.move(0.0f, -velocidade.y);
				} else if (!subir) {
					corpo.move(0.0f, velocidade.y);
				}
			}
		}
	}
}