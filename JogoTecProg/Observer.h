#pragma once
#include "GerenciadorEntrada.h"

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
