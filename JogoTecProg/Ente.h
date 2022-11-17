#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

#include "IDs.h"
#include "GerenciadorGrafico.h"

class Ente {
protected:
    //static Gerenciadores::GerenciadorGrafico* pGrafico;
    Gerenciadores::GerenciadorGrafico* pGrafico;
    const IDs::IDs ID;
public:
    Ente(const IDs::IDs ID);
    ~Ente();
    const IDs::IDs getID() const;
    //void setGerenciadorGrafico(Gerenciadores::GerenciadorGrafico* pG);
    virtual void desenhar() = 0;
};