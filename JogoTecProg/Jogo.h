#pragma once
#include "FaseFloresta.h"


class Jogo {


private:
	Gerenciadores::GerenciadorGrafico* gGrafico;
	Fases::FaseFloresta* faseFloresta;
public:
	Jogo();
	~Jogo();
	void criaFase();
	void executar();
};