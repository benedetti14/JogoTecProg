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
	/*aux->atualizar();
	std::cout << aux << std::endl;
	aux = listaEntidades.getProximo();
	std::cout << aux << std::endl;*/
	//aux->atualizar();
	//aux = listaEntidades.getProximo();
	//aux->atualizar();
	while (aux != nullptr) {
		aux->getElemento()->atualizar();
		aux = aux->getProximo();
	}

	/*int tamanho = listaEntidades.getTamanho();
	Entidades::Entidade* aux = nullptr;
	std::cout << tamanho << std::endl;
	for (int i = 0; i < tamanho; i++) {
		aux = listaEntidades.operator[](i);
		aux->atualizar();
	}*/
}

