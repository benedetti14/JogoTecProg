#pragma once
#include<iostream>
#include "Elemento.h"

namespace Listas {
	template<class TL>
	class Lista
	{
	private:
		Elemento<TL>* pPrimeiro;
		Elemento<TL>* pUltimo;
	public:
		Lista();
		~Lista();
		void incluiElemento(Elemento<TL>* pE);
		void incluiElemento(TL* i);
		void limpar();
		Elemento<TL>* getPrimeiro();
		Elemento<TL>* getAtual();
	};
}
