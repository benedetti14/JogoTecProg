#pragma once
#include<iostream>
#include <fstream>
#include "Jogador.h"
#include "Inimigo.h"
#include "Dinossauro.h"
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
		//Gerenciadores::GerenciadorEventos* pEventos;
		Entidades::Personagens::Jogador* jogador;
		Listas::ListaEntidades listaPersonagens;
		Listas::ListaEntidades listaObstaculos;
		Fundo* fundo;
		bool faseTerminada;
		bool iniciou;
		int pontosJogador;
		sf::Vector2f proximaPosicao;
	public:
		Fase(IDs::IDs id);
		virtual ~Fase();
		virtual void inicializa() = 0;
		virtual void executar() = 0;
		virtual void desenhar() = 0;
		void terminarFase();
		int getPontosJogador()  const;
		virtual Estados::IdEstado getIDfase() const = 0;
	};
}