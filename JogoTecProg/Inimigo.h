#pragma once

#include "Personagem.h"
#include "Jogador.h"

#include <time.h>

#include <cmath>

#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f

#define VELOCIDADE_INIMIGO 60.0f


namespace Entidades {

    namespace Personagens {

        class Inimigo : public Personagem {
        private:
            Jogador* jogador;
            short moveAleatorio;
            float dtAux;
            void inicializa();
        public:
            Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* jogador);
            ~Inimigo();
            void move();
            void atualizaMovimentoAleatorio();
            void colisao(Entidade* outraEntidade, sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
            void atualizarAnimacao();
        };

    }

}
