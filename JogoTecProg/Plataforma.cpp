#include "Plataforma.h"
#define cPlataforma "../JogoTecProg/imagens/fase1/plataforma.png"

Entidades::Obstaculos::Plataforma::Plataforma(const sf::Vector2f posi, const sf::Vector2f tam) : Obstaculo(posi, tam, IDs::IDs::plataforma)
{
    animacao.inicializa(posi, tam, cPlataforma);

}

Entidades::Obstaculos::Plataforma::~Plataforma()
{
}


void  Entidades::Obstaculos::Plataforma::move()
{
    desenhar();
}

void Entidades::Obstaculos::Plataforma::colisao(Entidade* outraEntidade, sf::Vector2f ds) {
    sf::Vector2f posOutro = outraEntidade->getPosicao();
    sf::Vector2f tamOutro = outraEntidade->getTamanho();

    if (outraEntidade->getID() == IDs::IDs::jogador || outraEntidade->getID() == IDs::IDs::inimigo) {
        colisaoObstaculo(ds, static_cast<Personagens::Personagem*>(outraEntidade));
    }
}