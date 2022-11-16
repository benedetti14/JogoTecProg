#pragma once
#include<iostream>
#include "Jogador.h"
#include "Inimigo.h"
#include "Plataforma.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "ListaEntidades.h"
#include "Fundo.h"

namespace Fases {
	class Fase : public Ente {
	protected:
		Gerenciadores::GerenciadorColisao* colisor;
		Gerenciadores::GerenciadorEventos* pEventos;
		Entidades::Personagens::Jogador* jogador;
	public:
		Fase();
		virtual ~Fase();
		virtual void inicializa() = 0;
		virtual void executar() = 0;
		virtual void desenhar() = 0;
	};
}