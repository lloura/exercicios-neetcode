#include <iostream>
#include <string>
#include <vector>

using namespace std;

string encode(vector<string>& strs) {
    string s;

    for (const auto& str : strs) // para cada string do vetor
        s += to_string(str.length()) + "#" + str; // concactenando o tamanho de cada string + um caractere indicador (nesse caso \) + a string em si

    return s;
}

vector<string> decode(string& s) {
    vector<string> strs;

    while (!s.empty()){ // enquanto a string original não estiver vazia
        int pos = s.find("#"); // primeiro busca a posição do caractere indicador
        int length = stoi(s.substr(0, pos)); // interpreta que todos os caracteres entre a pos 0 do vetor até a posição do caractere especial são na verdade o tamanho da string, e após retirar essa substring converte a mesma no tamanho da string a ser extraida
        strs.push_back(s.substr(pos+1, length)); // insere no vetor a substring que está entre a posição pos+1 (para não pegar o caractere especial) até o tamanno da string a ser extraida
        s = s.substr(pos+1+length); // reduz a string original retirando o número a direita do caractere especial, o caractere especial em si, como também a substring já estraída
    }

    return strs;
}

void imprimirVetorStrings(const vector<string>& strs){
    for (const auto& s : strs)
        cout << "\"" << s << "\"" << " ";
    cout << endl;
}

void demonstrarFuncoesEncodeDecodeStrings(vector<string>& strsInput){
    string encodedS;
    vector<string> strsOutput;

    cout << "strsInput: ";
    imprimirVetorStrings(strsInput);

    cout << "encodedS: ";
    encodedS = encode(strsInput);
    cout << "\"" << encodedS << "\"" << endl;

    cout << "strsOutput: ";
    strsOutput = decode(encodedS);
    imprimirVetorStrings(strsOutput);
}

int main() {
    vector<string> strs;
    
    strs = {"neet","code","love","you"};
    demonstrarFuncoesEncodeDecodeStrings(strs);

    strs = {"we","say",":","yes"};
    demonstrarFuncoesEncodeDecodeStrings(strs);

    return 0;
}