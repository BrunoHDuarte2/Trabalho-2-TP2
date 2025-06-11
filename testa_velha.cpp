/**
 * @file test_velha.cpp
 * @brief Arquivo de testes para a função verifica_resultado do jogo da velha.
 *
 * Este arquivo contém diversos cenários de teste para verificar o funcionamento da função
 * `verifica_resultado`, que avalia o estado do tabuleiro do jogo da velha e retorna:
 * - 1: Vitória do jogador X
 * - 2: Vitória do jogador O
 * - 0: Empate
 * - -1: Jogo indefinido (incompleto)
 * - -2: Estado inválido/impossível
 */

#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "velha.hpp"
#include <vector>
using std::vector;

/**
 * @test Verifica vitória do jogador X por linha.
 */
TEST_CASE( "Vitoria do X Linha", "[velha]" ) {
    vector<vector<int>> tabuleiro = {
        {1, 1, 1},
        {2, 2, 0},
        {0, 0, 0}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 1);
    tabuleiro = {
        {0, 2, 2},
        {1, 1, 1},
        {0, 0, 0}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 1);
    tabuleiro = {
        {0, 2, 2},
        {0, 0, 0},
        {1, 1, 1}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 1);
}

/**
 * @test Verifica vitória do jogador X por coluna.
 */
TEST_CASE( "Vitoria do X Coluna", "[velha]" ) {
    vector<vector<int>> tabuleiro = {
        {1, 0, 2},
        {1, 2, 0},
        {1, 0, 0}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 1);
    tabuleiro = {
        {2, 1, 2},
        {0, 1, 0},
        {0, 1, 0}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 1);
    tabuleiro = {
        {0, 2, 1},
        {0, 0, 1},
        {0, 2, 1}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 1);
}

/**
 * @test Verifica vitória do jogador X por diagonal principal.
 */
TEST_CASE( "Vitoria do X Diagonal principal", "[velha]" ) {
    vector<vector<int>> tabuleiro = {
        {1, 0, 0},
        {2, 1, 2},
        {0, 0, 1}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 1);
    tabuleiro = {
        {1, 2, 0},
        {1, 1, 2},
        {2, 2, 1}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 1);
    tabuleiro = {
        {1, 2, 2},
        {0, 1, 0},
        {2, 1, 1}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 1);
}

/**
 * @test Verifica vitória do jogador X por diagonal secundária.
 */
TEST_CASE( "Vitoria do X Diagonal secundária", "[velha]" ) {
    vector<vector<int>> tabuleiro = {
        {0, 0, 1},
        {2, 1, 2},
        {1, 0, 0}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 1);
    tabuleiro = {
        {2, 2, 1},
        {1, 1, 2},
        {1, 2, 0}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 1);
    tabuleiro = {
        {2, 2, 1},
        {0, 1, 0},
        {1, 1, 2}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 1);
}

/**
 * @test Verifica vitória do jogador O por linha.
 */
TEST_CASE( "Vitoria do O Linha", "[velha]" ) {
    vector<vector<int>> tabuleiro = {
        {2, 2, 2},
        {1, 0, 1},
        {0, 1, 0}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 2);
    tabuleiro = {
        {1, 0, 1},
        {2, 2, 2},
        {0, 1, 0}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 2);
    tabuleiro = {
        {0, 1, 1},
        {0, 0, 1},
        {2, 2, 2}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 2);
}

/**
 * @test Verifica vitória do jogador O por coluna.
 */
TEST_CASE( "Vitoria do O Coluna", "[velha]" ) {
    vector<vector<int>> tabuleiro = {
        {2, 1, 0},
        {2, 0, 1},
        {2, 1, 0}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 2);
    tabuleiro = {
        {1, 2, 0},
        {1, 2, 1},
        {0, 2, 0}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 2);
    tabuleiro = {
        {0, 1, 2},
        {1, 0, 2},
        {0, 1, 2}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 2);
}

/**
 * @test Verifica vitória do jogador O por diagonal principal.
 */
TEST_CASE( "Vitoria do O Diagonal principal", "[velha]" ) {
    vector<vector<int>> tabuleiro = {
        {2, 0, 0},
        {1, 2, 1},
        {0, 1, 2}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 2);
    tabuleiro = {
        {2, 1, 0},
        {0, 2, 1},
        {0, 1, 2}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 2);
    tabuleiro = {
        {2, 1, 1},
        {0, 2, 0},
        {0, 1, 2}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 2);
}

/**
 * @test Verifica vitória do jogador X por diagonal secundária.
 */
TEST_CASE( "Vitoria do O Diagonal secundaria", "[velha]" ) {
    vector<vector<int>> tabuleiro = {
        {0, 0, 2},
        {1, 2, 1},
        {2, 1, 0}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 2);
    tabuleiro = {
        {0, 1, 2},
        {0, 2, 1},
        {2, 1, 0}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 2);
    tabuleiro = {
        {0, 1, 2},
        {0, 2, 0},
        {2, 1, 1}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 2);
}

/**
 * @test Verifica empate dos jogadores.
 */
TEST_CASE( "Empate", "[velha]" ) {
    vector<vector<int>> tabuleiro = {
        {2, 1, 1},
        {1, 2, 2},
        {2, 1, 1}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 0);
    tabuleiro = {
        {1, 2, 1},
        {1, 2, 1},
        {2, 1, 2}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 0);
    tabuleiro = {
        {2, 1, 1},
        {1, 2, 2},
        {2, 1, 1}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 0);
}

/**
 * @test Verifica que o estado do jogo não é nem de vitória, nem de empate.
 */
TEST_CASE( "Indefinido", "[velha]" ) {
    vector<vector<int>> tabuleiro = {
        {2, 0, 0},
        {1, 2, 1},
        {2, 1, 1}
    };
    REQUIRE( verifica_resultado(tabuleiro) == -1);
    tabuleiro = {
        {1, 2, 1},
        {0, 2, 1},
        {2, 1, 2}
    };
    REQUIRE( verifica_resultado(tabuleiro) == -1);
    tabuleiro = {
        {1, 1, 2},
        {1, 1, 2},
        {2, 2, 0}
    };
    REQUIRE( verifica_resultado(tabuleiro) == -1);
}

/**
 * @test Verifica que o resultado do jogo é impossível pelas regras.
 */
TEST_CASE( "Impossível", "[velha]" ) {
    vector<vector<int>> tabuleiro = {
        {2, 1, 1},
        {1, 1, 1},
        {2, 1, 1}
    };
    REQUIRE( verifica_resultado(tabuleiro) == -2);
    tabuleiro = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    REQUIRE( verifica_resultado(tabuleiro) == -2);
    tabuleiro = {
        {1, 2, 2},
        {1, 2, 2},
        {2, 2, 0}
    };
    REQUIRE( verifica_resultado(tabuleiro) == -2);
}

