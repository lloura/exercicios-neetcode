#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int esquerda{}; // utilizar a técnica de dois ponteiros, um algoritmo de busca binaria convencional daria problema com números repetidos 
    int direita = numbers.size() - 1; // 

    while (esquerda < direita){
        if (numbers[esquerda] + numbers[direita] == target) 
            return {esquerda + 1, direita + 1}; 
        if (numbers[esquerda] + numbers[direita] > target) // 
            direita--; // diminui o escopo mais para a esquerda
        else
            esquerda++; // diminui o escopo mais para a direita
    }

    return {};
}

void imprimirVetor(vector<int>& nums){
    cout << "{ ";
    for (auto i : nums)
        cout << i << " ";
    cout << "}" << endl;
}

void executarFuncoesTwoSum(vector<int> numbers, int target){
    vector<int> res;

    cout << "numbers = ";
    imprimirVetor(numbers);
    
    cout << "target = ";
    cout << target << endl;

    res = twoSum(numbers, target);
    cout << "twoSum = ";
    imprimirVetor(res);
    cout << endl;
}

int main() {
    vector<int> numbers;
    int target;

    numbers = {1, 2, 3, 4};
    target = 3;
    executarFuncoesTwoSum(numbers, target);

    numbers = {2, 3, 4};
    target = 6;
    executarFuncoesTwoSum(numbers, target);

    numbers = {2,7,11,15};
    target = 9;
    executarFuncoesTwoSum(numbers, target);

    numbers = {0,0, 3,4};
    target = 0;
    executarFuncoesTwoSum(numbers, target);

    numbers = {-1,3};
    target = 2;
    executarFuncoesTwoSum(numbers, target);

    return 0;
}