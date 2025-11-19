#include <cstdlib>
#include <iostream>

using namespace std;

// essa nova iteração do exercício é mais refinada, por isso o tempo de execução é O(logn)

double myPowAux(double x, long long int n){ // função auxiliar para ajudar a aplicar também os conceitos de dividir e conquistar nesse exercicio, será encarregada de realizar os cálculos das potencializações
    if (n == 0) return 1; // caso base da função recursiva, onde a cada iteração n ficará cada vez mais perto de 0, e então será devolvido 1, pois todo numero elevado à 0 resulta em 1

    double half = myPowAux(x, n / 2); // variável half criada para reduzir a quantidade de chamadas da função auxiliar, ajudando a solução a ser verdadeiramente O(log n)

    return (n % 2 == 0) ? (half * half) : (half * half * x); // chamada recursiva da função, onde é verificado se n é ímpar ou não, caso for, será necessário multiplicar o resultado final das operações por x mais uma vez

    // return (n % 2 == 0) ? (myPowAux(x, n / 2) * myPowAux(x, n / 2)) : (myPowAux(x, n / 2) * myPowAux(x, n / 2) * x); método antigo que tornava a solução a ser O(2 log n), o que causava erros de time out em edge cases
}

double myPow(double x, int n){
    if (x == 0) return 0; // independente do expoente, 0 elevado a qualquer número sempre resultará em 0, então é retornado 0 logo de cara

    long long int longN = n; // conversão de int para long long int para corrigir os erros de conversão de sinal que aconteciam, novamente, nos edge cases malucos do leetcode

    return (n > 0) ? (myPowAux(x, abs(longN))) : (1 / myPowAux(x, abs(longN))); // chamada da função auxiliar, a depender se o expoente for positivo ou não, no término do cálculo a resposta será ajustada, pois por ex.: 2³ = 2.2.2, já 2⁻³ = 1 / (2.2.2)
}

// essa antiga iteração do exercício foi mais experimental e rudimentar, por isso o tempo de execução é O(n)

/*
double myPow(double x, int n) { // tentei fazer esse exercicio de forma recursiva, seguindo o que li sobre recursividade no livro entendendo algoritomos (grokking algorythms)
    if (n == 0) // esse é o caso base, quero que todas as iterações cheguem cada vez mais perto de 0, pois aí posso devolver 1, uma vez que qualquer número elevado a 0 resulta em 1
        return 1;

    return (n > 0) ? (myPow(x, n - 1) * x) : (myPow(x, n + 1) / x); // comparação para verificar se o expoente é maior ou não que zero, caso for, vamos querer que na proxima iteração o expoente seja ele n-1, caso contrário, ele será n+1, para que se aproxime mais de 0
}
*/

int main() {
    double x;
    int n;

    x = 2;
    n = 5;
    cout << "x = " << x << endl;
    cout << "n = " << n << endl;
    cout << "myPow = " << myPow(x, n) << endl;

    x = 1.1;
    n = 10;
    cout << "x = " << x << endl;
    cout << "n = " << n << endl;
    cout << "myPow = " << myPow(x, n) << endl;

    x = 2;
    n = -3;
    cout << "x = " << x << endl;
    cout << "n = " << n << endl;
    cout << "myPow = " << myPow(x, n) << endl;

    return 0;
}
