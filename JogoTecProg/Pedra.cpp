#include "Pedra.h"

#define cPedraFloresta "..\JogoTecProg\imagens\obstaculos\pedra1.png"
#define cPedraDeserto "..\JogoTecProg\imagens\obstaculos\pedra2.png"
#define DANO_PEDRA_0 10
#define DANO_PEDRA_1 15

Entidades::Obstaculos::Pedra::Pedra(const sf::Vector2f posi, const sf::Vector2f tam /*, IDs::IDs IdFase*/):
Obstaculo(posi, tam, IDs::IDs::caixa), dureza() {

	srand(time(NULL));
	dureza = rand() % 2;
	animacao.inicializa(posi, tam, cPedraFloresta);

	/* if(IdFase == faseFloresta){
		animacao.inicializa(posi, tam, cPedraFloresta);
	} else {
		animacao.inicializa(posi, tam, cPedraDeserto);
	}*/
}

Entidades::Obstaculos::Pedra::~Pedra()
{
}

void Entidades::Obstaculos::Pedra::move() {
	desenhar();
}

void Entidades::Obstaculos::Pedra::colisao(Entidade* outraEntidade, sf::Vector2f ds) {
	if (outraEntidade->getID() == IDs::IDs::jogador) {
		colisaoObstaculo(ds, static_cast<Personagens::Personagem*>(outraEntidade));

        /*
        if (dureza == 0) {
            (static_cast<Personagens::Jogador*>(outraEntidade))->danoRecebido(DANO_PEDRA_0);
        }
        else {
            (static_cast<Personagens::Jogador*>(outraEntidade))->danoRecebido(DANO_PEDRA_1);
        }
        */
	}
    
}

void Entidades::Obstaculos::Pedra::colisaoObstaculo(sf::Vector2f ds, Entidades::Personagens::Personagem* pPersonagem) {
    sf::Vector2f posOutro = pPersonagem->getPosicao();
    sf::Vector2f tamOutro = pPersonagem->getTamanho();
   
    
    Entidades::Personagens::Jogador* pJogador = static_cast<Entidades::Personagens::Jogador*>(pPersonagem);
    

    if (ds.x < 0.0f && ds.y < 0.0f) {
        if (ds.x > ds.y) {
            if (posOutro.x < posicao.x) {
                posOutro.x += ds.x;
                if (this->dureza == 0) {
                    pJogador->danoRecebido(DANO_PEDRA_0);
                }
                else {
                    pJogador->danoRecebido(DANO_PEDRA_1);
                }
            }
            else {
                posOutro.x -= ds.x;
            }
        }
        else {
            if (posOutro.y < posicao.y) {
                posOutro.y += ds.y;
                if (this->dureza == 0) {
                    pJogador->danoRecebido(DANO_PEDRA_0);
                }
                else {
                    pJogador->danoRecebido(DANO_PEDRA_1);
                }
                pJogador->podePular();
            }
            else {
                posOutro.y -= ds.y;
            }
        }
    }

    pPersonagem->setPosicao(posOutro);
 
}