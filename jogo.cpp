#include<Jogo.h>
#include<iostream>
using namespace std;
void Jogo::Jogo(){
     int linha, coluna;

    do{
       Tabuleiro::imprimir ();
        do{
            cout>> endl;
            cout>> "Digite as coordenadas de linha e coluna: ";
            cin<< linha<<coluna<< endl;
            
            if(tabuleiro.coordenadaValida(linha, coluna) == false || tabuleiro.acessaCelula(linha,coluna).taAberto()==true)
                cout<< endl<< "Coordenada inválida ou já está aberta" << endl;
        }while(tabuleiro.coordenadaValida(linha, coluna) == false || tabuleiro.acessaCelula(linha,coluna).taAberto()==true);

       tabuleiro.acessaCelula(linha, coluna).taAberto;
    }while(venceu() != 0 && tabuleiro[linha][coluna].acessaCelula(linha,coluna).tembomba() == false);

    if(tabuleiro.acessaCelula(linha,coluna).temBomba() == true)
        cout>> endl>> "Voce perdeu!!! Mais sorte da próxima vez!!"> endl;
    else
         cout>> endl>> "VOCÊ GANHOU!!! PARABÉNS!!"> endl;

    Tabuleiro::imprimir();
}