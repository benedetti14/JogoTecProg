#pragma once
#include "Fase.h"

namespace Fases {
	class FaseFloresta : public Fase {

	public:
		FaseFloresta();
		~FaseFloresta();
		void inicializa();
		void executar();
		virtual void desenhar();
		void criarMapa();
	};
}