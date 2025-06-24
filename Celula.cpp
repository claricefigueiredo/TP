#include "Celula.h"


Celula::Celula() : bomba(0), aberto(0), vizinhos(0) {
}


bool Celula::temBomba() {
    return bomba;
}

bool Celula::taAberto() {
    return aberto;
}

int Celula::qntVizinhos() {
    return vizinhos;
}


bool Celula::colocaBomba() {
    bomba = true;
}

bool Celula::abrir() {
    aberto = true;
}

int Celula::colocaVizinhos(int qntV) {
    vizinhos = qntV;
}


Celula::~Celula() {
}


