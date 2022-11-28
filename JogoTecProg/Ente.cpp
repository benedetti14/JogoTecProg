#include "Ente.h"

Ente::Ente(const IDs::IDs ID) :
    ID(ID) 
{
}

Ente::~Ente() {

}

const IDs::IDs Ente::getID() const {
    return ID;
}


void Ente::setGerenciadorGrafico(Gerenciadores::GerenciadorGrafico* pG){
    pGrafico = pG;
}

Gerenciadores::GerenciadorGrafico* Ente::pGrafico = NULL;
