#pragma once
#include "MaquinaEstados.h"

namespace Estados {

	class MaquinaEstado;

	enum class IdEstado {
		vazio = 0,
		menuPrincipal,
		menuPausa,
		jogandoFloresta,
		jogandoDeserto,
		novoJogo,
		fimJogo, 
		ranking
	};

	class Estado {
	protected:
		IdEstado ID;
		MaquinaEstado* pMaquinaEstado;
	public:
		Estado(MaquinaEstado* pME = nullptr, IdEstado id = IdEstado::vazio);
		virtual ~Estado();
		void setMaquinaEstado(MaquinaEstado* pME);
		void mudaEstado(IdEstado id);
		Estados::IdEstado getIDestado() const;
		virtual void atualizar() = 0;
		virtual void desenhar() = 0;
		virtual void resetarEstado() = 0;
	};
}