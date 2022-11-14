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

void Listas::ListaEntidades::executar() {
	Entidade* aux = listaEntidades.inicioLista();
	while (aux != nullptr) {
		aux->atualizar();
		aux = listaEntidades.getProximo();
	}
}

