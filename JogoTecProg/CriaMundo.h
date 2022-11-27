#pragma once
#include <SFML\Graphics.hpp>
#include "ListaEntidades.h"
#include "Jogador.h"

class CriaMundo
{
private:
	sf::Vector3f posicaoVista;
	Listas::ListaEntidades* listaPersonagens;
	Listas::ListaEntidades* listaObstaculos;
	unsigned int distanciaRenderizacao;
	sf::Vector2f ultimaPosicaoCriada;
	sf::Vector2f limiteTela;
	int sequencia;
public: 
	CriaMundo(Listas::ListaEntidades* listaPersonagens, Listas::ListaEntidades* listaObstaculos, const unsigned int distanciaRenderizacao = 20);
	~CriaMundo();
	void criar(sf::Vector2f* posicaoVista, Entidades::Personagens::Jogador* jogador, IDs::IDs fase);
	void limpar();
	void setDistanciaRenderizacao();
	void voltaPraOrigem();
	void criaPlataforma(sf::Vector2f pos, sf::Vector2f tam, IDs::IDs fase);
	void criaCowboy(sf::Vector2f pos, sf::Vector2f tam, Entidades::Personagens::Jogador* jogador);
	void criaNinja(sf::Vector2f pos, sf::Vector2f tam, Entidades::Personagens::Jogador* jogador);
	void criaDino(sf::Vector2f pos, sf::Vector2f tam, Entidades::Personagens::Jogador* jogador);
	void criaCaixa(sf::Vector2f pos, sf::Vector2f tam);
	void criaPedra(sf::Vector2f pos, sf::Vector2f tam);
};

