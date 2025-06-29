#ifndef JOGO_H
#define JOGO_H
#include <string>
#include "tabuleiro.h"
#include <iostream>

class Jogo
{
private:
    Tabuleiro tabuleiro;
public:
    Jogo();
    //Controla o jogo lendo as entradas dos jogadores
   std:: string play();
    //Verifica se há ganhador, se quantidade >0 não ganhou, senão, ganhou
    int Venceu();
};

#endif //JOGO_H