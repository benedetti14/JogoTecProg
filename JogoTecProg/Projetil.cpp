#include "Projetil.h"

#define cProjetil "../JogoTecProg/imagens/inimigos/ninja/Kunai.png"
#define GRAVIDADE 0.7f;
#define VELO_NINJA {100.0f, 100.0f}
#define TAM_PROJETIL {30.0f, 15.0f}
#define DANO_PROJETIL 10

Entidades::Projetil::Projetil(sf::Vector2f posi, const IDs::IDs ID, const bool esquerda):
Entidade(posi, TAM_PROJETIL, ID), animacao(), esquerdaNinja(esquerda), dt(), relogio(), velocidade(VELO_NINJA), 
ativo(false), caindo(false)
{
	animacao.inicializa(posi, TAM_PROJETIL, cProjetil);
}

Entidades::Projetil::~Projetil(){
}

void Entidades::Projetil::atualizar(){
	dt = relogio.getElapsedTime().asSeconds();
	relogio.restart();

	if (ativo) {
		if (esquerdaNinja) {
			posicao.x += -velocidade.x * dt;
		} else {
			posicao.x += velocidade.x * dt;
		}
		/*velocidade.y += dt * GRAVIDADE;
		posicao.y = velocidade.y * GRAVIDADE;*/
	}
	else if (caindo) {
		float g = 2 * GRAVIDADE;
		posicao.y -= (velocidade.y * velocidade.y) / g ;
	}

	setPosicao(posicao);
	
	desenhar();
}

void Entidades::Projetil::move(){
	atualizar();
}

void Entidades::Projetil::colisao(Entidade* outraEntidade, sf::Vector2f ds){
	if (outraEntidade->getID() == IDs::IDs::jogador ) {
		(static_cast<Entidades::Personagens::Jogador*>(outraEntidade))->danoRecebido(DANO_PROJETIL);
		caindo = true;
	}
	else if(outraEntidade->getID() == IDs::IDs::plataforma || outraEntidade->getID() == IDs::IDs::caixa) {
		caindo = false;
	}
	ativo = false;
}

void Entidades::Projetil::desenhar() {
	if (ativo || caindo) {
		animacao.desenhar();
	}
}

void Entidades::Projetil::setPosicao(sf::Vector2f posi){
	animacao.setPosicao(posi);
}

void Entidades::Projetil::ativar(const bool a){
	ativo = a;
}

bool Entidades::Projetil::getAtivo() {
	return ativo;
}
