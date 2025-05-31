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
    int jump(vector<int>& nums) {
        int i = 0, maxPos = 0, maxReach = 0, count = 0;

        while (maxPos < nums.size() - 1){
            maxReach = max(maxReach, i + nums[i]);
            if (i == maxPos){
                maxPos = maxReach;
                count++;
            }
            i++;
        }
        
        return count;
    }
};