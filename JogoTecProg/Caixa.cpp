#include "Caixa.h"
#define cCaixa "../JogoTecProg/imagens/obstaculos/caixa.png"

Entidades::Obstaculos::Caixa::Caixa(const sf::Vector2f posi, const sf::Vector2f tam) : Obstaculo(posi, tam, IDs::IDs::caixa), lentidao(0.25f) {
    animacao.inicializa(posi, tam, cCaixa);
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

	if (outraEntidade->getID() == IDs::IDs::jogador || outraEntidade->getID() == IDs::IDs::inimigo) {
        colisaoObstaculo(ds, static_cast<Personagens::Personagem*>(outraEntidade));
    }
}

void Entidades::Obstaculos::Caixa::colisaoObstaculo(sf::Vector2f ds, Entidades::Personagens::Personagem* pPersonagem) {
    sf::Vector2f posOutro = pPersonagem->getPosicao();
    sf::Vector2f tamOutro = pPersonagem->getTamanho();
    sf::Vector2f velFinal = pPersonagem->getVelocidadeFinal();
    if (ds.x < 0.0f && ds.y < 0.0f) {
        if (ds.x > ds.y) {
            if (pPersonagem->getID() == IDs::IDs::jogador) {
                velFinal.x *= lentidao;
                if (posOutro.x < posicao.x) { 
                    posicao.x -= ds.x;
                }
                else {
                    posicao.x += ds.x;
                }
                setPosicao(posicao);
            }
            else {
                if (posOutro.x < posicao.x) { 
                    posOutro.x += ds.x;
                }
                else {
                    posOutro.x -= ds.x;
                }
            }
        }
        else {
            if (posOutro.y < posicao.y) {
                posOutro.y += ds.y;
                if (pPersonagem->getID() == IDs::IDs::jogador) {
                    Personagens::Jogador* pJogador = static_cast<Personagens::Jogador*>(pPersonagem);
                    pJogador->podePular();
                }
            }
            else {
                posOutro.y -= ds.y;
            }
            velFinal.y = 0.0f;
        }
    }
    pPersonagem->setPosicao(posOutro);
    pPersonagem->setVelocidadeFinal(velFinal);
}
