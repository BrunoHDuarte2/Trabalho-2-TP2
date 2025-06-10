#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "velha.hpp"
#include <vector>
using namespace std;

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

