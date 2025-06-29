#ifndef CELULA_H
#define CELULA_H

#include <iostream>

class Celula {
    private:
        bool bomba;
        bool aberto;
        int vizinhos;
    public:
        //Cria uma célula sem bombas, fechada e com 0 vizinhos
        Celula();

        //Retorna se na célula tem uma bomba
        bool temBomba();
        //REtorna se a célula já foi aberta
        bool taAberto();
        //Retorna a quantidade de vizinhos
        int qntVizinhos();

        //Adiciona uma bomba a célula
        void colocaBomba();
        //Abre a célula
        void abrir();
        //Insere a quantidade de vizinhos da célula
        void colocaVizinhos(int qntV);

        //Destrutor
        ~Celula();
};

#endif //CELULA_H
