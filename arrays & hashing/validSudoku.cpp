#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<int, unordered_set<char>> lines; // onde int será o índice da linha e o set guardará os números 
    unordered_map<int, unordered_set<char>> columns; // onde int será o índice da coluna e o set guardará os números 
    map<pair<int, int>, unordered_set<char>> grids; // receberá os números de cada seção 3x3, onde a chave será o par (linha_seção, coluna_seção)

    for (int i=0; i < board.size(); i++){ // percorrer o tabuleiro linha por linha
        for (int j=0; j < board[i].size(); j++){ // percorrer o tabuleiro coluna por coluna
            cout << board[i][j] << " ";
            if (board[i][j] == '.') // caso a célula esteja vazia (seja um '.')
                continue; // primeira vez que uso essa função 'continue', faz com que o loop pule para a próxima iteração caso a condição seja verdadeira

            pair<int, int> gridKey = {i / 3, j / 3}; // monta o par que será a chave da seção, onde o resultado da *divisão entre inteiros* linha / 3 e coluna / 3 determina a seção ex: linha 5 e coluna 7 resulta em (2, 3), pois 5 / 3 = 2 e 7 / 3 = 3
            if (lines[i].count(board[i][j]) || columns[j].count(board[i][j]) || grids[gridKey].count(board[i][j])) // checa se o número já foi registrado naquela linha, naquela coluna e naquela seção 3x3
                return false; // se o número já foi registrado anteriormente na linha, na coluna ou na seção, o sudoku está inválido

            lines[i].insert(board[i][j]); // caso seja um novo número na linha, ele é registrado para as próximas checagens
            columns[j].insert(board[i][j]); // idem para a coluna
            grids[gridKey].insert(board[i][j]); // idem para a seção
        }
        cout << endl;
    }

    return true; // se chegar a percorrer todo o tabuleiro sem encontrar duplicatas, o sudoku está válido
}

void imprimirBool(bool b){
    if (b)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

int main() {
    vector<vector<char>> board;

    board = {
        {'1','2','.','.','3','.','.','.','.'},
        {'4','.','.','5','.','.','.','.','.'},
        {'.','9','8','.','.','.','.','.','3'},
        {'5','.','.','.','6','.','.','.','4'},
        {'.','.','.','8','.','3','.','.','5'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','.','.','.','.','.','2','.','.'},
        {'.','.','.','4','1','9','.','.','8'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    imprimirBool(isValidSudoku(board));

    board = {
        {'1','2','.','.','3','.','.','.','.'},
        {'4','.','.','5','.','.','.','.','.'},
        {'.','9','1','.','.','.','.','.','3'},
        {'5','.','.','.','6','.','.','.','4'},
        {'.','.','.','8','.','3','.','.','5'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','.','.','.','.','.','2','.','.'},
        {'.','.','.','4','1','9','.','.','8'},
        {'.','.','.','.','8','.','.','7','9'}
    }; 
    imprimirBool(isValidSudoku(board));

    return 0;
}
