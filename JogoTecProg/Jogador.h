#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include "Entidade.h"
#include "Personagem.h"


namespace Entidades {
	namespace Personagens {
		class Jogador : public Personagem {
		private:
			bool andar;
			bool subir;
		public:
			Jogador(sf::Vector2f posi, sf::Vector2f velo, sf::Vector2f tam);
			~Jogador();
			void setAndar(bool a);
			void setSubir(bool s);
			void move();
		};
	}
};