#pragma once
#include "Fase.h"

namespace Fases {
	class FaseFloresta : public Fase {
	private:
		Listas::ListaEntidades listaEntidades;
		Listas::ListaEntidades listaPersonagens;
		Listas::ListaEntidades listaObstaculos;
		Fundo fundo;
		Gerenciadores::GerenciadorColisao* pColisor;
	public:
		FaseFloresta();
		~FaseFloresta();
		void inicializa();
		void executar();
		virtual void desenhar();
	};
}