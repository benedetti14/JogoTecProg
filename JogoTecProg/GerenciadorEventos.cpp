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
        pJogador->andar(false);
    } else if (tecla == sf::Keyboard::Left) {
        pJogador->andar(true);
    } else if (tecla == sf::Keyboard::Up) {
        pJogador->pular();
    } else if (tecla == sf::Keyboard::Escape) {
        pGrafico->fechaJanela();
	}
	else if (tecla == sf::Keyboard::X) {
		pJogador->atacar(true);
    }
    else {
        pJogador->parar();
    }
}

void Gerenciadores::GerenciadorEventos::verificaTeclaSolta(sf::Keyboard::Key tecla) {
    if (tecla == sf::Keyboard::Right || tecla == sf::Keyboard::Left) {
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