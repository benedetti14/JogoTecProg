#pragma once
#include<iostream>
#include "GerenciadorGrafico.h"

class Ente
{
protected:
	int id;
	Gerenciadores::GerenciadorGrafico* pGrafico;
public:
	Ente();
	~Ente();
	virtual void desenhar() = 0;
};

