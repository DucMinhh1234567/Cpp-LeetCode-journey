#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (len == 0 || len == 1) return false;
        // Brute force: O(n^2)
        for (int i = 0; i < len; i++){
            for (int j = 0; j < len; j++){
                if (j != i && nums[i] == nums[j]) return true;
            }
        }
        return false;

        // Sort then search: O(nlog(n))
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 1; i++){
            if (nums[i] == nums[i + 1]) return true;
        }
        return false;

        // Use unordered set: O(n)
        unordered_set<int> set;
        for (int i = 0; i < len; i++){
            // Nếu tìm ko thấy
            if (set.find(nums[i]) == set.end()) set.insert(nums[i]);
            else return true;
        }
        return false;
    }
};