#include "AnimacaoPersonagem.h"

ElementosGraficos::AnimacaoPersonagem::AnimacaoPersonagem(sf::Vector2f pos, sf::Vector2f tam): Animacao(),
mapaImagem(), imgAtual(parado), relogio()
{
	corpo->setPosition(pos);
	corpo->setSize(tam);
}


ElementosGraficos::AnimacaoPersonagem::~AnimacaoPersonagem(){
	std::map<IdAnimacao, Imagem*>::iterator it = mapaImagem.begin();
	while (it != mapaImagem.end()) {
		if (it->second) {
			delete (it->second); //deleta a Imagem 
			it->second = nullptr;
		}
		it++;
	}
	mapaImagem.clear();
}

void ElementosGraficos::AnimacaoPersonagem::atualizar(IdAnimacao imgAtual, const bool esquerda){
	if (this->imgAtual != imgAtual) {
		if (this->imgAtual == 0) {
			mapaImagem[this->imgAtual]->reseta();
		}
		this->imgAtual = imgAtual;
	}

	float dT = relogio.getElapsedTime().asSeconds();
	relogio.restart();

	Imagem* imagem = mapaImagem[this->imgAtual];
	sf::Vector2f escala = imagem->getEscala();
	sf::IntRect tamImagem = imagem->getTamanho();

	imagem->atualizar(dT, esquerda);
	corpo->setTextureRect(tamImagem);
	corpo->setTexture(imagem->getTexture());
	corpo->setScale(escala);
}

void ElementosGraficos::AnimacaoPersonagem::incluiAnimacao(IdAnimacao id, const char* cTextura, unsigned int qtdImagens, const float tempoTroca, sf::Vector2f escala)
{
	Imagem* imagem = new Imagem(cTextura, qtdImagens, tempoTroca, escala);

	if (imagem == nullptr) {
		std::cout << "Animacao: erro ao incluir animacao!" << std::endl;
		exit(1);
	}
	mapaImagem.insert(std::pair<IdAnimacao, Imagem*>(id, imagem));

}

void ElementosGraficos::AnimacaoPersonagem::setOrigin(sf::Vector2f origem){
	corpo->setOrigin(origem);
}
