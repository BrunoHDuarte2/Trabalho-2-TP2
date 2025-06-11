// Copyright 2025 Bruno Henrique Duarte
#include "velha.hpp"
#include <vector>
using std::vector;
bool valida_linha_player(vector<vector<int>> tabuleiro, int player) {
    bool primeiraLinha = (tabuleiro[0][0] == player)&&
                        (tabuleiro[0][1] == player)&&
                        (tabuleiro[0][2] == player);
    bool segundaLinha = (tabuleiro[1][0] == player)&&
                        (tabuleiro[1][1] == player)&&
                        (tabuleiro[1][2] == player);
    bool terceiraLinha = (tabuleiro[2][0] == player)&&
                        (tabuleiro[2][1] == player)&&
                        (tabuleiro[2][2] == player);
    return primeiraLinha || segundaLinha || terceiraLinha;
}
bool valida_coluna_player(vector<vector<int>> tabuleiro, int player) {
    bool primeiraColuna = (tabuleiro[0][0] == player)&&
                        (tabuleiro[1][0] == player)&&
                        (tabuleiro[2][0] == player);
    bool segundaColuna = (tabuleiro[0][1] == player)&&
                        (tabuleiro[1][1] == player)&&
                        (tabuleiro[2][1] == player);
    bool terceiraColuna = (tabuleiro[0][2] == player)&&
                        (tabuleiro[1][2] == player)&&
                        (tabuleiro[2][2] == player);
    return primeiraColuna || segundaColuna || terceiraColuna;
}
bool valida_diagonal_principal_player(vector<vector<int>> tabuleiro, int player) {
    return (tabuleiro[0][0] == player)&&
            (tabuleiro[1][1] == player)&&
            (tabuleiro[2][2] == player);
}
bool valida_diagonal_secundaria_player(vector<vector<int>> tabuleiro, int player) {
    return (tabuleiro[0][2] == player) &&
            (tabuleiro[1][1] == player) &&
            (tabuleiro[2][0] == player);
}
/*
    empate  <- estado do jogo da velha.
    Verifica se todos as posições foram preenchidas, supondo que X sempre começa.
*/
bool empate(vector<vector<int>> tabuleiro) {
    int numX = 0;
    int numO = 0;
    for (int i=0; i < 3; i++) {
        for (int j=0 ; j < 3 ; j++) {
            if ( tabuleiro[i][j] == 1 ) {
                numX++;
            }
            if ( tabuleiro[i][j] == 2 ) {
                numO++;
            }
        }
    }
    // Caso onde o tabuleiro está completo:
    // Já que ninguém venceu e o tabuleiro está completo -> Empate
    return (numX == 5)&&(numO == 4);
}
bool impossivel(vector<vector<int>> tabuleiro) {
    int numX = 0;
    int numO = 0;
    for (int i = 0; i < tabuleiro.size(); i++) {
        for (int j = 0; j < tabuleiro.size(); j++) {
            if ( tabuleiro[i][j] == 1 ) {
                numX++;
            }
            if ( tabuleiro[i][j] == 2 ) {
                numO++;
            }
        }
    }
    // Casos:
    // Jogador X jogou mais vezes que o jogador O
    // Jogador O jogou mais vezes que o jogador X
    return (numX > numO+1) || (numX < numO);
}
int verifica_resultado(const vector<vector<int>> tabuleiro) {
    if ( impossivel(tabuleiro) ) {
        return -2;
    }
    bool linhaDeX = valida_linha_player(tabuleiro, 1);
    bool colunaDeX = valida_coluna_player(tabuleiro, 1);
    bool diagonalPDeX = valida_diagonal_principal_player(tabuleiro, 1);
    bool diagonalSDeX = valida_diagonal_secundaria_player(tabuleiro, 1);
    if ( linhaDeX || colunaDeX || diagonalPDeX || diagonalSDeX ) {
        return 1;
    }
    bool linhaDeO = valida_linha_player(tabuleiro, 2);
    bool colunaDeO = valida_coluna_player(tabuleiro, 2);
    bool diagonalPDeO = valida_diagonal_principal_player(tabuleiro, 2);
    bool diagonalSDeO = valida_diagonal_secundaria_player(tabuleiro, 2);
    if ( linhaDeO || colunaDeO || diagonalPDeO || diagonalSDeO ) {
        return 2;
    }
    if ( empate(tabuleiro) ) return 0;
    else return -1;
}
