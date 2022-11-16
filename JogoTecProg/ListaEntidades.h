#pragma once
#include <iostream>
#include "Lista.h"
#include "Entidade.h"

using namespace Entidades;

namespace Listas {
	class ListaEntidades
	{
	private:
		Lista<Entidade> listaEntidades;
	public:
		ListaEntidades();
		~ListaEntidades();
		void incluiEntidade(Entidade* pEnt);
		void removeEntidade(Entidade* pEnt);
		int getTamanho();
		Entidade* operator[](int pos);
		void executar();
	};
}

