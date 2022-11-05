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
