#pragma once

#include "Observer.h"

namespace Controle {
	class ControleTexto : public Observer {
	private:
		std::string texto;
	public:
		ControleTexto();
		~ControleTexto();
		void notificaTeclaPressionada(std::string tecla);
		void notificaTeclaSolta(std::string tecla);
		std::string getString() const;
		void resetar();
	};
}