#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map; // cria a tabela hash que armazenará os valores e seus respectivos indices (valor -> indice)

    for (int i{}; i < nums.size(); i++){
        if (map.find(target - nums[i]) == map.end()) // realiza a procura da chave (nesse caso, o valor resultante de target - nums[i]) no mapa
            map.insert_or_assign(nums[i], i); // caso a chave (o valor) ainda não exista na tabela, este será adicionado juntamente com seu indice
        else // caso a chave exista, será retornada o indice referente ao valor de target - nums[i], juntamente com o valor atual
            return {map[target - nums[i]], i};
    }
    return {};
}

void imprimirVetor(vector<int>& nums){
    for (auto i : nums)
        cout << i << " ";
    cout << endl;
}

int main() {
    vector<int> nums, result;
    int target;

    nums = {3, 4, 5, 6};
    imprimirVetor(nums);
    target = 7;
    cout << target << endl;
    result = twoSum(nums, target);
    imprimirVetor(result);
    cout << endl;

    
    nums = {4, 5, 6};
    imprimirVetor(nums);
    target = 10;
    cout << target << endl;
    result = twoSum(nums, target);
    imprimirVetor(result);
    cout << endl;

    nums = {5, 5};
    imprimirVetor(nums);
    target = 10;
    cout << target << endl;
    result = twoSum(nums, target);
    imprimirVetor(result);
    cout << endl;
    
    nums = {-1, -2, -3, -4, -5};
    imprimirVetor(nums);
    target = -8;
    cout << target << endl;
    result = twoSum(nums, target);
    imprimirVetor(result);
    cout << endl;

    return 0;
}