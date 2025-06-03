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
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while (i > 0 && nums[i-1] >= nums[i]) {
            i--;
        }
        
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int j = nums.size() - 1;
        while (j >= i && nums[j] <= nums[i-1]) {
            j--;
        }
        
        swap(nums[i-1], nums[j]);
        reverse(nums.begin() + i, nums.end());        
    }
};