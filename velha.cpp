#include "velha.hpp"
#include <vector>
using namespace std;
bool valida_linha_X(vector<int> linha){
    int tamanhoLinha = linha.size();
    int qtdUns = 0;
    while(tamanhoLinha--){
        if(linha[tamanhoLinha] == 1){
            qtdUns++;
        }
    }
    return qtdUns == 3;
}
bool valida_coluna_X(vector<vector<int>> tabuleiro){
    bool primeiraColuna = (tabuleiro[0][0] == 1)&&(tabuleiro[1][0] == 1)&&(tabuleiro[2][0] == 1);
    bool segundaColuna = (tabuleiro[0][1] == 1)&&(tabuleiro[1][1] == 1)&&(tabuleiro[2][1] == 1);
    bool terceiraColuna = (tabuleiro[0][2] == 1)&&(tabuleiro[1][2] == 1)&&(tabuleiro[2][2] == 1);
    return primeiraColuna||segundaColuna||terceiraColuna;
}
int verifica_resultado(const vector<vector<int>> tabuleiro)
{
    bool linhaDeX = valida_linha_X(tabuleiro[0]) || valida_linha_X(tabuleiro[1]) || valida_linha_X(tabuleiro[2]);
    bool colunaDeX = valida_coluna_X(tabuleiro);
    if(linhaDeX||colunaDeX){
        return 1;
    }
    return 0;
}