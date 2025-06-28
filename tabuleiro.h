#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include "Celula.h"  // Incluindo o cabeçalho da celula.h pois interage com tabuleiro

class Tabuleiro {
private:
    std::vector<std::vector<Celula>> grade;  // Matriz de células que forma o tabuleiro
    int tamanho;                             // Tamanho do tabuleiro (tamanho x tamanho)
    int totalBombas;                         // Número total de bombas no tabuleiro

    //Verifica se as coordenadas estão dentro dos limites do tabuleiro
    bool coordenadaEhValida(int l, int c) const;
    
    //Conta quantas bombas existem nas células vizinhas à posição (l,c)
    int contarBombasVizinhas(int l, int c) const;
    
    //Abre a célula e, se for vazia, abre recursivamente as vizinhas
    void abrirCelulaRecursivo(int l, int c);

public:
    //Cria um tabuleiro com tamanho t e b bombas
    Tabuleiro(int t, int b);
    
    //Inicializa o tabuleiro: coloca bombas e calcula vizinhos
    void inicializar();
    
    //Imprime o tabuleiro no console, mostrando células abertas
    void imprimir() const;
    
    //Abre a célula na posição (l,c) (interface pública para a abertura)
    void abrirCelula(int l, int c);
    
    //Retorna true se a célula (l,c) contém uma bomba
    bool celulaTemBomba(int l, int c) const;
    
    //Retorna true se a célula (l,c) já foi aberta
    bool celulaAberta(int l, int c) const;
    
    //Verifica se o jogador ganhou (todas células sem bomba abertas)
    bool ganhou() const;
    
    //Verifica se as coordenadas (l,c) são válidas no tabuleiro
    bool coordenadaValida(int l, int c) const;
};

#endif
