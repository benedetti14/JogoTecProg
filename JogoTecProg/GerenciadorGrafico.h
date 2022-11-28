#pragma once
#include <SFML/Graphics.hpp>


namespace Gerenciadores {
	class GerenciadorGrafico {
	private:
		sf::RenderWindow* janela;
		sf::View camera;
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
		sf::Vector2f getTamanhoJanela() const;
		sf::Texture setTextura(const char* cTextura);
		const sf::View getCamera();
		void atualizaCamera(sf::Vector2f posJogador);
		void centralizaCamera();
	};
}