#include "Tabuleiro.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Inicializa todas as células como vazias
void Tabuleiro::iniciaTabuleiro() {
    for(int l = 0; l < 10; l++) {
        for(int c = 0; c < 10; c++) {
            tabuleiro[l][c] = Celula();
        }
    }
}
