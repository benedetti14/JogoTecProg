#pragma once

#include <iostream>
#include <map>
#include "Estado.h"

namespace Estados {

	enum class IdEstado;
	class Estado;

	class MaquinaEstado {
	protected:
		Estados::IdEstado estadoAtual;
		Estados::IdEstado ultimoEstado;
		std::map<IdEstado, Estado*> mapaEstados;
	public:
		MaquinaEstado();
		virtual ~MaquinaEstado();
		void mudarEstadoAtual(IdEstado id);
		void atualizarEstadoAtual();
		void desenharEstadoAtual();
		void incluiEstado(Estado* pEstado);
		IdEstado getEstadoAtual() const;
		IdEstado getUltimoEstado() const;

	};
}