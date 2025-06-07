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
int verifica_resultado(const vector<vector<int>> tabuleiro)
{
    bool linhaDeX = valida_linha_X(tabuleiro[0]) || valida_linha_X(tabuleiro[1]) || valida_linha_X(tabuleiro[2]);
    if(linhaDeX){
        return 1;
    }
    return 0;
}