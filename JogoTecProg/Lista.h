#pragma once
#include<iostream>
#include "Elemento.h"

namespace Listas {
	template<class TL>
	class Lista
	{
	private:
		Elemento<Tl>* pPrimeiro;
		Elemento<Tl>* pUltimo;
	public:
		Lista();
		~Lista();
		void incluiElemento(Elemento<Tl>* pE);
		void incluiElemento(Tl* i);
		void limpar();
		Elemento<Tl>* getPrimeiro();
		Elemento<Tl>* getAtual();
	};
}
