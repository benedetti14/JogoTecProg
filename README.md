# Viagem no Tempo - o Jogo

Este é um projeto da disciplina de Técnicas de Programação da UTFPR, nele deveriamos realizar a criação de um software de plataforma em formato de jogo, na linguagem C++. Para isso, utilizamos a biblioteca SFML (Simple and Fast Multimedia Library), versão 2.5.1, para realizar a parte gráfica. Para compilação utilizamos o Visual Studio 2022. No desenvolvimento do jogo, utilizou-se conceitos introdutórios de engenharia de Software, e avançados de Programação Orientada a Objetos. Não obstante, foi necessário compreender e seguir uma tabela de requisitos funcionais e técnicos, assim como desenvolver uma modelagem (análise e projeto), através de diagramas de classes em UML, a partir de um modelo preestabelecido. 
Para melhor entendimento do funcionamento do software, abaixo temos uma explicação do jogo em si, imagens dos diagramas de classe feitos (especificando as classes e suas relações).

O jogo conta com um jogador, o Cavalheiro, controlado pelas teclas ‘Up’, ‘Down’, ‘Right’ e ‘Left’, que consegue atacar outros personagens usando a tecla ‘X’. Este jogador pode passar por duas fases diferentes, a Fase Floresta e a Fase Deserto, cada qual composta por objetos e personagens variados, que se relacionam de maneira distinta uns com os outros. 
Em ambas as fases o jogador pode enfrentar inimigos como o Dinossauro, comum às duas, a Cowboy e o Ninja, restritos à fase Floresta e Deserto, respectivamente. O último inimigo, inclusive, é o ‘Chefão’ do jogo, e pode disparar projéteis na direção do jogador. Além disso, as fases possuem três tipos de obstáculos com os quais o jogador pode interagir, a Plataforma, em que as entidades podem subir, a Caixa, que pode ser empurrada, e a Pedra, que causa dano de acordo com seu  nível de dureza.
Ao iniciar o jogo existe um Menu Principal, no qual pode-se escolher entre as duas fases. Se optou-se pela primeira fase e conseguiu-se chegar ao final sem que todas as vidas fossem perdidas, o jogador é automaticamente levado à segunda fase. Nas duas fases, ao pressionar a tecla ‘Escape’ um Menu de Pausa é invocado, onde pode-se escolher entre sair do jogo ou continuar na fase.
Todos os personagens têm um número pré estabelecido de vidas, que são perdidas à medida que ocorre colisão, de acordo com o nível de dano que cada um pode causar. Os inimigos perdem vidas caso o jogador os ataque, e vice versa, com a diferença de que o jogador também perde vidas ao encostar na Pedra.

# Diagrama de Classes UML:

![Diagrama UML](JogoTecProg/imagens/UML/diagrama5.jpg)
