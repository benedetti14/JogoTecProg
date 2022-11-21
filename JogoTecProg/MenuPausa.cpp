#include "MenuPausa.h"

Menus::MenuPausa::MenuPausa(Estados::MaquinaEstado* pM, Fases::Fase* pF) :
    Menu(), Estado(pM, Estados::IdEstado::menuPausa), pFase(pF), pontos(0)
{

    ElementosGraficos::Botao* botao = nullptr;


    botao = new ElementosGraficos::Botao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f, pGrafico->getTamanhoJanela().y / 2), "CONTINUAR");
    botao->selecionar(true);
    botoes.push_back(botao);

    botao = new ElementosGraficos::Botao(sf::Vector2f(pGrafico->getTamanhoJanela().x / 2.0f, pGrafico->getTamanhoJanela().y / 2 + 100), "SAIR");
    botoes.push_back(botao);

    maximo = 1;
    selecionado = 0;
}

Menus::MenuPausa::~MenuPausa()
{
}

void Menus::MenuPausa::executar(){
    if (ativo) {
        ativo = false;
        switch (selecionado) {
        case 0:
            mudaEstado(pFase->getIDfase());
            break;
        case 1:
            mudaEstado(Estados::IdEstado::fimJogo);
            break;
        }
    }
}

void Menus::MenuPausa::desenhar() {
    pGrafico->centralizaCamera();
    fundo.desenhar();
    for (int i = 0; i < botoes.size(); i++) {
        botoes[i]->desenhar();
    }
}

void Menus::MenuPausa::atualizar(){
    ativo = true;
}

void Menus::MenuPausa::resetarEstado(){
    for (int i = 0; i < botoes.size(); i++) {
        botoes[i]->selecionar(false);
    }
    selecionado = 0;
    botoes[selecionado]->selecionar(true);
    ativo = true;
}

void Menus::MenuPausa::setPontos(int p){
    pontos = p;
}

int Menus::MenuPausa::getPontos() const {
    return this->pontos;
}

Estados::IdEstado Menus::MenuPausa::getIDfase() const{
    return pFase->getIDfase();
}

void Menus::MenuPausa::abreMenuPausa(){
    if (pMaquinaEstado->getIDEstadoAtual() == Estados::IdEstado::jogandoDeserto || pMaquinaEstado->getIDEstadoAtual() == Estados::IdEstado::jogandoFloresta) {
        mudaEstado(Estados::IdEstado::menuPausa);
        pontos = pFase->getPontosJogador();
    }
}
