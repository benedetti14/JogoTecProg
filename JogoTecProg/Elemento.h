#pragma once
#include<iostream>


namespace Listas {
	
	template<class TIPO>
	class Elemento
	{
	private: 
		Elemento<TIPO>* proximo;
		Elemento<TIPO>* anterior;
		TIPO* info;
	public:
		Elemento();
		~Elemento();
		void setProximo(Elemento<TIPO*> prox);
		Elemento<TIPO*> getProximo();
		void setAnterior(Elemento<TIPO*> ant);
		Elemento<TIPO*> getAnterior();
		void setInfo(TIPO* i);
		TIPO* getInfo();
	};
}

