#include <iostream>

using namespace std;

string filterString(const string& s){ // funcao auxilar para filtrar os caracteres da string e os deixar de acordo com os do escopo do exercicio (alfanumericos, de a-z e de 0-9)
    string filteredS; // string que será criada com somente os caracteres filtrados

    for (int i = 0; i < s.length(); i++){
        if ((tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            filteredS += s[i];
        }
    }

    return filteredS;
}

bool isPalindrome(string s) {
    s = filterString(s); // primeiro filtrar a string para poder comparar somente com os caracteres alfanumericos presentes

    for (int i = 0; i < s.size() / 2; i++){ // começar do indice 0 e ir até a metade da string
        if (tolower(s[i]) != tolower(s[(s.size() - 1) - i])) // começar do indice 0 e comparar o caractere presente nele com o caractere presente no lado oposto do vetor
            return false; // caso em algum momento a comparação acima não for verdadeira, a string passada não configura como um palindromo
    }

    return true; // caso chegar até aqui, significa que todas as letras comparadas foram iguais às suas correspondentes do lado oposto do vetor, portanto, a string passada é um vetor
}

void printBoolean(bool b){
    if (b)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

int main() {
    string s;

    s = "Was it a car or a cat I saw?"; // true
    cout << s << endl;
    printBoolean(isPalindrome(s));

    s = "tab a cat"; // false
    cout << s << endl;
    printBoolean(isPalindrome(s));

    s = "Never odd or even"; // true
    cout << s << endl;
    printBoolean(isPalindrome(s));

    return 0;
}