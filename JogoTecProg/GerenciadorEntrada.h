#pragma once
#include <SFML\Graphics.hpp>
#include <map>
#include <list>
#include <string>

#include "Observer.h"

namespace Gerenciadores {
	class GerenciadorEntrada {
	private:
		static GerenciadorEntrada* pEntrada;
		std::map< sf::Keyboard::Key, std::string> mapaTecla;
		std::list<Controle::Observer*> observadores;
		std::list<Controle::Observer*>::iterator iterador;
		GerenciadorEntrada();
	public:
		~GerenciadorEntrada();
		static GerenciadorEntrada* getGerenciadorEntrada();
		void incluirObserver(Controle::Observer* pO);
		void removerObserver(Controle::Observer* pO);
		void verificaTeclaPressionada(sf::Keyboard::Key tecla);
		void verificaTeclaSolta(sf::Keyboard::Key tecla);
		std::string getTecla(sf::Keyboard::Key);
	};
}