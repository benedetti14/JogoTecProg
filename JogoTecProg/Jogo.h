#pragma once
#include "FaseFloresta.h"


class Jogo {


private:
	Gerenciadores::GerenciadorGrafico* gGrafico;
	Fases::FaseFloresta* faseFloresta;
	Fases::Fase* fase;
public:
	Jogo();
	~Jogo();
	void criaFase();
	void executar();
};