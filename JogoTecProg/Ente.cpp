#include "Ente.h"

Ente::Ente(const IDs::IDs ID) :
    ID(ID), pGrafico(pGrafico->getGerenciadorGrafico())
{

}

Ente::~Ente() {

}

const IDs::IDs Ente::getID() const {
    return ID;
