#include "Cowboy.h"

#define VELOCIDADE_COWBOY 60.0f
#define DANO_COWBOY 5
#define VIDA_COWBOY 10
#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f

//#define COWBOY_ANDA "../JogoTecProg/imagens/inimigos/cowboy/Cowboy_Anda.png"
#define COWBOY_PARADO "../JogoTecProg/imagens/inimigos/cowboy/Cowboy_Parado.png"
#define COWBOY_CORRE "../JogoTecProg/imagens/inimigos/cowboy/Cowboy_Corre.png"
#define COWBOY_MORRE "../JogoTecProg/imagens/inimigos/cowboy/Cowboy_Morre.png"

Entidades::Personagens::Inimigos::Cowboy::Cowboy(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* jogador) : Inimigo(pos, tam, jogador, 1, VELOCIDADE_COWBOY) {
    inicializa();
}

void Entidades::Personagens::Inimigos::Cowboy::inicializa() {
    animacao.incluiAnimacao(ElementosGraficos::anda, COWBOY_CORRE, 8, 0.15f, sf::Vector2f(3, 1.5));
    //animacao.incluiAnimacao(ElementosGraficos::corre, DINOSSAURO_CORRE, 8, 0.15f, sf::Vector2f(6, 3));
    animacao.incluiAnimacao(ElementosGraficos::parado, COWBOY_PARADO, 5, 0.15f, sf::Vector2f(3, 1.5));
    //animacao.incluiAnimacao(ElementosGraficos::morre, DINOSSAURO_MORRE, 5, 0.15f, sf::Vector2f(3, 1.5));
    animacao.setOrigin(sf::Vector2f(tamanho.x / 2.8f, tamanho.y / 3.5f));
    //corpo.setFillColor(sf::Color::Red);
}

Entidades::Personagens::Inimigos::Cowboy::~Cowboy() {

}