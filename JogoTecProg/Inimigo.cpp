#include "Inimigo.h"

Entidades::Personagens::Inimigo::Inimigo::Inimigo(const sf::Vector2f posi, const sf::Vector2f tam, Jogador* jogador) : Personagem(posi, tam, sf::Vector2f(VELOCIDADE_INIMIGO, VELOCIDADE_INIMIGO),IDs::IDs::inimigo), jogador(jogador), dtAux(0.0f) {
	inicializa();

    srand(time(NULL));
	
    moveAleatorio = rand() % 3;
	
    if (moveAleatorio == 0) {
        parar();
    }
    else if (moveAleatorio == 1) {
        andar(true);
    }
    else {
        andar(false);
    }
}

void Entidades::Personagens::Inimigo::inicializa() {
    corpo.setOrigin(sf::Vector2f(tamanho.x / 12.0f, tamanho.y / 8.5f));
	corpo.setFillColor(sf::Color::Red);
}

Entidades::Personagens::Inimigo::Inimigo::~Inimigo() {}

void Entidades::Personagens::Inimigo::atualizaMovimentoAleatorio() {
    if (dtAux > 1.0f) {
        moveAleatorio = rand() % 3;
        if (moveAleatorio == 0) {
            parar();
        }
        else if (moveAleatorio == 1) {
            andar(true);
        }
        else {
            andar(false);
        }
        dtAux = 0.0f;
    }
}

void Entidades::Personagens::Inimigo::move() {
    sf::Vector2f posJogador = jogador->getPosicao();
    sf::Vector2f posInimigo = getPosicao();
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
    atualizar();
    dtAux += relogio.getElapsedTime().asSeconds() * 100;
    relogio.restart();
}