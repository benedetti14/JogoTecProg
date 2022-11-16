#pragma once
#include "Fase.h"

namespace Fases {
	class FaseFloresta : public Fase {
	private:
		Listas::ListaEntidades listaEntidades;
		Fundo fundo;
	public:
		FaseFloresta();
		~FaseFloresta();
		void inicializa();
		void executar();
		virtual void desenhar();
	};
}