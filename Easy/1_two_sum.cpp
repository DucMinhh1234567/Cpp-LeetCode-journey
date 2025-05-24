#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i{0}; i < nums.size(); i++){
            map[nums[i]] = i;
        }
        for (int i{0}; i < nums.size(); i++){
            int minus = target - nums[i];
            if (map.find(minus) != map.end() && map[minus] != i){
                return {i, map[minus]};
            }
        }

        return {};
    }
};