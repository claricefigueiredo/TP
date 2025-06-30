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
            if(tabuleiro.acessaCelula(linha,coluna).taAberto()==false && 
               tabuleiro.acessaCelula(linha,coluna).temBomba() == false &&
               !tabuleiro.acessaCelula(linha,coluna).temBandeira())
                quantidade++;
        }
    }
    return quantidade;
}



string Jogo::play(){
    int linha, coluna, acao;
    bool perdeu=false;
    do{
        tabuleiro.imprimir();
        do{
            cout<< endl;
            cout<< "Digite 0 para colocar/remover bandeira ou 1 para abrir uma célula: ";
            cin>> acao;
            if(cin.fail() || (acao != 0 && acao != 1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida! Digite 0 ou 1." << endl;
                continue;
            }
            
            cout<< "Digite as coordenadas de linha e coluna: ";
            cin>> linha>> coluna;
            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida! Digite dois números." << endl;
                continue;
            }
            if(tabuleiro.coordenadaValida(linha-1, coluna-1) == false || 
              (acao == 1 && tabuleiro.acessaCelula(linha-1,coluna-1).taAberto()) ||
              (acao == 1 && tabuleiro.acessaCelula(linha-1,coluna-1).temBandeira()))
                cout<< endl<< "Coordenada inválida, já está aberta ou tem bandeira" << endl;
    
        }while(tabuleiro.coordenadaValida(linha-1, coluna-1) == false || 
              (acao == 1 && tabuleiro.acessaCelula(linha-1,coluna-1).taAberto()) ||
              (acao == 1 && tabuleiro.acessaCelula(linha-1,coluna-1).temBandeira()));

        if(acao == 0) {
            // Toggle flag
            tabuleiro.acessaCelula(linha-1, coluna-1).alternaBandeira();
        } else {
            // Open cell
            if (!tabuleiro.acessaCelula(linha-1, coluna-1).temBomba() && 
                tabuleiro.acessaCelula(linha-1, coluna-1).qntVizinhos() == 0) {
                tabuleiro.abreZeros(linha-1, coluna-1);
            }

            tabuleiro.acessaCelula(linha-1, coluna-1).abrir();
            if (tabuleiro.acessaCelula(linha - 1, coluna - 1).temBomba()) {
                perdeu = true;
            }
        }
       
    }while(Venceu() != 0 && !perdeu);

    tabuleiro.imprimir();
    if(perdeu)
        return "\nVoce perdeu!!! Mais sorte da próxima vez!!";
    else
        return "\nVOCÊ GANHOU!!! PARABÉNS!!";
}

