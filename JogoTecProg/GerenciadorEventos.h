#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"
#include "GerenciadorEntrada.h"


namespace Gerenciadores {
	class GerenciadorEventos {
	private:
		GerenciadorEntrada* pEntrada;
		GerenciadorGrafico* pGrafico;
		static GerenciadorEventos* pEventos;
		GerenciadorEventos();
	public:
		~GerenciadorEventos();
		static GerenciadorEventos* getGerenciadorEventos();
		void executar();
	};
}