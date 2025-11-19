#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

bool hasDuplicate(vector<int>& nums) {
    set<int> setNums(begin(nums), end(nums)); // insere os valores do array nums em um set (tipo de estrutura de dados que não permite duplicatas)
    return setNums.size() != nums.size(); // retorna o resultado da comparação dos valores do set criado e do array original, caso houver diferença entre os tamanhos, significa que havia dupliacatas no array original
}

void checkHasDuplicate(vector<int>& nums){
    if (hasDuplicate(nums))
        cout << "false" << endl;
    else
        cout << "true" << endl;
}

void imprimirArray(vector<int>& nums){
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<int> nums;

    nums = {1, 2, 3, 3};
    imprimirArray(nums);
    checkHasDuplicate(nums);

    nums = {1, 2, 3, 4};
    imprimirArray(nums);
    checkHasDuplicate(nums);

    return 0;
}