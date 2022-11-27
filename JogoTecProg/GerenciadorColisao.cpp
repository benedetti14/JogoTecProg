#include "GerenciadorColisao.h"

Gerenciadores::GerenciadorColisao::GerenciadorColisao(Listas::ListaEntidades* listaPersonagens, Listas::ListaEntidades* listaObstaculos)
	: listaPersonagem(listaPersonagens), listaObstaculo(listaObstaculos)
{
}


Gerenciadores::GerenciadorColisao::~GerenciadorColisao() {
    if (listaPersonagem) {
        delete(listaPersonagem);
    }
    if (listaObstaculo) {
        delete(listaObstaculo);
    }
}

const sf::Vector2f Gerenciadores::GerenciadorColisao::calculaColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2) {
    sf::Vector2f pos1 = ent1->getPosicao();
    sf::Vector2f pos2 = ent2->getPosicao();

    sf::Vector2f tam1 = ent1->getTamanho();
    sf::Vector2f tam2 = ent2->getTamanho();
    
    if (ent1->getID() == IDs::IDs::jogador) {
		tam1.x += 20.0f;
    }

    sf::Vector2f distanciaEntreCentros(
        fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
        fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f))
    );

    sf::Vector2f somaMetadeRectangulo(tam1.x / 2.0f + tam2.x / 2.0f, tam1.y / 2.0f + tam2.y / 2.0f);
    return sf::Vector2f(distanciaEntreCentros.x - somaMetadeRectangulo.x, distanciaEntreCentros.y - somaMetadeRectangulo.y);
}

void Gerenciadores::GerenciadorColisao::colisaoEntrePersonagens() {
    for (int i = 0; i < listaPersonagem->getTamanho() - 1; i++) {
        Entidades::Entidade* ent1 = listaPersonagem->operator[](i);
        for (int j = i + 1; j < listaPersonagem->getTamanho(); j++) {
            Entidades::Entidade* ent2 = listaPersonagem->operator[](j);
            sf::Vector2f ds = calculaColisao(ent1, ent2);
            if (ds.x < 0.0f && ds.y < 0.0f) {
                ent1->colisao(ent2);
                if (ent1->getID() == IDs::IDs::jogador)
                    ent2->colisao(ent1);
            }
        }
    }
}

void Gerenciadores::GerenciadorColisao::colisaoEntrePersonagemObstaculo() {
    for (int i = 0; i < listaPersonagem->getTamanho(); i++) {
        Entidades::Entidade* ent1 = listaPersonagem->operator[](i);
        for (int j = 0; j < listaObstaculo->getTamanho(); j++) {
            Entidades::Entidade* ent2 = listaObstaculo->operator[](j);
            sf::Vector2f ds = calculaColisao(ent1, ent2);
            if (ds.x < 0.0f && ds.y < 0.0f) {
				if (ent2->getID() == IDs::IDs::plataforma || ent2->getID() == IDs::IDs::caixa || ent2->getID() == IDs::IDs::pedra) {
                    ent2->colisao(ent1, ds);
                }
            }
        }
    }
}

void Gerenciadores::GerenciadorColisao::colisaoEntreObstaculos() {
    for (int i = 0; i < listaObstaculo->getTamanho(); i++) {
        Entidades::Entidade* ent1 = listaObstaculo->operator[](i);
        for (int j = i + 1; j < listaObstaculo->getTamanho(); j++) {
            Entidades::Entidade* ent2 = listaObstaculo->operator[](j);
            sf::Vector2f ds = calculaColisao(ent1, ent2);
            if (ds.x < 0.0f && ds.y < 0.0f) {
                ent2->colisao(ent1, ds);
            }
        }
    }
}

void Gerenciadores::GerenciadorColisao::executar() {
    colisaoEntrePersonagens();
    colisaoEntrePersonagemObstaculo();
    colisaoEntreObstaculos();
}