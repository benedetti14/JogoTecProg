#include "Cowboy.h"

#define VELOCIDADE_COWBOY 60.0f
#define DANO_COWBOY 5
#define VIDA_COWBOY 20
#define RAIO_PERSEGUIR_X 400.0f
#define RAIO_PERSEGUIR_Y 400.0f

#define RAIO_ATACAR_X 100.0f
#define RAIO_ATACAR_Y 100.0f

#define COWBOY_ATACA "../JogoTecProg/imagens/inimigos/cowboy/Cowboy_Ataca.png"
#define COWBOY_PARADO "../JogoTecProg/imagens/inimigos/cowboy/Cowboy_Parado.png"
#define COWBOY_CORRE "../JogoTecProg/imagens/inimigos/cowboy/Cowboy_Corre.png"
#define COWBOY_MORRE "../JogoTecProg/imagens/inimigos/cowboy/Cowboy_Morre.png"

Entidades::Personagens::Inimigos::Cowboy::Cowboy(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* jogador) : Inimigo(pos, tam, jogador, VIDA_COWBOY, VELOCIDADE_COWBOY) {
    inicializa();
}

Entidades::Personagens::Inimigos::Cowboy::~Cowboy() {

}
void Entidades::Personagens::Inimigos::Cowboy::inicializa() {
    animacao.incluiAnimacao(ElementosGraficos::corre, COWBOY_CORRE, 8, 0.15f, sf::Vector2f(3, 1.5));
    animacao.incluiAnimacao(ElementosGraficos::parado, COWBOY_PARADO, 5, 0.15f, sf::Vector2f(3, 1.5));
    animacao.incluiAnimacao(ElementosGraficos::ataca, COWBOY_ATACA, 7, 0.15f, sf::Vector2f(3, 1.5));
    animacao.setOrigin(sf::Vector2f(tamanho.x / 2.8f, tamanho.y / 3.5f));
}

void Entidades::Personagens::Inimigos::Cowboy::colisao(Entidade* outraEntidade, sf::Vector2f ds) {
    Personagem* pPersonagem = dynamic_cast<Personagem*>(outraEntidade);
    if (pPersonagem->getID() == IDs::IDs::jogador) {
        if (pPersonagem != nullptr) {
			if (!pPersonagem->estaAtacando() && atacando) {
                pPersonagem->danoRecebido(DANO_COWBOY);
            }
        }
    }
}

void Entidades::Personagens::Inimigos::Cowboy::atualizarAnimacao() {

	if (atacando) {
		animacao.atualizar(ElementosGraficos::ataca, esquerda);
	}
	else if (podeAndar) {
		animacao.atualizar(ElementosGraficos::corre, esquerda);
	}
	else {
		animacao.atualizar(ElementosGraficos::parado, esquerda);
	}
}

void Entidades::Personagens::Inimigos::Cowboy::move() {
	sf::Vector2f posJogador = jogador->getPosicao();
	sf::Vector2f posInimigo = getPosicao();

    if (fabs(posJogador.x - posInimigo.x) <= RAIO_ATACAR_X && fabs(posJogador.y - posInimigo.y) <= RAIO_ATACAR_Y) {
        if (posJogador.x - posInimigo.x > 0.0f) {
            atacando = true;
        }
    }
    else {
		if (fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X && fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUIR_Y) {
			if (posJogador.x - posInimigo.x > 0.0f) {
				andar(false);
			}
			else {
				andar(true);
			}
		}
		else {
			atualizaMovimentoAleatorio();
		}
    }

	atualizar();
	atualizarAnimacao();
	dtAux += relogio.getElapsedTime().asSeconds() * 100;
	relogio.restart();
}