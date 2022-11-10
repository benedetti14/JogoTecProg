#pragma once
#include<iostream>
#include "Jogador.h"
#include "Inimigo.h"
#include "Plataforma.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisao.h"
#include "ListaEntidades.h"

class Jogo
{
private:
	Entidades::Personagens::Jogador jogador;
	Entidades::Personagens::Inimigo inimigo;
	Entidades::Obstaculos::Plataforma plataforma;
	Gerenciadores::GerenciadorGrafico* pGrafico;
	Gerenciadores::GerenciadorEventos* pEventos;
	Gerenciadores::GerenciadorColisao colisor;
	Listas::ListaEntidades personagens;
	
public:
	Jogo();
	~Jogo();
	void executar();
};