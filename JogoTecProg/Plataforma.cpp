#include "Plataforma.h"

#define cPlataforma "../JogoTecProg/imagens/fase1/plataforma.png"
#define cPlataformaFloresta "..\JogoTecProg\imagens\obstaculos\plataforma1.png"
#define cPlataformaDeserto "..\JogoTecProg\imagens\obstaculos\plataforma2.png"

Entidades::Obstaculos::Plataforma::Plataforma(const sf::Vector2f posi, const sf::Vector2f tam /*, IDs::IDs IdFase*/) : Obstaculo(posi, tam, IDs::IDs::plataforma)
{
    animacao.inicializa(posi, tam, cPlataforma);

    /*
    if (IdFase == IDs::IDs::faseFloresta) {
        animacao.inicializa(posi, tam, cPedraFloresta);
    }
    else (IdFase == IDs::IDs::faseDeserto) {
        animacao.inicializa(posi, tam, cPedraDeserto);
    }*/

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