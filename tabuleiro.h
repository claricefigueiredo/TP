#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "Celula.h"

class Tabuleiro {
private:
    Celula tabuleiro[10][10];  // Matriz 10x10 que representa o tabuleiro

public:
    // Preenche todas as células do tabuleiro como vazias
    void iniciaTabuleiro();
    
    // Distribui 'n' bombas em posições aleatórias
    void sorteiaBombas(int n);
    
    // Verifica se a posição está dentro dos limites do tabuleiro
    bool coordenadaValida(int linha, int coluna);
    
    // Conta quantas bombas existem nas células vizinhas à posição informada
    int contaBombaViz(int linha, int coluna);
    
    // Atualiza todas as células com a contagem de bombas vizinhas
    int insereBombasViz();
    
    // Abre células vazias adjacentes recursivamente (implementação no .cpp)
    void abreZeros(int linha, int coluna);
    
    // Exibe o tabuleiro atual no console
    void imprimir();
    
    // Retorna referência direta à célula na posição especificada
    Celula& acessaCelula(int linha, int coluna);
};

#endif // TABULEIRO_H
