#pragma once
#include<iostream>

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
			Elemento <TIPO>* anterior;
			TIPO* elemento;

		public:
			Elemento() : proximo(nullptr), anterior(nullptr), elemento(nullptr) {};
			~Elemento() {};
			void setProximo(Elemento<TIPO>* prox) { proximo = prox; };
			Elemento<TIPO>* getProximo() { return proximo; };
			void setAnterior(Elemento<TIPO>* ant) { anterior = ant; };
			Elemento<TIPO>* getAnterior() { return anterior; };
			void setElemento(TIPO* pE) { elemento = pE; };
			TIPO* getElemento() { return elemento; };
		};

		Elemento<TIPO>* pPrimeiro;
		Elemento<TIPO>* pUltimo;
		Elemento<TIPO>* pAtual;

	public:
		Lista();
		~Lista();
		void incluiElemento(Elemento<TIPO>* pE);
		void incluiElemento(TIPO* pE);
		void removeElemento(TIPO* pE);
		void limpar();
		Elemento<TIPO>* getPrimeiro() { return pPrimeiro; };
		Elemento<TIPO>* getUltimo() { return pUltimo; };
		TIPO* inicioLista();
		TIPO* getProximo();

	};

	template <class TIPO>
	Lista<TIPO>::Lista() : pPrimeiro(nullptr), pUltimo(nullptr), pAtual(nullptr) {
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
			} else {
				pUltimo->setProximo(elemento);
				elemento->setAnterior(pUltimo);
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

	template <class TIPO>
	void Lista<TIPO>::removeElemento(TIPO* pE) {
		if (pE) {
			
			Elemento<TIPO>* aux1 = pPrimeiro;
			Elemento<TIPO>* aux2 = nullptr;

			while (aux1->getElemento() != pE && aux1 != nullptr) {
				aux1 = aux1->getProximo();
			}

			if (aux1->getElemento() == pE) {
				if (aux1 == pPrimeiro) {
					pPrimeiro = aux1->getProximo();
				} else if (aux1 == pUltimo) {
					pUltimo = aux1->getAnterior();
					pUltimo->setProximo(nullptr);
				} else {
					aux2 = aux1->getAnterior();
					aux2->setProximo(aux1->getProximo());
				}
			}

			delete aux1;
			aux1 = nullptr;
			aux2 = nullptr;

		}
	}
	

	template <class TIPO>
	TIPO*Lista<TIPO>::inicioLista() {
		pAtual = pPrimeiro;
		if (pAtual) {
			return pAtual->getElemento();
		} else {
			return nullptr;
		}
	}


	template <class TIPO>
	TIPO* Lista<TIPO>::getProximo() {
		pAtual = pAtual->getProximo();
		if (pAtual) {
			return pAtual->getElemento();
		} else {
			return nullptr;
		}
	}
}
