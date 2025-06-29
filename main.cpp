#include <iostream>
#include "Jogo.h"
#include<string>
using namespace std;

int main() {
    int opcao;
    do {
        Jogo novo;
        string resultado= novo.play();
        cout<< resultado<< endl;
        cout << "\nDigite 1 para jogar novamente:";
        cin>> opcao;
    }while (opcao==1);
    return 0;
}
