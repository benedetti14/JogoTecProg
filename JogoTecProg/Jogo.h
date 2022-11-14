#pragma once
#include "FaseFloresta.h"

class Jogo
{
private:
	Fases::FaseFloresta* faseFloresta;
public:
	Jogo();
	~Jogo();
	void executar();
};