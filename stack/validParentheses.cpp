#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> brackets; // pilha que armazenará os parenteses que estiverem sendo comparados

    for (int i = 0; i < s.size(); i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){ // se for um parentese de abertura, será adicionado à pilha
            brackets.push(s[i]);
        }
        else{
            if (brackets.empty()) // caso já não haja nenhum parentese de na pilha, já retorna false, também serve como medida de segurança, pois impede que seja feito o pop() em uma pilha fazia
                return false;
            else{
                if ((s[i] == ')' && brackets.top() == '(') || (s[i] == ']' && brackets.top() == '[') || (s[i] == '}' && brackets.top() == '{')) // caso o caractere sendo comparado seja um parentese de abertura E o último caractere adicionado seja o seu respectivo parentese de fechamento, é realizada a operação pop() na pilha, para poder ser comparado com outro caractere
                    brackets.pop();
                else
                    return false;
            }
        }
    }

    return brackets.empty(); // se a pilha estiver vazia, significa que a ordem dos parenteses estava correta e portando eles são validos
}

void printBoolean(bool b){
    if (b)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}

int main() {
    string s;

    s = "[]";
    cout << s << endl;
    printBoolean(isValid(s));

    s = "([{}])";
    cout << s << endl;
    printBoolean(isValid(s));

    s = "[(])";
    cout << s << endl;
    printBoolean(isValid(s));    

    return 0;
}