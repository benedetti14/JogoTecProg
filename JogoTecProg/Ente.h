#pragma once
#include<iostream>

class Ente
{
protected:
	int id;

public:
	Ente();
	~Ente();
	virtual void executar() = 0;
};

