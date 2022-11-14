#include "Fundo.h"

Fundo::Fundo(const char* cTextura, sf::Vector2f tJanela): Ente(IDs::IDs::fundo), textura(pGrafico->setTextura(cTextura)), 
pAntCamera(pGrafico->getCamera().getCenter()), tamJanela(tJanela)
{
	fundo.setSize(tamJanela);
	fundo.setTexture(&textura);
	fundo.setPosition(0.0f, 0.0f);
}

Fundo::~Fundo(){
}

void Fundo::atualizar(){
	sf::Vector2f posicaoCamera = pGrafico->getCamera().getCenter();
	sf::Vector2f dS = posicaoCamera - pAntCamera;
	pAntCamera = posicaoCamera;

	if (dS.x != 0.0f) {
		const float posiEsquerda = posicaoCamera.x - tamJanela.x / 2.0f;
		fundo.setPosition(posiEsquerda, 0.0f);
	}
}

void Fundo::desenhar() {
	atualizar();
	pGrafico->getJanela()->draw(fundo);
}
