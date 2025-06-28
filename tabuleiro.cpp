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

// Distribui n bombas aleatoriamente
void Tabuleiro::sorteiaBombas(int n) {
    int bombas = 0;
    srand(time(NULL));
    while(bombas < n) {
        int l = rand() % 10;
        int c = rand() % 10;
        if(!tabuleiro[l][c].temBomba()) {
            tabuleiro[l][c].colocarBomba();
            bombas++;
        }
    }
}
