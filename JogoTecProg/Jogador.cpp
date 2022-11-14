#include "Jogador.h"
#define JOGADOR_ANDA "../imagens/jogador/Jogador_Anda.png"
#define JOGADOR_CORRE "../imagens/jogador/Jogador_Corre.png"
#define JOGADOR_PULA "../imagens/jogador/Jogador_Pula.png"
#define JOGADOR_ATACA "../imagens/jogador/Jogador_Ataca.png"
#define JOGADOR_MORRE "../imagens/jogador/Jogador_Morre.png"
#define JOGADOR_PARADO "../imagens/jogador/Jogador_Parado.png"

namespace Entidades {
	namespace Personagens {

		Jogador::Jogador(sf::Vector2f posi, sf::Vector2f tam) : Personagem(posi, tam, VELOCIDADE_JOGADOR, IDs::IDs::jogador), noChao(false) {
			inicializa();
		}

		Jogador::~Jogador() {}
		
		void Jogador::inicializa() {
			animacao.incluiAnimacao(ElementosGraficos::anda, JOGADOR_ANDA, 10, 0.15f, sf::Vector2f(6, 3));
			animacao.incluiAnimacao(ElementosGraficos::corre, JOGADOR_CORRE, 10, 0.15f, sf::Vector2f(6, 3));
			animacao.incluiAnimacao(ElementosGraficos::pula, JOGADOR_PULA, 10, 0.15f, sf::Vector2f(6, 3));
			animacao.incluiAnimacao(ElementosGraficos::ataca, JOGADOR_ATACA, 10, 0.15f, sf::Vector2f(6, 3));
			animacao.incluiAnimacao(ElementosGraficos::morre, JOGADOR_MORRE, 10, 0.15f, sf::Vector2f(6, 3));
			animacao.incluiAnimacao(ElementosGraficos::parado, JOGADOR_PARADO, 5, 0.15f, sf::Vector2f(6, 3));
			corpo.setOrigin(sf::Vector2f(tamanho.x / 2.5f, tamanho.y / 2.0f));
		}

		void Jogador::move() {
			atualizar();
			atualizarAnimacao();
			pGrafico->atualizaCamera(posicao);
		}

		void Jogador::atualizarAnimacao() {
			if (atacando) {
				animacao.atualizar(ElementosGraficos::ataca, esquerda);
			} else if (!noChao) {
				animacao.atualizar(ElementosGraficos::pula, esquerda);
			} else if (podeAndar) {
				animacao.atualizar(ElementosGraficos::anda, esquerda);
			} else {
				animacao.atualizar(ElementosGraficos::parado, esquerda);
			}
		}

		void Jogador::pular() {
			if (noChao) {
				float AUX = TAMANHO_PULO * GRAVIDADE;
				velocidadeFinal.y = -sqrt(2.0f * AUX);
				noChao = false;
			}
		}

		void Jogador::podePular() {
			noChao = true;
		}
		
		void Jogador::colisao(Entidade* outraEntidade, sf::Vector2f ds) {
			
		}

	}//namespace Personagens
}//namespace Entidades

