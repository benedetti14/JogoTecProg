#pragma once

#include "Personagem.h"
#include "Jogador.h"

#include <time.h>

#include <cmath>

#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f


namespace Entidades {

    namespace Personagens {

        class Inimigo : public Personagem {
        protected:
            Jogador* jogador;
            short moveAleatorio;
            float dtAux;
			virtual void inicializa() = 0;
        public:
            Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* jogador, int v, float veloI);
            ~Inimigo();
            virtual void move();
            void atualizaMovimentoAleatorio();
            void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
            void atualizarAnimacao();
        };

    }

}
