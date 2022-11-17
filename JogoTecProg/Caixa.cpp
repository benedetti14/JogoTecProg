#include "Caixa.h"
#define cCaixa "../JogoTecProg/imagens/obstaculos/caixa.png"

Entidades::Obstaculos::Caixa::Caixa(const sf::Vector2f posi, const sf::Vector2f tam): Obstaculo(posi, tam, IDs::IDs::caixa, cCaixa) {
}

Entidades::Obstaculos::Caixa::~Caixa()
{
}


void  Entidades::Obstaculos::Caixa::move(){
    desenhar();
}

void Entidades::Obstaculos::Caixa::colisao(Entidade* outraEntidade, sf::Vector2f ds){
    sf::Vector2f posOutro = outraEntidade->getPosicao();
    sf::Vector2f tamOutro = outraEntidade->getTamanho();

    if (outraEntidade->getID() == IDs::IDs::jogador) {
        colisaoObstaculo(ds, static_cast<Personagens::Personagem*>(outraEntidade));
    }
}
