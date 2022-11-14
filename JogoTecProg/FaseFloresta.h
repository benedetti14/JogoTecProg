#pragma once
#include "Fase.h"

namespace Fases {
	class FaseFloresta : public Fase {
		Listas::ListaEntidades listaEntidades;
		Fundo fundo;
	public:
		FaseFloresta();
		~FaseFloresta();
		void inicializa();
		void executar();
	};
}