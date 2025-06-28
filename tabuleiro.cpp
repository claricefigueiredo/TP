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

// Verifica se a posição está dentro do tabuleiro
bool Tabuleiro::coordenadaValida(int linha, int coluna) {
    return (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10);
}

// Conta bombas nas 4 células vizinhas (cima, baixo, esquerda, direita)
int Tabuleiro::contaBombaViz(int linha, int coluna) {
    int quantidade = 0;
    if(coordenadaValida(linha-1, coluna) && tabuleiro[linha-1][coluna].temBomba()) quantidade++;
    if(coordenadaValida(linha+1, coluna) && tabuleiro[linha+1][coluna].temBomba()) quantidade++;
    if(coordenadaValida(linha, coluna+1) && tabuleiro[linha][coluna+1].temBomba()) quantidade++;
    if(coordenadaValida(linha, coluna-1) && tabuleiro[linha][coluna-1].temBomba()) quantidade++;
    return quantidade;
}

// Calcula bombas vizinhas para todas as células
int Tabuleiro::insereBombasViz() {
    int totalBombas = 0;
    for(int l = 0; l < 10; l++) {
        for(int c = 0; c < 10; c++) {
            int vizinhos = contaBombaViz(l, c);
            tabuleiro[l][c].definirVizinhos(vizinhos);
            if(tabuleiro[l][c].temBomba()) totalBombas++;
        }
    }
    return totalBombas;
}

// Exibe o tabuleiro no console
void Tabuleiro::imprimir() {
    cout << "\n\n\t    ";
    for(int l = 0; l < 10; l++)
        cout << " " << l << "  ";
    cout << "\n\t   -----------------------------------------\n";

    for(int l = 0; l < 10; l++) {
        cout << "\t" << l << "  |";
        for(int c = 0; c < 10; c++) {
            if(tabuleiro[l][c].estaAberta()) {
                if(tabuleiro[l][c].temBomba())
                    cout << " * ";
                else
                    cout << " " << tabuleiro[l][c].quantidadeVizinhos() << " ";
            } else {
                cout << "   ";
            }
            cout << "|";
        }
        cout << "\n\t   -----------------------------------------\n";
    }
}

// Retorna referência a uma célula específica
Celula& Tabuleiro::acessaCelula(int linha, int coluna) {
    return tabuleiro[linha][coluna];
}
