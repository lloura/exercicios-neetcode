#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() -1;

    while(low <= high){
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    return -1;
}

void imprimirVetor(const vector<int>& nums){
    cout << "{ ";
    for(const auto& num : nums){
        cout << num << " ";
    }
    cout << "}";
    cout << endl;
}

void chamarFuncoesBuscaBinaria(vector<int>& nums, const int& target){
    cout << "nums = ";
    imprimirVetor(nums);
    cout << "target = " << target << endl;
    cout << "search = " << search(nums, target) << endl << endl;
}

int main() {
    vector<int> nums;
    int target;    
/*
    nums = {-1,0,2,4,6,8};
    target = 4;
    chamarFuncoesBuscaBinaria(nums, target);

    nums = {-1,0,2,4,6,8};
    target = -1;
    chamarFuncoesBuscaBinaria(nums, target);
*/
    nums = {-1,0,3,5,9,12};
    target = 9;
    chamarFuncoesBuscaBinaria(nums, target);

    nums = {-1,0,3,5,9,12};
    target = 2;
    chamarFuncoesBuscaBinaria(nums, target);

    return 0;
}