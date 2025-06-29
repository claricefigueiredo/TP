#include "tabuleiro.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
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
            tabuleiro[l][c].colocaBomba();
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
            tabuleiro[l][c].colocaVizinhos(vizinhos);
            if(tabuleiro[l][c].temBomba()) totalBombas++;
        }
    }
    return totalBombas;
}

void Tabuleiro::abreZeros(int linha, int coluna) {
    // Verifica se a coordenada é inválida, se já está aberta ou tem bomba
    if(!coordenadaValida(linha, coluna) || 
       tabuleiro[linha][coluna].taAberto() || 
       tabuleiro[linha][coluna].temBomba()) {
        return;
    }

    // Abre a célula atual
    tabuleiro[linha][coluna].abrir();

    // Se não tem bombas vizinhas, abre recursivamente as adjacentes
    if(tabuleiro[linha][coluna].qntVizinhos() == 0) {
        abreZeros(linha-1, coluna);  // Cima
        abreZeros(linha+1, coluna);  // Baixo
        abreZeros(linha, coluna-1);  // Esquerda
        abreZeros(linha, coluna+1);  // Direita
    }
}

// Exibe o tabuleiro no console
void Tabuleiro::imprimir() {
    cout << "\n\n\t    ";
    for(int l = 0; l < 10; l++)
        cout << " " << l+1 << "  ";
    cout << "\n\t   -----------------------------------------\n";

    for(int l = 0; l < 10; l++) {
        cout << "\t" << l+1 << "  |";
        for(int c = 0; c < 10; c++) {
            if(tabuleiro[l][c].taAberto()) {
                if(tabuleiro[l][c].temBomba())
                    cout << " * ";
                else
                    cout << " " << tabuleiro[l][c].qntVizinhos() << " ";
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
