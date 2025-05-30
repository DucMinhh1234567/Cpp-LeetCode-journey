#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Sort rồi tìm: O(nlogn)
        sort(nums.begin(), nums.end());
        if (nums[0] != 0) return 0;
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i] + 1 != nums[i + 1]) return nums[i] + 1;
        }
        return nums.size();

        // Dùng unorder set
        unordered_set<int> set;
        for (int i : nums){
            set.insert(i);
        }

        for (int i = 0; i < nums.size(); i++){
            if (set.find(i) == set.end()) return i;
        }
        return nums.size();

        // Dùng unorder map
        unordered_map<int, int> map;
        for (int i : nums){
            map[i] = 1;
        }

        for (int i = 0; i < nums.size(); i++){
            if (map[i] != 1) return i;
        }
        return nums.size();

        // Cách XOR não to vl
        int n = nums.size();

        int xor1 = 0, xor2 = 0;
        int xoor = 0;
        for(int i = 0; i < n; i++){
            xor1 = xor1 ^ nums[i];
            xor2 = xor2 ^ (i+1);
        }
        xoor = xor1 ^ xor2;

        return xoor;
    }
};