#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq; // mapa hash para guardar as contagens dos numeros (valor -> frequencia)

    for (const auto& num : nums) // para cada número em nums
        freq[num]++; // adiciona +1 na contagem de frequencia dos caracteres

    vector<pair<int, int>> pares(freq.begin(), freq.end()); // cria pares para poder ser realizada a organização
    sort(pares.begin(), pares.end(), [](const pair<int, int>& a, const pair<int, int>& b) {return a.second > b.second;}); // utilização mais avançada da função padrão sort, onde alémn dos pontos de início e fim também é enviada uma expressão de comparação, que servirá como critério da organização

    vector<int> res; // vetor que por fim armazenará os valores que mais se repetem
    for (int i = 0; i < k && i < pares.size(); i++) // não é necessário percorrer o par a partir do fim, pois o mesmo já foi organizado de maneira decrescente
        res.push_back(pares[i].first);

    return res;
}

void imprimirNums(vector<int>& nums){
    for (auto& num : nums)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> nums, result;
    int k;

    nums = {1,2,2,3,3,3};
    imprimirNums(nums);
    k = 2;
    cout << k << endl;
    result = topKFrequent(nums, k);
    imprimirNums(result);

    nums = {7, 7};
    imprimirNums(nums);
    k = 1;
    cout << k << endl;
    result = topKFrequent(nums, k);
    imprimirNums(result);

    return 0;
}