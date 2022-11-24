#include "Dinossauro.h"


#define VELOCIDADE_DINOSSAURO 60.0f
#define DANO_DINOSSAURO 5
#define VIDA_DINOSSAURO 10
#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f

#define DINOSSAURO_ANDA "../JogoTecProg/imagens/inimigos/dinossauro/Dinossauro_Anda.png"
#define DINOSSAURO_PARADO "../JogoTecProg/imagens/inimigos/dinossauro/Dinossauro_Parado.png"
#define DINOSSAURO_CORRE "../JogoTecProg/imagens/inimigos/dinossauro/Dinossauro_Corre.png"
#define DINOSSAURO_MORRE "../JogoTecProg/imagens/inimigos/dinossauro/Dinossauro_Morre.png"

Entidades::Personagens::Inimigos::Dinossauro::Dinossauro(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* jogador) : Inimigo(pos, tam, jogador, 1, VELOCIDADE_DINOSSAURO) {
	inicializa();
}

void Entidades::Personagens::Inimigos::Dinossauro::inicializa() {
    animacao.incluiAnimacao(ElementosGraficos::anda, DINOSSAURO_ANDA, 10, 0.15f, sf::Vector2f(3, 1.5));
    //animacao.incluiAnimacao(ElementosGraficos::corre, DINOSSAURO_CORRE, 8, 0.15f, sf::Vector2f(6, 3));
    animacao.incluiAnimacao(ElementosGraficos::parado, DINOSSAURO_PARADO, 5, 0.15f, sf::Vector2f(3, 1.5));
    //animacao.incluiAnimacao(ElementosGraficos::morre, DINOSSAURO_MORRE, 5, 0.15f, sf::Vector2f(3, 1.5));
    animacao.setOrigin(sf::Vector2f(tamanho.x / 2.8f, tamanho.y / 3.5f));
    //corpo.setFillColor(sf::Color::Red);
}

Entidades::Personagens::Inimigos::Dinossauro::~Dinossauro() {

}