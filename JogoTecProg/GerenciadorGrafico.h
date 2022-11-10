#pragma once
#include <SFML/Graphics.hpp>


namespace Gerenciadores {
	class GerenciadorGrafico {
	private:
		sf::RenderWindow* janela;
		static GerenciadorGrafico* pGrafico;
		GerenciadorGrafico();
	public:
		~GerenciadorGrafico();
		static GerenciadorGrafico* getGerenciadorGrafico();
		sf::RenderWindow* getJanela();
		const bool janelaAberta();
		void fechaJanela();
		void limpaJanela();
		void mostrar();
		//void desenhar(sf::RectangleShape corpo);
	};
}

