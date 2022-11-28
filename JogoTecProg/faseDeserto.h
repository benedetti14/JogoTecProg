#pragma once
#include "Fase.h"
#include "Estado.h"
#include "CriaMundo.h"

namespace Fases {
	class FaseDeserto : public Fase, public Estados::Estado {

	public:
		FaseDeserto(Estados::MaquinaEstado* pME);
		~FaseDeserto() override;
		void inicializa();
		void executar();
		virtual void desenhar();

		void atualizar();
		void resetarEstado();
		Estados::IdEstado getIDfase() const;
		CriaMundo mundo;
	};
}
