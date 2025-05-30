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
    int minSubArrayLen(int target, vector<int>& nums) {
        // O(n)
        int sum = 0;
        int count = INT_MAX;
        for (int i = 0, j = 0; i < nums.size(); i++){
            sum += nums[i];
            while (sum >= target){
                sum -= nums[j];
                count = min(i - j + 1, count);
                j++;
            }
        }
        if (count == INT_MAX) return 0;
        return count;

        // Tìm lời giải O(nlog(n))
    }
};