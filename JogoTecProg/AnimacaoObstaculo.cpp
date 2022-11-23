#include "AnimacaoObstaculo.h"

ElementosGraficos::AnimacaoObstaculo::AnimacaoObstaculo(): Animacao(), textura() {
}

ElementosGraficos::AnimacaoObstaculo::~AnimacaoObstaculo()
{
}

void ElementosGraficos::AnimacaoObstaculo::inicializa(sf::Vector2f pos, sf::Vector2f tam, const char* cTextura) {
	
	textura = pGrafico->setTextura(cTextura);

	corpo->setTexture(&textura);
	corpo->setPosition(pos);
	corpo->setSize(tam);

}
