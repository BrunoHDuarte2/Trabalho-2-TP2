#include "velha.hpp"
#include <vector>
using namespace std;
bool valida_linha_X(vector<vector<int>> tabuleiro){
    bool primeiraLinha = (tabuleiro[0][0] == 1)&&(tabuleiro[0][1] == 1)&&(tabuleiro[0][2] == 1);
    bool segundaLinha = (tabuleiro[1][0] == 1)&&(tabuleiro[1][1] == 1)&&(tabuleiro[1][2] == 1);
    bool terceiraLinha = (tabuleiro[2][0] == 1)&&(tabuleiro[2][1] == 1)&&(tabuleiro[2][2] == 1);
    return primeiraLinha||segundaLinha||terceiraLinha;
}
bool valida_linha_O(vector<vector<int>> tabuleiro){
    bool primeiraLinha = (tabuleiro[0][0] == 2)&&(tabuleiro[0][1] == 2)&&(tabuleiro[0][2] == 2);
    bool segundaLinha = (tabuleiro[1][0] == 2)&&(tabuleiro[1][1] == 2)&&(tabuleiro[1][2] == 2);
    bool terceiraLinha = (tabuleiro[2][0] == 2)&&(tabuleiro[2][1] == 2)&&(tabuleiro[2][2] == 2);
    return primeiraLinha||segundaLinha||terceiraLinha;
}
bool valida_coluna_X(vector<vector<int>> tabuleiro){
    bool primeiraColuna = (tabuleiro[0][0] == 1)&&(tabuleiro[1][0] == 1)&&(tabuleiro[2][0] == 1);
    bool segundaColuna = (tabuleiro[0][1] == 1)&&(tabuleiro[1][1] == 1)&&(tabuleiro[2][1] == 1);
    bool terceiraColuna = (tabuleiro[0][2] == 1)&&(tabuleiro[1][2] == 1)&&(tabuleiro[2][2] == 1);
    return primeiraColuna||segundaColuna||terceiraColuna;
}
bool valida_coluna_O(vector<vector<int>> tabuleiro){
    bool primeiraColuna = (tabuleiro[0][0] == 2)&&(tabuleiro[1][0] == 2)&&(tabuleiro[2][0] == 2);
    bool segundaColuna = (tabuleiro[0][1] == 2)&&(tabuleiro[1][1] == 2)&&(tabuleiro[2][1] == 2);
    bool terceiraColuna = (tabuleiro[0][2] == 2)&&(tabuleiro[1][2] == 2)&&(tabuleiro[2][2] == 2);
    return primeiraColuna||segundaColuna||terceiraColuna;
}
int verifica_resultado(const vector<vector<int>> tabuleiro)
{
    bool linhaDeX = valida_linha_X(tabuleiro);
    bool colunaDeX = valida_coluna_X(tabuleiro);
    if(linhaDeX||colunaDeX){
        return 1;
    }
    bool linhaDeO = valida_linha_O(tabuleiro);
    bool colunaDeO = valida_coluna_O(tabuleiro);
    if(linhaDeO||colunaDeO){
        return 2;
    }
    return 0;
}