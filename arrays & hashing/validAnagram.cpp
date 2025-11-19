#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) // caso haja diferença nos tamanhos das strings, por definição elas não podem ser anagramas uma da outra
        return false;

    unordered_map<char, int> countS, countT; // cria uma tabela hash para servir de contador para cada caractere, utilizando o proprio caractere como chave
    
    for (int i{}; i < s.size(); i++){
        countS[s[i]]++; // adiciona +1 ao contador dos caracteres, que por padrão começa em 0  
        countT[t[i]]++;
    }

    return countS == countT; // se as tabelas hash forem iguais, significa que há a mesma quantidade de caracteres em ambas as strings
}

void checkIsAnagram(string s, string t){
    if (isAnagram(s, t))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

int main() {
    string s, t;

    s = "racecar";
    t = "carrace";
    cout << s << endl;
    cout << t << endl;
    checkIsAnagram(s, t);

    s = "jar";
    t = "jam";
    cout << s << endl;
    cout << t << endl;
    checkIsAnagram(s, t);

    return 0;
}