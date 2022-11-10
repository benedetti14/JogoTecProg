#pragma once
#include<iostream>
#include "Jogador.h"
#include "Inimigo.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "ListaEntidades.h"

class Jogo
{
private:
	Entidades::Personagens::Jogador jogador;
	Entidades::Personagens::Inimigo inimigo;
	Gerenciadores::GerenciadorGrafico* pGrafico;
	Gerenciadores::GerenciadorEventos* pEventos;
	Listas::ListaEntidades personagens;
	
public:
	Jogo();
	~Jogo();
	void executar();
};