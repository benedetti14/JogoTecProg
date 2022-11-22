#include "ControleTexto.h"

Controle::ControleTexto::ControleTexto(): Observer(){
}

Controle::ControleTexto::~ControleTexto(){
}

void Controle::ControleTexto::notificaTeclaPressionada(std::string tecla)
{
    if (tecla == "Enter" ||
        tecla == "Right" ||
        tecla == "Left" ||
        tecla == "Up" ||
        tecla == "Down" ||
        tecla == "Escape" ||
        tecla == "Control" ||
        tecla == "Shift" ||
        tecla == "RControl" ||
        tecla == "RShift" ||
        tecla == "Tab" ||
        tecla == "Unknown") {
        return;
    }

    if (tecla == "BackSpace") {
        if (texto.size() > 0) {
            texto.pop_back();
        }
    } else if (tecla == "Space") {
        texto += " ";
    } else {
        texto += tecla;
    }

}

void Controle::ControleTexto::notificaTeclaSolta(std::string tecla)
{
}

std::string Controle::ControleTexto::getString() const
{
	return texto;
}

void Controle::ControleTexto::resetar()
{
    texto = "";
}
