#include "Pedra.h"

#define cPedraFloresta "../JogoTecProg/imagens/obstaculos/pedra1.png"
#define cPedraDeserto "../JogoTecProg/imagens/obstaculos/pedra2.png"
#define DANO_PEDRA_0 10
#define DANO_PEDRA_1 15

Entidades::Obstaculos::Pedra::Pedra(const sf::Vector2f posi, const sf::Vector2f tam /*, IDs::IDs IdFase*/):
Obstaculo(posi, tam, IDs::IDs::pedra), dureza() {

	srand(time(NULL));
	dureza = rand() % 2;
	animacao.inicializa(posi, tam, cPedraFloresta);
}

Entidades::Obstaculos::Pedra::~Pedra()
{
}

void Entidades::Obstaculos::Pedra::move() {
	desenhar();
}

void Entidades::Obstaculos::Pedra::colisao(Entidade* outraEntidade, sf::Vector2f ds) {
	if (outraEntidade->getID() == IDs::IDs::jogador || outraEntidade->getID() == IDs::IDs::inimigo) {
        reageColisaoPersonagem(ds, static_cast<Personagens::Personagem*>(outraEntidade));
    }
    else {
        reageColisaoObstaculo(ds, static_cast<Obstaculos::Obstaculo*>(outraEntidade));
    }
        
}

void Entidades::Obstaculos::Pedra::reageColisaoPersonagem(sf::Vector2f ds, Entidades::Personagens::Personagem* pPersonagem) {
    sf::Vector2f posOutro = pPersonagem->getPosicao();
    sf::Vector2f tamOutro = pPersonagem->getTamanho();
    

    if (ds.x < 0.0f && ds.y < 0.0f) {
        if (ds.x > ds.y) {
            if (pPersonagem->getID() == IDs::IDs::jogador) {
                if (posOutro.x < posicao.x) {
                    posOutro.x += ds.x;
                    if (pPersonagem->getID() == IDs::IDs::jogador) {
                        if (this->dureza == 0) {
                                pPersonagem->danoRecebido(DANO_PEDRA_0);
                        }
                        else {
                            pPersonagem->danoRecebido(DANO_PEDRA_1);
                        }
                        if (pPersonagem->getEsquerda()) {
                            posOutro.x += 100.0f;
                        }
                        else {
                            posOutro.x -= 100.0f;
                        }
                    }
                }
                else {
                    posOutro.x -= ds.x;
                    if (pPersonagem->getID() == IDs::IDs::jogador) {
                        if (this->dureza == 0) {
                                pPersonagem->danoRecebido(DANO_PEDRA_0);
                        }
                        else {
                            pPersonagem->danoRecebido(DANO_PEDRA_1);
                        }
                        if (pPersonagem->getEsquerda()) {
                            posOutro.x += 100.0f;
                        }
                        else {
                            posOutro.x -= 100.0f;
                        }
                    }
                }
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

                    if (this->dureza == 0) {
                        pPersonagem->danoRecebido(DANO_PEDRA_0);
                    }
                    else {
                        pPersonagem->danoRecebido(DANO_PEDRA_1);
                    }
                    if (pPersonagem->getEsquerda()) {
                        posOutro.x -= 100.0f;
                    }
                    else {
                        posOutro.x += 100.0f;
                    }
                    Personagens::Jogador* pJogador = static_cast<Personagens::Jogador*>(pPersonagem);
                    pJogador->podePular();
                }
            }
            else {
                posOutro.y -= ds.y;
                if (pPersonagem->getID() == IDs::IDs::jogador) {

                    if (this->dureza == 0) {
                        pPersonagem->danoRecebido(DANO_PEDRA_0);
                    }
                    else {
                        pPersonagem->danoRecebido(DANO_PEDRA_1);
                    }
                    if (pPersonagem->getEsquerda()) {
                        posOutro.x -= 100.0f;
                    }
                    else {
                        posOutro.x += 100.0f;
                    }
                    Personagens::Jogador* pJogador = static_cast<Personagens::Jogador*>(pPersonagem);
                    pJogador->podePular();
                }
            }
        }
    }

    pPersonagem->setPosicao(posOutro);
}

void Entidades::Obstaculos::Pedra::reageColisaoObstaculo(sf::Vector2f ds, Entidades::Obstaculos::Obstaculo* pObstaculo) {
    sf::Vector2f posOutro = pObstaculo->getPosicao();
    sf::Vector2f tamOutro = pObstaculo->getTamanho();

    if (ds.x < 0.0f && ds.y < 0.0f) {
        if (ds.x > ds.y) {
            if (posOutro.x < posicao.x) {
                posOutro.x += ds.x;
            }
            else {
                posOutro.x -= ds.x;
            }
        }
        else {
            if (posOutro.y < posicao.y) {
                posOutro.y += ds.y;
            }
            else {
                posOutro.y -= ds.y;
            }
        }
    }
    pObstaculo->setPosicao(posOutro);
}