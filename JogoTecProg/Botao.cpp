#include "Botao.h"


#define C_BOTAO_ORIGINAL "../JogoTecProg/imagens/menu/Botao_Original.jpeg"
#define C_BOTAO_SELECIONADO "../JogoTecProg/imagens/menu/Botao_Selecionado.jpeg"

#define BOTAO_X 300.f
#define BOTAO_Y 50.f
#define TAM_FONTE 30

ElementosGraficos::Botao::Botao(sf::Vector2f pos, const char* original, const char* selecionado):
texturaOriginal(), texturaSelecionado(), Animacao() {
	texturaOriginal = pGrafico->setTextura(original);
	texturaSelecionado = pGrafico->setTextura(selecionado);

	corpo->setSize(sf::Vector2f(BOTAO_X, BOTAO_Y));
	corpo->setOrigin(sf::Vector2f(BOTAO_X / 2, BOTAO_Y / 2));
	corpo->setPosition(pos);
	corpo->setTexture(&texturaOriginal);

}

ElementosGraficos::Botao::~Botao()
{
}

void ElementosGraficos::Botao::selecionar(const bool selecionado){
	if (selecionado) {
		corpo->setTexture(&texturaSelecionado);
	} else {
		corpo->setTexture(&texturaOriginal);
	}
}

void ElementosGraficos::Botao::desenhar(){

	pGrafico->getJanela()->draw(*corpo);
}
