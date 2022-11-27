#include "ListaEntidades.h"

Listas::ListaEntidades::ListaEntidades(): listaEntidades(){
}

Listas::ListaEntidades::~ListaEntidades(){
}

void Listas::ListaEntidades::incluiEntidade(Entidade* pEnt){
	if (pEnt) {
		listaEntidades.incluiElemento(pEnt);
	}
}

void Listas::ListaEntidades::removeEntidade(Entidade* pEnt) {
	if (pEnt) {
		listaEntidades.removeElemento(pEnt);
	}
}

int Listas::ListaEntidades::getTamanho() {
	return listaEntidades.getTamanho();
}

Entidades::Entidade* Listas::ListaEntidades::operator[](int pos) {
	return listaEntidades.operator[](pos);
}

void Listas::ListaEntidades::executar() {
	Listas::Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* aux = listaEntidades.getPrimeiro();
	while (aux != nullptr) {
		if (aux->getElemento() != nullptr) {
			if (aux->getElemento()->estaVivo()) {
				aux->getElemento()->move();
			}
			else {
				listaEntidades.removeElemento(aux->getElemento());
			}
		}
			
		aux = aux->getProximo();
	}
}

void Listas::ListaEntidades::limparLista(){
	listaEntidades.limpar();
}

