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
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        
        // Solution 1: Use how frequent the sign change
        vector<int> result;
        int count = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] - nums[i - 1] != 0) result.push_back(nums[i] - nums[i - 1]);
        }
        
        if (result.empty()) return 1;
        
        for (int i = 1; i < result.size(); i++) {
            if (result[i] * result[i-1] < 0) {
                count++;
            }
        }
        
        return count + 1;

        // Solution 2: Find peak and the valley of the difference map
        // Pretty much the same but solution 2 does seem more efficient
        // And more complex
        int up = 1, down = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                up = down + 1;
            } else if (nums[i] < nums[i-1]) {
                down = up + 1;
            }
        }
        return max(up, down);
    }
};