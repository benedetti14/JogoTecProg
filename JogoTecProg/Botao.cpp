#include "Botao.h"


#define C_BOTAO_ORIGINAL "../JogoTecProg/imagens/menu/Botao_Original.jpeg"
#define C_BOTAO_SELECIONADO "../JogoTecProg/imagens/menu/Botao_Selecionado.jpeg"

#define BOTAO_X 300.f
#define BOTAO_Y 50.f
#define TAM_FONTE 30
#define C_FONTE "../JogoTecProg/imagens/fontes/Fonte.ttf"

ElementosGraficos::Botao::Botao(sf::Vector2f pos, std::string info): texturaOriginal(), //texto1(),
texturaSelecionado(), Animacao() {
	texturaOriginal = pGrafico->setTextura(C_BOTAO_ORIGINAL);
	texturaSelecionado = pGrafico->setTextura(C_BOTAO_SELECIONADO);

	corpo->setSize(sf::Vector2f(BOTAO_X, BOTAO_Y));
	corpo->setOrigin(sf::Vector2f(BOTAO_X / 2, BOTAO_Y / 2));
	corpo->setPosition(pos);
	corpo->setTexture(&texturaOriginal);
	/*texto.setTamanhoFonte(TAM_FONTE);
	texto.setPosicao(pos);
	texto.setCor(77, 68, 44);*/
	
	/*
	sf::FloatRect tamTexto = texto1.getLocalBounds();

	texto1.setString(info);
	texto1.setFont(pGrafico->setFonte(C_FONTE));
	texto1.setCharacterSize(TAM_FONTE);
	texto1.setOrigin(sf::Vector2f(tamTexto.width / 2, tamTexto.height)); // alinhamento no centro 
	texto1.setPosition(pos);
	texto1.setFillColor(sf::Color::White); */
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
	pGrafico->getJanela()->draw(texto1);
	//texto.desenhar();
}
