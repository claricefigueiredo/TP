#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Celula {
private:
    bool bomba;
    bool aberta;
    int vizinhos;

public:
    Celula() : bomba(false), aberta(false), vizinhos(0) {}

    bool temBomba() const { return bomba; }
    bool estaAberta() const { return aberta; }
    int getVizinhos() const { return vizinhos; }

    void colocarBomba() { bomba = true; }
    void abrir() { aberta = true; }
    void setVizinhos(int v) { vizinhos = v; }
};

class Tabuleiro {
private:
    vector<vector<Celula>> grade;
    int tamanho;
    int totalBombas;

    bool coordenadaEhValida(int l, int c) const {
        return l >= 0 && l < tamanho && c >= 0 && c < tamanho;
    }

    int contarBombasVizinhas(int l, int c) const {
        int cont = 0;
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nl = l + dx[i], nc = c + dy[i];
            if (coordenadaEhValida(nl, nc) && grade[nl][nc].temBomba())
                cont++;
        }
        return cont;
    }

    void abrirCelulaRecursivo(int l, int c) {
        if (!coordenadaEhValida(l, c) || grade[l][c].estaAberta())
            return;

        grade[l][c].abrir();

        if (grade[l][c].getVizinhos() == 0 && !grade[l][c].temBomba()) {
            abrirCelulaRecursivo(l - 1, c);
            abrirCelulaRecursivo(l + 1, c);
            abrirCelulaRecursivo(l, c - 1);
            abrirCelulaRecursivo(l, c + 1);
        }
    }

public:
    Tabuleiro(int t, int b) : tamanho(t), totalBombas(b) {
        grade.resize(tamanho, vector<Celula>(tamanho));
    }

    void inicializar() {
        srand(time(NULL));
        int bombasColocadas = 0;

        // limpar o tabuleiro
        for (int i = 0; i < tamanho; i++)
            for (int j = 0; j < tamanho; j++)
                grade[i][j] = Celula();

        // sortear bombas
        while (bombasColocadas < totalBombas) {
            int l = rand() % tamanho;
            int c = rand() % tamanho;

            if (!grade[l][c].temBomba()) {
                grade[l][c].colocarBomba();
                bombasColocadas++;
            }
        }

        // contar bombas vizinhas
        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) {
                grade[i][j].setVizinhos(contarBombasVizinhas(i, j));
            }
        }
    }

    void imprimir() const {
        cout << "\n\t    ";
        for (int i = 0; i < tamanho; i++) cout << " " << i << "  ";
        cout << "\n\t   " << string(4 * tamanho + 1, '-') << "\n";

        for (int i = 0; i < tamanho; i++) {
            cout << "\t" << i << " |";
            for (int j = 0; j < tamanho; j++) {
                if (grade[i][j].estaAberta()) {
                    if (grade[i][j].temBomba())
                        cout << " * ";
                    else
                        cout << " " << grade[i][j].getVizinhos() << " ";
                } else {
                    cout << "   ";
                }
                cout << "|";
            }
            cout << "\n\t   " << string(4 * tamanho + 1, '-') << "\n";
        }
    }

    void abrirCelula(int l, int c) {
        abrirCelulaRecursivo(l, c);
    }

    bool celulaTemBomba(int l, int c) const {
        return grade[l][c].temBomba();
    }

    bool celulaAberta(int l, int c) const {
        return grade[l][c].estaAberta();
    }

    bool ganhou() const {
        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) {
                if (!grade[i][j].temBomba() && !grade[i][j].estaAberta())
                    return false;
            }
        }
        return true;
    }

    bool coordenadaValida(int l, int c) const {
        return coordenadaEhValida(l, c);
    }
};

class Jogo {
private:
    Tabuleiro tabuleiro;
    int tamanho;
    int bombas;

public:
    Jogo(int t, int b) : tabuleiro(t, b), tamanho(t), bombas(b) {}

    void executar() {
        int opcao;
        do {
            tabuleiro.inicializar();
            cout << "\n\t\t\tCAMPO MINADO\n";

            int linha, coluna;
            do {
                tabuleiro.imprimir();
                do {
                    cout << "\nDigite linha e coluna: ";
                    cin >> linha >> coluna;
                    if (!tabuleiro.coordenadaValida(linha, coluna) || tabuleiro.celulaAberta(linha, coluna))
                        cout << "Coordenada inválida ou já aberta.\n";
                } while (!tabuleiro.coordenadaValida(linha, coluna) || tabuleiro.celulaAberta(linha, coluna));

                tabuleiro.abrirCelula(linha, coluna);

            } while (!tabuleiro.ganhou() && !tabuleiro.celulaTemBomba(linha, coluna));

            tabuleiro.imprimir();
            if (tabuleiro.celulaTemBomba(linha, coluna))
                cout << "\n\tQue pena! Você perdeu!\n";
            else
                cout << "\n\tParabéns! Você ganhou!\n";

            cout << "\nDigite 1 para jogar novamente: ";
            cin >> opcao;
        } while (opcao == 1);
    }
};

int main() {
    Jogo jogo(10, 20);
    jogo.executar();
    return 0;
}

