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
    int maxAdjacentDistance(vector<int>& nums) {
        int large = abs(nums[nums.size() - 1] - nums[0]);
        for (int i = 1; i < nums.size(); i++){
            large = max(abs(nums[i] - nums[i - 1]), large);
        }
        return large;
    }
};