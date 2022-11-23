#include "Estado.h"

Estados::Estado::Estado(MaquinaEstado* pME, IdEstado id): pMaquinaEstado(pME), ID(id) {
}

Estados::Estado::~Estado(){
	pMaquinaEstado = nullptr;
}

void Estados::Estado::setMaquinaEstado(MaquinaEstado* pME){
	pMaquinaEstado = pME;
}

void Estados::Estado::mudaEstado(IdEstado id){
	if (pMaquinaEstado == nullptr) {
		std::cout << "deu ruim" << std::endl;
	}
	else {

		pMaquinaEstado->mudarEstadoAtual(id);
	}
}

Estados::IdEstado Estados::Estado::getIDestado() const{
	return ID;
}

