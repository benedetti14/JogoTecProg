#pragma once
#include "GerenciadorEntrada.h"

namespace Gerenciadores {
	class GerenciadorEntrada;
}

namespace Controle {

	class Observer {
	protected:
		Gerenciadores::GerenciadorEntrada* pEntrada;
	public:
		Observer();
		~Observer();
		virtual void notificaTeclaPressionada(std::string tecla) = 0;
		virtual void notificaTeclaSolta(std::string tecla) = 0;
	};
}
