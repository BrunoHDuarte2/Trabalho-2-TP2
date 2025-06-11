// Copyright 2025 Bruno Henrique Duarte
/**
 * @file test.cpp
 * @brief Implementa a lógica de verificação do jogo da velha.
 * 
 * Contém funções auxiliares para validar vitórias em linhas, colunas e diagonais,
 * além de verificar empate e situações impossíveis de acontecer no jogo.
 * 
 * @author Bruno Henrique Duarte
 * @date 2025
 */
#include "velha.hpp"
#include <vector>
using std::vector;

/**
 * @brief Verifica se o jogador venceu em alguma linha.
 * 
 * @param tabuleiro Matriz 3x3 representando o estado do jogo.
 * @param player Inteiro representando o jogador (1 para X, 2 para O).
 * @return true se o jogador venceu em alguma linha, false caso contrário.
 */
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

/**
 * @brief Verifica se o jogador venceu em alguma coluna.
 * 
 * @param tabuleiro Matriz 3x3 representando o estado do jogo.
 * @param player Inteiro representando o jogador (1 para X, 2 para O).
 * @return true se o jogador venceu em alguma coluna, false caso contrário.
 */
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


/**
 * @brief Verifica se o jogador venceu na diagonal principal.
 * 
 * @param tabuleiro Matriz 3x3 representando o estado do jogo.
 * @param player Inteiro representando o jogador (1 para X, 2 para O).
 * @return true se o jogador venceu na diagonal principal, false caso contrário.
 */
bool valida_diagonal_principal_player(vector<vector<int>> tabuleiro, int player) {
    return (tabuleiro[0][0] == player)&&
            (tabuleiro[1][1] == player)&&
            (tabuleiro[2][2] == player);
}

/**
 * @brief Verifica se o jogador venceu na diagonal secundária.
 * 
 * @param tabuleiro Matriz 3x3 representando o estado do jogo.
 * @param player Inteiro representando o jogador (1 para X, 2 para O).
 * @return true se o jogador venceu na diagonal secundária, false caso contrário.
 */
bool valida_diagonal_secundaria_player(vector<vector<int>> tabuleiro, int player) {
    return (tabuleiro[0][2] == player) &&
            (tabuleiro[1][1] == player) &&
            (tabuleiro[2][0] == player);
}

/**
 * @brief Verifica se o jogo terminou em empate.
 * 
 * Considera que o jogador X sempre inicia, então empate ocorre com 5 jogadas de X e 4 de O,
 * sem que nenhum tenha vencido.
 * 
 * @param tabuleiro Matriz 3x3 representando o estado do jogo.
 * @return true se o jogo terminou empatado, false caso contrário.
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
    return (numX == 5)&&(numO == 4);
}

/**
 * @brief Verifica se o estado atual do jogo é impossível.
 * 
 * Situações impossíveis incluem: X jogou mais de uma vez a mais que O, ou O jogou mais que X.
 * 
 * @param tabuleiro Matriz 3x3 representando o estado do jogo.
 * @return true se o estado do tabuleiro é impossível, false caso contrário.
 */
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
    return (numX > numO+1) || (numX < numO);
}

/**
 * @brief Verifica o resultado do jogo da velha.
 * 
 * @param tabuleiro Matriz 3x3 representando o estado do jogo.
 * @return int Resultado do jogo:
 * - -2: estado impossível
 * - -1: jogo em andamento
 * -  0: empate
 * -  1: vitória do jogador X
 * -  2: vitória do jogador O
 */
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
