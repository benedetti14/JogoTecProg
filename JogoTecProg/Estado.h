#pragma once
#include "MaquinaEstados.h"

namespace Estados {

	class MaquinaEstado;

	enum class IdEstado {
		vazio = 0,
		menuPrincipal,
		menuPausa,
		jogando,
		novoJogo,
		fimJogo
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
		Estados::IdEstado getId() const;
		//virtual void atualizar() = 0;
		//virtual void desenhar() = 0;
		virtual void executar() = 0;
		virtual void resetarEstado() = 0;
	};
}