#include "velha.hpp"
#include <vector>
using namespace std;
/*
    valida_linha_X  <- estado do jogo da velha
    verifica se ocorre tres 1's consecutivos em alguma das linhas.
*/
bool valida_linha_X(vector<vector<int>> tabuleiro){
    bool primeiraLinha = (tabuleiro[0][0] == 1)&&(tabuleiro[0][1] == 1)&&(tabuleiro[0][2] == 1);
    bool segundaLinha = (tabuleiro[1][0] == 1)&&(tabuleiro[1][1] == 1)&&(tabuleiro[1][2] == 1);
    bool terceiraLinha = (tabuleiro[2][0] == 1)&&(tabuleiro[2][1] == 1)&&(tabuleiro[2][2] == 1);
    return primeiraLinha||segundaLinha||terceiraLinha;
}
/*
    valida_linha_O  <- estado do jogo da velha
    verifica se ocorre tres 2's consecutivos em alguma das linhas.
*/
bool valida_linha_O(vector<vector<int>> tabuleiro){
    bool primeiraLinha = (tabuleiro[0][0] == 2)&&(tabuleiro[0][1] == 2)&&(tabuleiro[0][2] == 2);
    bool segundaLinha = (tabuleiro[1][0] == 2)&&(tabuleiro[1][1] == 2)&&(tabuleiro[1][2] == 2);
    bool terceiraLinha = (tabuleiro[2][0] == 2)&&(tabuleiro[2][1] == 2)&&(tabuleiro[2][2] == 2);
    return primeiraLinha||segundaLinha||terceiraLinha;
}
/*
    valida_coluna_X  <- estado do jogo da velha
    verifica se ocorre tres 1's consecutivos em alguma das colunas.
*/
bool valida_coluna_X(vector<vector<int>> tabuleiro){
    bool primeiraColuna = (tabuleiro[0][0] == 1)&&(tabuleiro[1][0] == 1)&&(tabuleiro[2][0] == 1);
    bool segundaColuna = (tabuleiro[0][1] == 1)&&(tabuleiro[1][1] == 1)&&(tabuleiro[2][1] == 1);
    bool terceiraColuna = (tabuleiro[0][2] == 1)&&(tabuleiro[1][2] == 1)&&(tabuleiro[2][2] == 1);
    return primeiraColuna||segundaColuna||terceiraColuna;
}
/*
    valida_coluna_X  <- estado do jogo da velha
    verifica se ocorre tres 2's consecutivos em alguma das colunas.
*/
bool valida_coluna_O(vector<vector<int>> tabuleiro){
    bool primeiraColuna = (tabuleiro[0][0] == 2)&&(tabuleiro[1][0] == 2)&&(tabuleiro[2][0] == 2);
    bool segundaColuna = (tabuleiro[0][1] == 2)&&(tabuleiro[1][1] == 2)&&(tabuleiro[2][1] == 2);
    bool terceiraColuna = (tabuleiro[0][2] == 2)&&(tabuleiro[1][2] == 2)&&(tabuleiro[2][2] == 2);
    return primeiraColuna||segundaColuna||terceiraColuna;
}
bool valida_diagonal_principal_X(vector<vector<int>> tabuleiro){
    return (tabuleiro[0][0]==1)&&(tabuleiro[1][1]==1)&&(tabuleiro[2][2]==1);
}
bool valida_diagonal_secundaria_X(vector<vector<int>> tabuleiro){
    return (tabuleiro[0][2]==1)&&(tabuleiro[1][1]==1)&&(tabuleiro[2][0]==1);
}
bool valida_diagonal_principal_O(vector<vector<int>> tabuleiro){
    return (tabuleiro[0][0]==2)&&(tabuleiro[1][1]==2)&&(tabuleiro[2][2]==2);
}
/*
    empate  <- estado do jogo da velha.
    Verifica se todos as posições foram preenchidas, supondo que X sempre começa.
*/
bool empate(vector<vector<int>> tabuleiro){
    int numX=0;
    int numO=0;
    for(int i=0; i<3;i++){
        for(int j=0; j<3;j++){
            if(tabuleiro[i][j]==1){
                numX++;
            } 
            if(tabuleiro[i][j]==2){
                numO++;
            } 
        }
    }
    // Caso onde o tabuleiro está completo, assim pode-se usar o resultado obtido anteriormente!
    // Já que ninguém venceu e o tabuleiro está completo -> Empate
    return (numX==5)&&(numO==4);
}
bool impossivel(vector<vector<int>> tabuleiro){
    int numX=0;
    int numO=0;
    for(int i=0; i<tabuleiro.size(); i++){
        for(int j=0; j<tabuleiro.size();j++){
            if(tabuleiro[i][j]==1){
                numX++;
            }
            if(tabuleiro[i][j]==2){
                numO++;
            }
        }
    }
    // Casos:
    // Jogador X jogou mais vezes que o jogador O
    // Jogador O jogou mais vezes que o jogador X
    return (numX>numO+1) || (numX<numO);
}
int verifica_resultado(const vector<vector<int>> tabuleiro)
{
    if(impossivel(tabuleiro)) {
        return -2;
    }
    bool linhaDeX = valida_linha_X(tabuleiro);
    bool colunaDeX = valida_coluna_X(tabuleiro);
    bool diagonalPDeX = valida_diagonal_principal_X(tabuleiro);
    bool diagonalSDeX = valida_diagonal_secundaria_X(tabuleiro);
    if(linhaDeX||colunaDeX||diagonalPDeX||diagonalSDeX){
        return 1;
    }
    bool linhaDeO = valida_linha_O(tabuleiro);
    bool colunaDeO = valida_coluna_O(tabuleiro);
    bool diagonalPDeO = valida_diagonal_principal_O(tabuleiro);
    if(linhaDeO||colunaDeO||diagonalPDeO){
        return 2;
    }
    if(empate(tabuleiro)){
        return 0;
    } else return -1;
    
}