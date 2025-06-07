#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "velha.hpp"
#include <vector>
using namespace std;

TEST_CASE( "Vitoria do X", "[velha]" ) {
    vector<vector<int>> tabuleiro = {
        {1, 1, 1},
        {2, 2, 0},
        {0, 0, 0}
    };
    REQUIRE( verifica_resultado(tabuleiro) == 1);
}