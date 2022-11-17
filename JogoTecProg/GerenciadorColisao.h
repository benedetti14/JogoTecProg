#pragma once 

#include <SFML\Graphics.hpp>
#include "Inimigo.h"
#include "Jogador.h"
#include "Plataforma.h"
#include "Lista.h"
#include "ListaEntidades.h"
#include <cmath>


namespace Gerenciadores {

    class GerenciadorColisao {
    private:
        Listas::ListaEntidades* listaPersonagem;
        Listas::ListaEntidades* listaObstaculo;
    public:
		GerenciadorColisao(Listas::ListaEntidades* listaPersonagem, Listas::ListaEntidades* listaObstaculo);
        ~GerenciadorColisao();
        const sf::Vector2f calculaColisao(Entidades::Entidade* ent1, Entidades::Entidade* ent2);
        void executar();
    };

}

