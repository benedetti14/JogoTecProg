#include "GerenciadorEventos.h"

Gerenciadores::GerenciadorEventos* Gerenciadores::GerenciadorEventos::pEventos = NULL;

Gerenciadores::GerenciadorEventos::GerenciadorEventos() : pGrafico(pGrafico->getGerenciadorGrafico()), pJogador(NULL) {
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

void Gerenciadores::GerenciadorEventos::setJogador(Entidades::Personagens::Jogador* jogador){
	this->pJogador = jogador;
}

void Gerenciadores::GerenciadorEventos::verificaTeclaPressionada(sf::Keyboard::Key tecla){
    if (tecla == sf::Keyboard::Right) {
        pJogador->setAndar(true);
    } else if (tecla == sf::Keyboard::Left) {
        pJogador->setAndar(false);
    } else if (tecla == sf::Keyboard::Up) {
        pJogador->setSubir(true);
    } else if (tecla == sf::Keyboard::Down) {
        pJogador->setSubir(false);
    } else if (tecla == sf::Keyboard::Escape) {
        pGrafico->fechaJanela();
    }
}

void Gerenciadores::GerenciadorEventos::verificaTeclaSolta(sf::Keyboard::Key tecla) {
    if (tecla == sf::Keyboard::Right || tecla == sf::Keyboard::Left
        || tecla == sf::Keyboard::Up || tecla == sf::Keyboard::Down) {
        pJogador->parar();
    }
}

void Gerenciadores::GerenciadorEventos::executar() {
    sf::Event evento;

    while(pGrafico->getJanela()->pollEvent(evento)) {
        if (evento.type == sf::Event::Closed) {
            pGrafico->fechaJanela();
        } else if (evento.type == sf::Event::KeyPressed) {
            verificaTeclaPressionada(evento.key.code);
        } else if (evento.type == sf::Event::KeyReleased) {
            verificaTeclaSolta(evento.key.code);
        }
    }
}