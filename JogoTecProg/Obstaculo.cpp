#include "Obstaculo.h"

Entidades::Obstaculos::Obstaculo::Obstaculo(const sf::Vector2f posi, const sf::Vector2f tama, const IDs::IDs ID) : Entidade(posi, tama, ID)
{
	corpo.setFillColor(sf::Color::Green);
}

Entidades::Obstaculos::Obstaculo::~Obstaculo()
{
}

void Entidades::Obstaculos::Obstaculo::atualizar()
{
	desenhar();
}

void Entidades::Obstaculos::Obstaculo::colisaoObstaculo(sf::Vector2f ds, Personagens::Personagem* pPersonagem) {
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
