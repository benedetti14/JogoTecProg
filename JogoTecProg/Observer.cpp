#include "Observer.h"

Controle::Observer::Observer(): pEntrada(pEntrada->getGerenciadorEntrada()) {
	pEntrada->incluirObserver(this);
}

Controle::Observer::~Observer(){
	pEntrada->removerObserver(this);
}
