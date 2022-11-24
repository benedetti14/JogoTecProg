#pragma once
#include "Fase.h"
#include "Estado.h"
#include "CriaMundo.h"

namespace Fases {
	class FaseFloresta : public Fase, public Estados::Estado {

	public:
		FaseFloresta(Estados::MaquinaEstado* pME);
		~FaseFloresta() override;
		void inicializa();
		void executar();
		virtual void desenhar();

		void atualizar();
		void resetarEstado();
		Estados::IdEstado getIDfase() const;
		CriaMundo mundo;
		//void terminarFase();
	};
}