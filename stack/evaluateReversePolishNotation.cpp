#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int calculate(const int& val1, const int& val2, const string& op){ // função auxiliar para realizar de fato os cálculos
    if (op == "+")
        return val1 + val2;
    if (op == "-")
        return val1 - val2;
    if (op == "*")
        return val1 * val2;
    if (op == "/")
        return val1 / val2;

    return 0;
}

int evalRPN(vector<string>& tokens) {
    stack<int> eval; // 

    for (int i{}; i < tokens.size(); i++){
        if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") // caso não for uma operação
            eval.push(stoi(tokens[i])); // adiciona o número na pilha
        else{ // caso o tokens[i] for +,-,*,/
            int val1 = eval.top(); // pega o primeiro item da pilha
            eval.pop();
            int val2 = eval.top(); // pega o segundo item da pilha (primeiro item atual)
            eval.pop();
            eval.push(calculate(val2, val1, tokens[i])); // insere de volta na pilha o resultado da operação
        }
    }
    
    return eval.top();
}

void imprimirTokens(const vector<string>& tokens){
    cout << "tokens = [";
    for (auto token : tokens)
        cout << " \"" << token <<  "\"";
    cout << "]" << endl;
    }

int main() {
    vector<string> tokens;

    tokens = {"1","2","+","3","*","4","-"};
    imprimirTokens(tokens);
    cout << "res = " << evalRPN(tokens) << endl;

    tokens = {"2","1","+","3","*"};
    imprimirTokens(tokens);
    cout << "res = " << evalRPN(tokens) << endl;

    tokens = {"4","13","5","/","+"};
    imprimirTokens(tokens);
    cout << "res = " << evalRPN(tokens) << endl;

    tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    imprimirTokens(tokens);
    cout << "res = " << evalRPN(tokens) << endl;

    return 0;
}