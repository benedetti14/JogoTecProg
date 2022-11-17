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
		aux->getElemento()->move();
			
		aux = aux->getProximo();
	}
}

void Listas::ListaEntidades::limparLista(){
	listaEntidades.limpar();
}

