#include "Animacao.h"

ElementosGraficos::Animacao::Animacao(sf::RectangleShape* pCorpo): 
corpo(pCorpo), mapaImagem(), imgAtual(parado), relogio()
{
}

ElementosGraficos::Animacao::~Animacao(){
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

void ElementosGraficos::Animacao::atualizar(IdAnimacao imgAtual, const bool esquerda){
	if (this->imgAtual != imgAtual) {
		this->imgAtual = imgAtual;
		mapaImagem[this->imgAtual]->reseta();
	}

	float dT = relogio.getElapsedTime().asSeconds();
	relogio.restart();

	Imagem* imagem = mapaImagem[imgAtual];
	sf::Vector2f escala = imagem->getEscala();
	sf::IntRect tamImagem = imagem->getTamanho();

	imagem->atualizar(dT, esquerda);
	corpo->setScale(escala);
	corpo->setTextureRect(tamImagem);
	corpo->setTexture(imagem->getTexture());

}

void ElementosGraficos::Animacao::incluiAnimacao(IdAnimacao id, const char* cTextura, unsigned int qtdImagens, const float tempoTroca, sf::Vector2f escala)
{
	Imagem* imagem = new Imagem(cTextura, qtdImagens, tempoTroca, escala);

	if (imagem == nullptr) {
		std::cout << "Animacao: erro ao incluir animacao!" << std::endl;
		exit(1);
	}
	mapaImagem.insert(std::pair<IdAnimacao, Imagem*>(id, imagem));

}
