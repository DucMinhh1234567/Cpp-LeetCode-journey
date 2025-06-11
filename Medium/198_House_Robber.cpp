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
    int rob(vector<int>& nums) {
        int result = 0, iter = 0;
        for (int i = 0; i < nums.size(); i++){
            int temp = result;
            result = max(iter + nums[i], result);
            iter = temp;
        }
        return result;
    }
};