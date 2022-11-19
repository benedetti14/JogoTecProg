#pragma once
#include "Fase.h"
#include "Estado.h"

namespace Fases {
	class FaseFloresta : public Fase, public Estados::Estado {

	public:
		FaseFloresta(Estados::MaquinaEstado* pME);
		~FaseFloresta();
		void inicializa();
		void executar();
		virtual void desenhar();
		void criarMapa();
		void resetarEstado();
		void terminarFase();
	};
}