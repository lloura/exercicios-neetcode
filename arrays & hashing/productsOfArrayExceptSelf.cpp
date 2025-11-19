#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(), 1); // um truque da classe int, onde o primeiro valor dentro dos parenteses é o tamanho do vetor (nesse caso, o mesmo tamanho que o nums) e o segundo valor indica o que cada um deve vir preenchido por padrão

    // seria mais fácil linkar o video do neetcode sobre esse problema, mas basicamente para obter o O(n) é necessário navegar pelo vetor a partir do inicio e e depois a partir do fim, mas salvando o produto das multiplicações anteriores antes de prosseguir para o proximo
    // é meio abstrato, creio que seja mehor ver a ilustração que ele faz para relembrar o que está sendo feito aqui
    // https://neetcode.io/problems/products-of-array-discluding-self?list=neetcode150
    // https://youtu.be/bNvIQI2wAjk?si=54j3QY0F55ZXGoXr
    int prefix = 1;
    for (int i = 0; i < nums.size(); i++){
        res[i] = prefix;
        prefix *= nums[i];
    }

    int postfix = 1;
    for (int i = nums.size() - 1; i >= 0; i--){
        res[i] *= postfix;
        postfix *= nums[i];
    }

    return res;
}

int product(vector<int> nums){
    int res = 1;

    for (const auto& num : nums)
        res *= num;

    return res;
}

void imprimirVetorNums(vector<int>& nums){
    cout << "{ ";
    for (const auto& num : nums)
        cout << num << " ";
    cout << "}" << endl;
}

void demonstarFuncoesProduto(vector<int> nums){
    vector<int> res;
    int prod;

    cout << "nums = ";
    imprimirVetorNums(nums);

    cout << "prod = " << product(nums) << endl;

    cout << "res = ";
    res = productExceptSelf(nums);
    imprimirVetorNums(res);

    cout << endl;
}

int main() {
    vector<int> nums;

    nums = {1,2,4,6};
    demonstarFuncoesProduto(nums);

    nums = {-1,0,1,2,3};
    demonstarFuncoesProduto(nums);

    nums = {1,2,3,4};
    demonstarFuncoesProduto(nums);

    return 0;
}