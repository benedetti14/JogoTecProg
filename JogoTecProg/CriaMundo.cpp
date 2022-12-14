#include "CriaMundo.h"

#include "Plataforma.h"
#include "Inimigo.h"
#include "Caixa.h"
#include "Dinossauro.h"
#include "Cowboy.h"
#include "Pedra.h"
#include "Ninja.h"

#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <vector>

CriaMundo::CriaMundo(Listas::ListaEntidades* listaPersonagens, Listas::ListaEntidades* listaObstaculos, const unsigned int distanciaRenderizacao)
{
	this->listaPersonagens = listaPersonagens;
	this->listaObstaculos = listaObstaculos;
	this->distanciaRenderizacao = distanciaRenderizacao;

	srand(time(NULL));

	sf::Vector2f tamanhoTela = sf::Vector2f(800, 600);
	limiteTela.y = tamanhoTela.y;

	void voltaPraOrigem();
}

CriaMundo::~CriaMundo()
{
}

void CriaMundo::criar(sf::Vector2f* posicaoVista, Entidades::Personagens::Jogador* jogador, IDs::IDs fase)
{
	*posicaoVista = ultimaPosicaoCriada;


	sequencia = 5;

	ultimaPosicaoCriada.y = -(2.0f + rand() % 2) * 50.0f / 3 + limiteTela.y;

	for (int i = 0; i < distanciaRenderizacao; i++)
	{
		if (sequencia <= 0) {
			sequencia = 2 + rand() % 3;
			ultimaPosicaoCriada.y = -(2.0f + rand() % 2) * 100.0f / 3 + limiteTela.y + 20.0f;
		}

		ultimaPosicaoCriada.x += 100.0f;
		
		sequencia--;

		criaPlataforma(ultimaPosicaoCriada, sf::Vector2f(100.0f, 100.0f), fase);
		
		if (rand() % 3 && sequencia > 1 && sequencia < 4) {
			if (rand() % 2)
				criaCaixa(sf::Vector2f(ultimaPosicaoCriada.x + 25.0f, ultimaPosicaoCriada.y - 25.0f - 25.0f), sf::Vector2f(50.0f, 50.0f));
			else
				criaPedra(sf::Vector2f(ultimaPosicaoCriada.x + 25.0f, ultimaPosicaoCriada.y - 25.0f - 25.0f), sf::Vector2f(50.0f, 50.0f));
		}


		if (rand() % 2) {
			
			if (rand() % 3) {
				criaDino(sf::Vector2f(ultimaPosicaoCriada.x, 300.0f), sf::Vector2f(50.0f, 50.0f), jogador);
			} else {
				if (fase == IDs::IDs::faseFloresta) {
					criaCowboy(sf::Vector2f(ultimaPosicaoCriada.x, 300.0f), sf::Vector2f(50.0f, 50.0f), jogador);
				} 
				else {
					criaNinja(sf::Vector2f(ultimaPosicaoCriada.x, 300.0f), sf::Vector2f(50.0f, 50.0f), jogador, listaObstaculos);
				}
			}
		}
	}

	limpar();
}

void CriaMundo::limpar()
{
	Entidades::Entidade* pEntidade = nullptr;
	
	for (int i = 0; i < listaObstaculos->getTamanho(); i++)
	{
		pEntidade = (*listaObstaculos)[i];
		if (pEntidade) {
			if (pEntidade->getPosicao().x < (ultimaPosicaoCriada.x - 3 * distanciaRenderizacao * 100.0f))
			{
				listaObstaculos->removeEntidade(pEntidade);
				i--;
				if (i < 0) {
					i = -1;
				}
			}
			else {
				break;
			}
		}
	}

	for (int i = 0; i < listaPersonagens->getTamanho(); i++)
	{
		pEntidade = (*listaPersonagens)[i];
		if (pEntidade) {
			if (pEntidade->getPosicao().x < (ultimaPosicaoCriada.x - 3 * distanciaRenderizacao * 100.0f))
			{
				listaPersonagens->removeEntidade(pEntidade);
				i--;
				if (i < 0) {
					i = -1;
				}
			}
			else {
				break;
			}
		}
	}
}

void CriaMundo::setDistanciaRenderizacao()
{
}

void CriaMundo::voltaPraOrigem()
{
	ultimaPosicaoCriada = sf::Vector2f(0, 0);
}

void CriaMundo::criaPlataforma(sf::Vector2f pos, sf::Vector2f tam, IDs::IDs id) {

	Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(pos, tam, id);
	if (plataforma) {
		listaObstaculos->incluiEntidade(static_cast<Entidades::Entidade*>(plataforma));
	}

}

void CriaMundo::criaCaixa(sf::Vector2f pos, sf::Vector2f tam) {
	Entidades::Obstaculos::Caixa* caixa = new Entidades::Obstaculos::Caixa(pos, tam);
	if (caixa) {
		listaObstaculos->incluiEntidade(static_cast<Entidades::Entidade*>(caixa));
	}
}

void CriaMundo::criaPedra(sf::Vector2f pos, sf::Vector2f tam) {
	Entidades::Obstaculos::Pedra* pedra = new Entidades::Obstaculos::Pedra(pos, tam);
	if (pedra) {
		listaObstaculos->incluiEntidade(static_cast<Entidades::Entidade*>(pedra));
	}
}

void CriaMundo::criaDino(sf::Vector2f pos, sf::Vector2f tam, Entidades::Personagens::Jogador* jogador) {

	Entidades::Personagens::Inimigos::Dinossauro* dino = new Entidades::Personagens::Inimigos::Dinossauro(pos, tam, jogador);
	if (dino) {
		listaPersonagens->incluiEntidade(static_cast<Entidades::Entidade*>(dino));
	}

}

void CriaMundo::criaCowboy(sf::Vector2f pos, sf::Vector2f tam, Entidades::Personagens::Jogador* jogador) {

	Entidades::Personagens::Inimigos::Cowboy* cowboy = new Entidades::Personagens::Inimigos::Cowboy(pos, tam, jogador);
	if (cowboy) {
		listaPersonagens->incluiEntidade(static_cast<Entidades::Entidade*>(cowboy));
	}

}

void CriaMundo::criaNinja(sf::Vector2f pos, sf::Vector2f tam, Entidades::Personagens::Jogador* jogador, Listas::ListaEntidades* listaObstaculos) {

	Entidades::Personagens::Inimigos::Ninja* ninja = new Entidades::Personagens::Inimigos::Ninja(pos, tam, jogador, listaObstaculos);
	if (ninja) {
		listaPersonagens->incluiEntidade(static_cast<Entidades::Entidade*>(ninja));
	}

}