#pragma once
#include<iostream>
#include <fstream>
#include "Jogador.h"
#include "Inimigo.h"
#include "Plataforma.h"
#include "Caixa.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "GerenciadorEntrada.h"
#include "ListaEntidades.h"
#include "Fundo.h"
#include "ListaEntidades.h"
#include "MaquinaEstados.h"
#include "Estado.h"
#include "Observer.h"

namespace Fases {
	class Fase : public Ente {
	protected:
		Gerenciadores::GerenciadorColisao* pColisor;
		Gerenciadores::GerenciadorEventos* pEventos;
		Entidades::Personagens::Jogador* jogador;
		Listas::ListaEntidades listaPersonagens;
		Listas::ListaEntidades listaObstaculos;
		Fundo* fundo;
		//bool faseTerminada;
		bool iniciou;
	public:
		Fase(IDs::IDs id);
		virtual ~Fase();
		void criaPlataforma(sf::Vector2f pos, sf::Vector2f tam);
		void criaCaixa(sf::Vector2f pos, sf::Vector2f tam);
		void criaInimigo(sf::Vector2f pos, sf::Vector2f tam);
		virtual void inicializa() = 0;
		virtual void executar() = 0;
		virtual void desenhar() = 0;
		virtual void criarMapa() = 0;
		void criarEntidades(char letra, sf::Vector2f pos);
		//virtual void terminarFase() = 0;
	};
}