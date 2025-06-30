#ifndef CELULA_H
#define CELULA_H

#include <iostream>

class Celula {
    private:
        bool bomba;
        bool aberto;
        int vizinhos;
        bool bandeira;
    public:
        //Cria uma célula sem bombas, fechada e com 0 vizinhos
        Celula();

        //Retorna se na célula tem uma bomba
        bool temBomba();
        //REtorna se a célula já foi aberta
        bool taAberto();
        //Retorna se a célula tem bandeira
        bool temBandeira();
        //Retorna a quantidade de vizinhos
        int qntVizinhos();

        //Adiciona uma bomba a célula
        void colocaBomba();
        //Abre a célula
        void abrir();
        //Alterna a bandeira (adiciona/remove)
        void alternaBandeira();
        //Insere a quantidade de vizinhos da célula
        void colocaVizinhos(int qntV);

        //Destrutor
        ~Celula();
};

#endif //CELULA_H
