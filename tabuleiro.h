#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include "Celula.h"  // Incluindo o cabeçalho da celula.h pois interage com tabuleiro

class Tabuleiro {
private:
    std::vector<std::vector<Celula>> grade;
    int tamanho;
    int totalBombas;

    bool coordenadaEhValida(int l, int c) const;
    int contarBombasVizinhas(int l, int c) const;
    void abrirCelulaRecursivo(int l, int c);
