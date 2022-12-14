#include "Obstaculo.h"

namespace Entidades {

    Obstaculos::Obstaculo::Obstaculo(const sf::Vector2f posi, const sf::Vector2f tama, const IDs::IDs ID) :
    Entidade(posi, tama, ID), animacao() {
    }

    Obstaculos::Obstaculo::~Obstaculo() {
    }

    void Obstaculos::Obstaculo::atualizar() {
        desenhar();
    }


    void Obstaculos::Obstaculo::reageColisaoPersonagem(sf::Vector2f ds, Personagens::Personagem* pPersonagem) {
        sf::Vector2f posOutro = pPersonagem->getPosicao();
        sf::Vector2f tamOutro = pPersonagem->getTamanho();
        sf::Vector2f velFinal = pPersonagem->getVelocidadeFinal();
        if (ds.x < 0.0f && ds.y < 0.0f) {
            if (ds.x > ds.y) {
                if (posOutro.x < posicao.x) {
                    posOutro.x += ds.x;
                }
                else {
                    posOutro.x -= ds.x;
                }
                velFinal.x = 0.0f;
            }
            else {
                if (posOutro.y < posicao.y) {
                    posOutro.y += ds.y;
                    if (pPersonagem->getID() == IDs::IDs::jogador) {
                        Entidades::Personagens::Jogador* pJogador = static_cast<Entidades::Personagens::Jogador*>(pPersonagem);
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

    void Obstaculos::Obstaculo::desenhar() {
        animacao.desenhar();
    }

    void Obstaculos::Obstaculo::setPosicao(sf::Vector2f posi) {
        posicao = posi;
        animacao.setPosicao(posicao);
    }

    void Obstaculos::Obstaculo::reageColisaoObstaculo(sf::Vector2f ds, Entidades::Obstaculos::Obstaculo* pObstaculo) {
        sf::Vector2f posOutro = pObstaculo->getPosicao();
        sf::Vector2f tamOutro = pObstaculo->getTamanho();

        if (ds.x < 0.0f && ds.y < 0.0f) {
            if (ds.x > ds.y) {
                if (posOutro.x < posicao.x) {
                    posOutro.x += ds.x;
                }
                else {
                    posOutro.x += ds.x;
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

} // namespace Entidades
