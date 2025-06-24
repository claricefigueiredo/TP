#ifndef CELULA_H
#define CELULA_H

#include <iostream>

class Celula {
    private:
        bool bomba;
        bool aberto;
        bool vizinhos;
    public:
        //Cria uma célula sem bombas, fechada e com 0 vizinhos
        Celula();

        //Destrutor
        ~Celula();
};

#endif //CELULA_H
