#include "GerenciadorColisao.h"

Gerenciadores::GerenciadorColisao::GerenciadorColisao(Entidades::Personagens::Jogador* jog, Entidades::Personagens::Inimigo* ini, Entidades::Obstaculos::Plataforma* plat) 
    : jogador(jog), inimigo(ini), plataforma(plat) {
}


Gerenciadores::GerenciadorColisao::~GerenciadorColisao() {

}

const sf::Vector2f Gerenciadores::GerenciadorColisao::calculaColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2) {
    sf::Vector2f pos1 = ent1->getPosicao();
    sf::Vector2f pos2 = ent2->getPosicao();

    sf::Vector2f tam1 = ent1->getTamanho();
    sf::Vector2f tam2 = ent2->getTamanho();

    sf::Vector2f distanciaEntreCentros(
        fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
        fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f))
    );
    sf::Vector2f somaMetadeRectangulo(tam1.x / 2.0f + tam2.x / 2.0f, tam1.y / 2.0f + tam2.y / 2.0f);
    return sf::Vector2f(distanciaEntreCentros.x - somaMetadeRectangulo.x, distanciaEntreCentros.y - somaMetadeRectangulo.y);
}

void Gerenciadores::GerenciadorColisao::executar() {
	
	Entidades::Entidade* pEntidade1 = jogador;
	Entidades::Entidade* pEntidade2 = plataforma;
    sf::Vector2f ds = calculaColisao(pEntidade1, pEntidade2);

    if (ds.x < 0.0f && ds.y < 0.0f) {
		pEntidade2->colisao(pEntidade1, ds);
    }

    pEntidade1 = inimigo;
    pEntidade2 = plataforma;
    ds = calculaColisao(pEntidade1, pEntidade2);

    if (ds.x < 0.0f && ds.y < 0.0f) {
        pEntidade2->colisao(pEntidade1, ds);
    }
}