#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    
    for (const auto& str : strs){ // para cada string recebida
        vector<int> countChar(26,0); // criando um vetor com 26 espaços e tendo todos estes espaços já preenchidos por 0
        for (auto& c : str) // para cada caractere da string
            countChar[toascii(c) - toascii('a')]++; // realiza a contagem dos caracteres
        
        string key; // nesse caso é necessário criar uma string ao invés de somente somar os valores pois é possível que a soma desses ainda dẽ o mesmo resultado, mesmo se as strings conterem uma contagem de caracteres diferente
        for (int i{}; i < countChar.size(); i++)
            key += ',' + to_string(countChar[i]); // criando uma chave única para a combinação da contagem de caracteres
        
        map[key].push_back(str); // utiliza a chave (a contagem de caracteres em formato de string) e adiciona a string ao vetor
    }

    vector<vector<string>> result; // criando o vetor de vetores de strings para poder retornar o resultado
    for (const auto& val : map){ // para cada vetor do mapa hash
        result.push_back(val.second); // adiciona o segundo elemento do mapa hash de acordo com a chave, nesse caso sendo o vetor com as strings
    } 
    return result;
}

void imprimirGroupAnagrams(vector<vector<string>>& result){
    cout << "[";
    for (const auto& strs : result){ // para cada vetor de string
        cout << "[";
        for (const auto& str : strs){ // para cada string
            cout << "\"" << str << "\",";
        }
        cout << "],";
    }
    cout << "]" << endl << endl;
}

void imprimirStrs(vector<string> strs){
    cout << "str = { ";
    for (const auto& str : strs)
        cout << "\"" << str << "\" ";
    cout << "}" << endl;
}

int main() {
    vector<string> strs;
    vector<vector<string>> result;

    strs = {"act","pots","tops","cat","stop","hat"};
    imprimirStrs(strs);
    result = groupAnagrams(strs);
    imprimirGroupAnagrams(result);

    strs = {"x"};
    imprimirStrs(strs);
    result = groupAnagrams(strs);
    imprimirGroupAnagrams(result);

    strs = {""};
    imprimirStrs(strs);
    result = groupAnagrams(strs);
    imprimirGroupAnagrams(result);

    return 0;
}