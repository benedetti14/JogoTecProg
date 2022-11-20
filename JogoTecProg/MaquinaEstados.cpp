#include "MaquinaEstados.h"

Estados::MaquinaEstado::MaquinaEstado(): ultimoEstado(IdEstado::vazio), estadoAtual(IdEstado::vazio), mapaEstados() {
	
}

Estados::MaquinaEstado::~MaquinaEstado(){
	std::map<IdEstado, Estado*>::iterator iterador = mapaEstados.begin();

	while (iterador != mapaEstados.end()) {
		delete (iterador->second); //deleta Estado
		iterador++;
	}
	mapaEstados.clear();
}

void Estados::MaquinaEstado::mudarEstadoAtual(IdEstado id){
	ultimoEstado = estadoAtual;
	estadoAtual = id;
	mapaEstados[id]->resetarEstado();
}


void Estados::MaquinaEstado::atualizarEstadoAtual(){
	mapaEstados[estadoAtual]->atualizar();
}

void Estados::MaquinaEstado::desenharEstadoAtual(){
	mapaEstados[estadoAtual]->desenhar();
}

void Estados::MaquinaEstado::incluiEstado(Estado* pEstado){
	if (pEstado == nullptr) {
		std::cout << "MaquinaEstados: ponteiro para Estado nulo!" << std::endl;
		exit(1);
	}
	mapaEstados.insert(std::pair<IdEstado, Estado*>(pEstado->getIDestado(), pEstado));
}

Estados::IdEstado Estados::MaquinaEstado::getEstadoAtual() const {
	return estadoAtual;
}

Estados::IdEstado Estados::MaquinaEstado::getUltimoEstado() const {
	return ultimoEstado;
}
