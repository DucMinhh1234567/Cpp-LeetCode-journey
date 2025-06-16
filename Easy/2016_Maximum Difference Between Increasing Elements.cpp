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
    int maximumDifference(vector<int>& nums) {
        int result = -1;
        int num = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] > num) result = max(result,nums[i] - num);
            if (num > nums[i]) num = nums[i];
        }
        return result;
    }
};