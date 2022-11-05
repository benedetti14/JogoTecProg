#pragma once
#include<iostream>
#include "Elemento.h"

namespace Listas {
	template<class TIPO>
	class Lista
	{
	private:
		//classe aninhada
		template <class TIPO>
		class Elemento {
		private:
			Elemento <TIPO>* proximo;
			TIPO* elemento;

		public:
			Elemento() : proximo(nullptr), elemento(nullptr) {};
			~Elemento() {};
			void setProximo(Elemento<TIPO>* prox) { proximo = prox; };
			Elemento<TIPO>* getProximo() { return proximo; };
			void setElemento(TIPO* pE) { elemento = pE; };
			TIPO* getElemento() { return elemento; };
		};

		Elemento<TIPO>* pPrimeiro;
		Elemento<TIPO>* pUltimo;

	public:
		Lista();
		~Lista();
		void incluiElemento(Elemento<TIPO>* pE);
		void incluiElemento(TIPO* pE);
		void limpar();
		Elemento<TIPO>* getPrimeiro() { return pPrimeiro; };
		Elemento<TIPO>* getUltimo() { return pUltimo; };
	};

	template <class TIPO>
	Lista<TIPO>::Lista() :pPrimeiro(nullptr), pUltimo(nullptr) {
	}

	template <class TIPO>
	Lista<TIPO>:: ~Lista() {
		limpar();
	}

	template <class TIPO>
	void Lista<TIPO>::limpar() {
		Elemento<TIPO>* aux1, * aux2;
		aux1 = pPrimeiro;

		while (aux1 != NULL) {
			aux2 = aux1->getProximo();
			delete(aux1->getElemento());
			aux1 = aux2;
		}

		pPrimeiro = nullptr;
		pUltimo = nullptr;
	}

	template <class TIPO>
	void Lista<TIPO>::incluiElemento(Elemento<TIPO>* elemento) {
		if (elemento) {
			if (pPrimeiro == nullptr) {
				pPrimeiro = elemento;
				pUltimo = pPrimeiro;
			}
			else {
				pUltimo->setProximo(elemento);
				elemento->setProximo(nullptr);
				pUltimo = elemento;
			}
		}
	}

	template <class TIPO>
	void Lista<TIPO>::incluiElemento(TIPO* i) {
		if (i) {
			Elemento<TIPO>* pE = new Elemento<TIPO>();
			pE->setElemento(i);
			incluiElemento(pE);
		}
	}
	
}
