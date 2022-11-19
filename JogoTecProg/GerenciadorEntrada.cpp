#include "GerenciadorEntrada.h"

Gerenciadores::GerenciadorEntrada* Gerenciadores::GerenciadorEntrada::pEntrada = nullptr;

Gerenciadores::GerenciadorEntrada::GerenciadorEntrada(){
    mapaTecla[sf::Keyboard::A] = "A";
    mapaTecla[sf::Keyboard::B] = "B";
    mapaTecla[sf::Keyboard::C] = "C";
    mapaTecla[sf::Keyboard::D] = "D";
    mapaTecla[sf::Keyboard::E] = "E";
    mapaTecla[sf::Keyboard::F] = "F";
    mapaTecla[sf::Keyboard::G] = "G";
    mapaTecla[sf::Keyboard::H] = "H";
    mapaTecla[sf::Keyboard::I] = "I";
    mapaTecla[sf::Keyboard::J] = "J";
    mapaTecla[sf::Keyboard::K] = "K";
    mapaTecla[sf::Keyboard::L] = "L";
    mapaTecla[sf::Keyboard::M] = "M";
    mapaTecla[sf::Keyboard::N] = "N";
    mapaTecla[sf::Keyboard::O] = "O";
    mapaTecla[sf::Keyboard::P] = "P";
    mapaTecla[sf::Keyboard::Q] = "Q";
    mapaTecla[sf::Keyboard::R] = "R";
    mapaTecla[sf::Keyboard::S] = "S";
    mapaTecla[sf::Keyboard::T] = "T";
    mapaTecla[sf::Keyboard::U] = "U";
    mapaTecla[sf::Keyboard::V] = "V";
    mapaTecla[sf::Keyboard::W] = "W";
    mapaTecla[sf::Keyboard::X] = "X";
    mapaTecla[sf::Keyboard::Y] = "Y";
    mapaTecla[sf::Keyboard::Z] = "Z";
    mapaTecla[sf::Keyboard::Num1] = "1";
    mapaTecla[sf::Keyboard::Num2] = "2";
    mapaTecla[sf::Keyboard::Num3] = "3";
    mapaTecla[sf::Keyboard::Num4] = "4";
    mapaTecla[sf::Keyboard::Num5] = "5";
    mapaTecla[sf::Keyboard::Num6] = "6";
    mapaTecla[sf::Keyboard::Num7] = "7";
    mapaTecla[sf::Keyboard::Num8] = "8";
    mapaTecla[sf::Keyboard::Num9] = "9";
    mapaTecla[sf::Keyboard::Num0] = "0";
    mapaTecla[sf::Keyboard::Numpad0] = "0";
    mapaTecla[sf::Keyboard::Numpad1] = "1";
    mapaTecla[sf::Keyboard::Numpad2] = "2";
    mapaTecla[sf::Keyboard::Numpad3] = "3";
    mapaTecla[sf::Keyboard::Numpad4] = "4";
    mapaTecla[sf::Keyboard::Numpad5] = "5";
    mapaTecla[sf::Keyboard::Numpad6] = "6";
    mapaTecla[sf::Keyboard::Numpad7] = "7";
    mapaTecla[sf::Keyboard::Numpad8] = "8";
    mapaTecla[sf::Keyboard::Numpad9] = "9";
    mapaTecla[sf::Keyboard::Space] = "Space";
    mapaTecla[sf::Keyboard::Enter] = "Enter";
    mapaTecla[sf::Keyboard::Escape] = "Escape";
    mapaTecla[sf::Keyboard::BackSpace] = "BackSpace";
    mapaTecla[sf::Keyboard::Right] = "Right";
    mapaTecla[sf::Keyboard::Left] = "Left";
    mapaTecla[sf::Keyboard::Up] = "Up";
    mapaTecla[sf::Keyboard::Down] = "Down";
    mapaTecla[sf::Keyboard::LControl] = "Control";
    mapaTecla[sf::Keyboard::LShift] = "Shift";
    mapaTecla[sf::Keyboard::RControl] = "RControl";
    mapaTecla[sf::Keyboard::RShift] = "RShift";
    mapaTecla[sf::Keyboard::Hyphen] = "-";
    mapaTecla[sf::Keyboard::Tab] = "Tab";
}

Gerenciadores::GerenciadorEntrada::~GerenciadorEntrada(){
    mapaTecla.clear();
    observadores.clear();
}

Gerenciadores::GerenciadorEntrada* Gerenciadores::GerenciadorEntrada::getGerenciadorEntrada(){
	if (pEntrada == nullptr) {
		pEntrada = new GerenciadorEntrada();
	}
	return pEntrada;
}

void Gerenciadores::GerenciadorEntrada::incluirObserver(Controle::Observer *pO){
    observadores.push_back(pO);
}

void Gerenciadores::GerenciadorEntrada::removerObserver(Controle::Observer *pO){
    observadores.remove(pO);
}

void Gerenciadores::GerenciadorEntrada::verificaTeclaPressionada(sf::Keyboard::Key tecla){

    iterador = observadores.begin();
    while (iterador != observadores.end()) {
        (*iterador)->notificaTeclaPressionada(getTecla(tecla));
        iterador++;
    }
}

void Gerenciadores::GerenciadorEntrada::verificaTeclaSolta(sf::Keyboard::Key tecla){
    
    iterador = observadores.begin();
    while (iterador != observadores.end()) {
        (*iterador)->notificaTeclaSolta(getTecla(tecla));
        iterador++;
    }
}

std::string Gerenciadores::GerenciadorEntrada::getTecla(sf::Keyboard::Key tecla){
    if (mapaTecla[tecla] == "") {
        return 0;
    } else {
        return mapaTecla[tecla];
    }
}
