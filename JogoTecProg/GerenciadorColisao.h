#pragma once 

#include <SFML\Graphics.hpp>
#include "Inimigo.h"
#include "Jogador.h"
#include "Plataforma.h"
#include <cmath>


namespace Gerenciadores {

    class GerenciadorColisao {
    private:
        Entidades::Personagens::Jogador* jogador;
        Entidades::Personagens::Inimigo* inimigo;
        Entidades::Obstaculos::Plataforma* plataforma;
    public:
		GerenciadorColisao(Entidades::Personagens::Jogador* jog, Entidades::Personagens::Inimigo* ini, Entidades::Obstaculos::Plataforma* plat);
        ~GerenciadorColisao();
        const sf::Vector2f calculaColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2);
        void executar();
    };

}

