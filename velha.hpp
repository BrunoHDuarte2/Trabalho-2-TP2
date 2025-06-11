#include <vector>
using namespace std;
bool valida_linha_player(vector<vector<int>> tabuleiro, int player);
bool valida_coluna_player(vector<vector<int>> tabuleiro, int player);
bool valida_diagonal_principal_player(vector<vector<int>> tabuleiro, int player);
bool valida_diagonal_secundaria_player(vector<vector<int>> tabuleiro, int player);
bool empate(vector<vector<int>> tabuleiro);
bool impossivel(vector<vector<int>> tabuleiro);
int verifica_resultado(vector<vector<int>> tabuleiro);