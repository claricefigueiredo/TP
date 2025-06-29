#ifndef JOGO_H
#define JOGO_H

#include "Tabuleiro.h"
#include <iostream>

class Jogo
{
private:
    Tabuleiro tabuleiro;
public:
    //Controla o jogo lendo as entradas dos jogadores
    void jogo();
    //Verifica se há ganhador, se quantidade >0 não ganhou, senão, ganhou
    int Venceu();
};

#endif //JOGO_H