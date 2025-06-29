#include"Jogo.h"
#include<iostream>
#include<string>
#include <limits>
using namespace std;
Jogo::Jogo(){
   tabuleiro.iniciaTabuleiro();
   tabuleiro.sorteiaBombas(20);
    tabuleiro.insereBombasViz();
}
int Jogo::Venceu(){
  int quantidade = 0;

    for(int linha = 0; linha < 10; linha++){
        for(int coluna = 0; coluna < 10; coluna++){
            if(tabuleiro.acessaCelula(linha,coluna).taAberto()==false && tabuleiro.acessaCelula(linha,coluna).temBomba() == false)
                quantidade++;
        }
    }
    return quantidade;
}



 string Jogo::play(){
     int linha, coluna;
    bool perdeu=false;
    do{
       tabuleiro.imprimir ();
        do{
            cout<< endl;
            cout<< "Digite as coordenadas de linha e coluna: ";
            cin>> linha>> coluna;
            if(cin.fail()) {
            cin.clear();
           cin.ignore(numeric_limits<streamsize>::max(), '\n');
           cout << "Entrada inválida! Digite dois números." << endl;
           continue;
            }
            if(tabuleiro.coordenadaValida(linha-1, coluna-1) == false || tabuleiro.acessaCelula(linha-1,coluna-1).taAberto()==true)
                cout<< endl<< "Coordenada inválida ou já está aberta" << endl;
    
        }while(tabuleiro.coordenadaValida(linha-1, coluna-1) == false || tabuleiro.acessaCelula(linha-1,coluna-1).taAberto()==true);

       tabuleiro.acessaCelula(linha-1, coluna-1).abrir();
       if (tabuleiro.acessaCelula(linha - 1, coluna - 1).temBomba()) {
            perdeu = true;
        }
       

       
    }while(Venceu() != 0 && !perdeu);

    
    tabuleiro.imprimir();
     if(perdeu)
        return "\nVoce perdeu!!! Mais sorte da próxima vez!!";
        else
         return "\nVOCÊ GANHOU!!! PARABÉNS!!";
}

