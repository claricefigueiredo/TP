#include "Celula.h"


Celula::Celula() : bomba(false), aberto(false), vizinhos(0) {
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


void Celula::colocaBomba() {
    bomba = true;
}

void Celula::abrir() {
    aberto = true;
}

void Celula::alternaBandeira() {
    bandeira = !bandeira;
}

void Celula::colocaVizinhos(int qntV) {
    vizinhos = qntV;
}


Celula::~Celula() {
}


