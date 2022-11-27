#pragma once
#include "FaseFloresta.h"
#include "FaseDeserto.h"
#include "MaquinaEstados.h"
#include "Fase.h"
#include "MenuPrincipal.h"
#include "MenuFimJogo.h"
#include "MenuRanking.h"
#include "MenuPausa.h"

class Jogo : public Estados::MaquinaEstado {
private:
	Gerenciadores::GerenciadorGrafico* gGrafico;
	Fases::FaseFloresta* faseFloresta;
	Fases::FaseDeserto* faseDeserto;
	Fases::Fase* fase;
public:
	Jogo();
	~Jogo();
	void criaFase();
	void executar();
	void terminarJogo();
};