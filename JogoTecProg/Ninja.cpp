#include "Ninja.h"

#define NINJA_CORRE "../JogoTecProg/imagens/inimigos/ninja/Ninja_Corre.png"
#define NINJA_ATACA "../JogoTecProg/imagens/inimigos/ninja/Ninja_Ataca.png"
#define NINJA_ATIRA "../JogoTecProg/imagens/inimigos/ninja/Ninja_Atira.png"
#define NINJA_PARADO "../JogoTecProg/imagens/inimigos/ninja/Ninja_Parado.png"

#define VELO_NINJA 60.0f
#define VIDA_NINJA 20
#define DANO_NINJA_0 15
#define DANO_NINJA_1 25

#define RAIO_ATIRAR_X 300.0f
#define RAIO_ATIRAR_y 300.0f

#define RAIO_ATACAR_X 100.0f
#define RAIO_ATACAR_Y 100.0f


Entidades::Personagens::Inimigos::Ninja::Ninja(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* jogador, Listas::ListaEntidades* listaObstaculos):
	Inimigo(pos, tam, jogador, VIDA_NINJA, VELO_NINJA), faixa(0), atirando(false), atirou(false), listaObstaculos(listaObstaculos)
{
	srand(time(NULL));
	faixa = rand() % 2;

	inicializa();
}

Entidades::Personagens::Inimigos::Ninja::~Ninja()
{
}

void Entidades::Personagens::Inimigos::Ninja::inicializa(){
	animacao.incluiAnimacao(ElementosGraficos::corre, NINJA_CORRE, 10, 0.15f, sf::Vector2f(3, 1.5));
	animacao.incluiAnimacao(ElementosGraficos::ataca, NINJA_ATACA, 10, 0.15f, sf::Vector2f(3, 1.5));
	animacao.incluiAnimacao(ElementosGraficos::atira, NINJA_ATIRA, 10, 0.15f, sf::Vector2f(3, 1.5));
	animacao.incluiAnimacao(ElementosGraficos::parado, NINJA_PARADO, 5, 0.15f, sf::Vector2f(3, 1.5));
	animacao.setOrigin(sf::Vector2f(tamanho.x / 3.0f, tamanho.y / 3.5f));
}

void Entidades::Personagens::Inimigos::Ninja::colisao(Entidade* outraEntidade, sf::Vector2f ds) {
	Personagem* pPersonagem = dynamic_cast<Personagem*>(outraEntidade);
	if (outraEntidade->getID() == IDs::IDs::jogador) {
		if (!pPersonagem->estaAtacando() && atacando) {
			if (faixa == 0) {
				jogador->danoRecebido(DANO_NINJA_0);
			}
			else {
				jogador->danoRecebido(DANO_NINJA_1);
			}	
		}
		
	}
}

void Entidades::Personagens::Inimigos::Ninja::atualizarAnimacao(){
	
	if (atacando) {
		animacao.atualizar(ElementosGraficos::ataca, esquerda);
	} else if (atirando) {
		animacao.atualizar(ElementosGraficos::atira, esquerda);
	} else if (podeAndar) {
		animacao.atualizar(ElementosGraficos::corre, esquerda);
	} else {
		animacao.atualizar(ElementosGraficos::parado, esquerda);
	}
}

void Entidades::Personagens::Inimigos::Ninja::atira(const bool esquerda){
	atirando = true;
	podeAndar = false;
	this->esquerda = esquerda;
	
	float pX = 0.0f, pY = 0.0f;
	if (esquerda) {
		pX = this->getPosicao().x + this->getTamanho().x;
	} else {
		pX = this->getPosicao().x;
	}

	pY = getPosicao().y;

	Entidades::Projetil* projetil = new Entidades::Projetil({pX, pY}, IDs::IDs::projetil, esquerda);
	projetil->ativar(true);
	listaObstaculos->incluiEntidade(static_cast<Entidade*>(projetil));
}

void Entidades::Personagens::Inimigos::Ninja::move(){
	sf::Vector2f posJogador = jogador->getPosicao();
	sf::Vector2f posInimigo = getPosicao();

	
	if (!atirou) {
		if (fabs(posJogador.x - posInimigo.x) <= RAIO_ATIRAR_X) {
			if (posJogador.x - posInimigo.x > 0.0f) {
				atira(false);
			}
			else {
				atira(true);
			}
			atirou = true;
		}
	}
	

	if (fabs(posJogador.x - posInimigo.x) <= RAIO_ATACAR_X && fabs(posJogador.y - posInimigo.y) <= RAIO_ATACAR_Y) {
		if (posJogador.x - posInimigo.x > 0.0f) {
			atacando = true;
		}
	}
	else {
		if (!atirando) {
			if (fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X && fabs(posJogador.y - posInimigo.y) <= RAIO_PERSEGUIR_Y) {
				if (posJogador.x - posInimigo.x > 0.0f) {
					andar(false);
				}
				else {
					andar(true);
				}
			}
			else {
				atualizaMovimentoAleatorio();
			}
		}
		
	}

	atualizar();
	atualizarAnimacao();
	atirando = false;
	dtAux += relogio.getElapsedTime().asSeconds() * 100;
	relogio.restart();
}
