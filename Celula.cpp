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


bool Celula::colocaBomba() {}

bool Celula::abrir() {}

int Celula::colocaVizinhos(int qntV) {}


Celula::~Celula() {}


