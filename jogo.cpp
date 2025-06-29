#include"Jogo.h"
#include<iostream>
#include<string>
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


 void Jogo::play(){
     int linha, coluna;

    do{
       tabuleiro.imprimir ();
        do{
            cout<< endl;
            cout<< "Digite as coordenadas de linha e coluna: ";
            cin>> linha>> coluna>> endl;
            
            if(tabuleiro.coordenadaValida(linha, coluna) == false || tabuleiro.acessaCelula(linha,coluna).taAberto()==true)
                cout<< endl<< "Coordenada inválida ou já está aberta" << endl;
        }while(tabuleiro.coordenadaValida(linha, coluna) == false || tabuleiro.acessaCelula(linha,coluna).taAberto()==true);

       tabuleiro.acessaCelula(linha, coluna).abrir();
    }while(Venceu() != 0 && tabuleiro.acessaCelula(linha,coluna).temBomba() == false);

    if(tabuleiro.acessaCelula(linha,coluna).temBomba() == true)
        cout<< endl<< "Voce perdeu!!! Mais sorte da próxima vez!!"<< endl;
    else
         cout<< endl<< "VOCÊ GANHOU!!! PARABÉNS!!"<< endl;

    tabuleiro.imprimir();
}
