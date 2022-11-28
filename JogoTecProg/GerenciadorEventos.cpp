#include "GerenciadorEventos.h"

Gerenciadores::GerenciadorEventos* Gerenciadores::GerenciadorEventos::pEventos = NULL;

Gerenciadores::GerenciadorEventos::GerenciadorEventos() : pGrafico(pGrafico->getGerenciadorGrafico()), 
pEntrada(pEntrada->getGerenciadorEntrada()) 
{
}

Gerenciadores::GerenciadorEventos::~GerenciadorEventos()
{
}

Gerenciadores::GerenciadorEventos* Gerenciadores::GerenciadorEventos::getGerenciadorEventos() {
    if (pEventos == NULL) {
        pEventos = new GerenciadorEventos();
    }
    return pEventos;
}

void Gerenciadores::GerenciadorEventos::executar() {
    sf::Event evento;

    while(pGrafico->getJanela()->pollEvent(evento)) {
        if (evento.type == sf::Event::Closed) {
            pGrafico->fechaJanela();
        } else if (evento.type == sf::Event::KeyPressed) {
           pEntrada->verificaTeclaPressionada(evento.key.code);
        } else if (evento.type == sf::Event::KeyReleased) {
           pEntrada->verificaTeclaSolta(evento.key.code);
        }
    }
}