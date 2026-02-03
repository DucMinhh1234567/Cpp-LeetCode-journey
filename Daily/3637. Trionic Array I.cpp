#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <sstream>

// You are given an integer array nums of length n.
// An array is trionic if there exist indices 0 < p < q < n − 1 such that:
// nums[0...p] is strictly increasing,
// nums[p...q] is strictly decreasing,
// nums[q...n − 1] is strictly increasing.
// Return true if nums is trionic, otherwise return false.

// Example 1:
// Input: nums = [1,3,5,4,2,6]
// Output: true
// Explanation:
// Pick p = 2, q = 4:
// nums[0...2] = [1, 3, 5] is strictly increasing (1 < 3 < 5).
// nums[2...4] = [5, 4, 2] is strictly decreasing (5 > 4 > 2).
// nums[4...5] = [2, 6] is strictly increasing (2 < 6).

// Example 2:
// Input: nums = [2,1,3]
// Output: false
// Explanation:
// There is no way to pick p and q to form the required three segments.

// Constraints:
// 3 <= n <= 100
// -1000 <= nums[i] <= 1000

using namespace std;

class Solution {
    public:
        bool isTrionic(vector<int>& nums) {
            int n = nums.size(), big = -1, small = n;

            for (int i = 0; i < n - 1; i++){
                if (big == -1 && nums[i] >= nums[i + 1]) big = i;
                if (small == n && nums[n - i - 1] <= nums[n - i - 2]) small = n - i - 1;
                
                if (big > 0 && small < n - 1 && big < small){
                    for (int i = big; i < small; i++){
                        if (nums[i] <= nums[i + 1]) return false;
                    }
                    return true;
                }
            }

            return false;
        }
    };