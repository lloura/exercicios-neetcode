#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    bool res;

    // da pra usar um set para verificar se há duplicatas nas linhas ou colunas, dá pra tentar converter um desses em set e se o tamanho for diferente de 9 já dá pra retornar false

    // a segunda dica recomenda utilizar um hash set para verificar as linhas e colunas

    return res;
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

    board = {{'1','2','.','.','3','.','.','.','.'},
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