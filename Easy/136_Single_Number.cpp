#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Naive approach
        // if (nums.size() == 1) return nums[0];

        // unordered_map<int, int> map;
        // for (int i = 0; i < nums.size(); i++){
        //     // Tìm thấy -> xóa
        //     if (map.find(nums[i]) != map.end()){
        //         map.erase(nums[i]);
        //     }
        //     // Ko thấy -> thêm
        //     else {
        //         map.insert({nums[i], 1});
        //     }
        // }

        // return map.begin()->first;

        // Using XOR(^)
        // Basically turn form decimal (10) to binary (2) 
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};
