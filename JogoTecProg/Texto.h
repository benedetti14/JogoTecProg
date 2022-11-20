#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "GerenciadorGrafico.h"

#define C_FONTE "../JogoTecProg/imagens/fontes/Fonte.ttf"

namespace ElementosGraficos {
	class Texto {
	private:
		sf::Text texto;
		std::string info;
		static Gerenciadores::GerenciadorGrafico* pGrafico;
	public:
		Texto(std::string info = "", sf::Vector2f pos = { 0.0f,0.0f }, const char* cTexto = C_FONTE);
		~Texto();
		void setInfo(std::string info);
		void setPosicao(sf::Vector2f pos);
		void setTamanhoFonte(const unsigned int);
		std::string getInfo() const;
		sf::Vector2f getPosicao() const;
		sf::Vector2f getTamanho() const;
		void desenhar();
		void setCor(const unsigned int R, const unsigned int G, const unsigned int B);
	};
}