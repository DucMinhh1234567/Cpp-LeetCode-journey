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

// You are given an integer array nums and an integer k.
// An array is considered balanced if the value of its maximum element 
// is at most k times the minimum element.
// You may remove any number of elements from nums​​​​​​​ without making it empty.
// Return the minimum number of elements to remove so that the remaining array is balanced.
// Note: An array of size 1 is considered balanced as its maximum and minimum are equal, 
// and the condition always holds true.

// Example 2:
// Input: nums = [1,6,2,9], k = 3
// Output: 2
// Explanation:
// Remove nums[0] = 1 and nums[3] = 9 to get nums = [6, 2].
// Now max = 6, min = 2 and max <= min * k as 6 <= 2 * 3. Thus, the answer is 2.

// Example 3:
// Input: nums = [4,6], k = 2
// Output: 0
// Explanation:
// Since nums is already balanced as 6 <= 4 * 2, no elements need to be removed.

// Constraints:
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 1 <= k <= 105

class Solution {
    public:
        int minRemoval(vector<int>& nums, int k) {
            int n = nums.size();
            if (n == 1) return 0;
            
            sort(nums.begin(), nums.end());
            int j = 0, currentSize = 0;
            for (int i = 0; i < n; i++){
                while (j < n && (long long)nums[j] <= (long long)nums[i] * k){
                    j++;
                    currentSize = max(currentSize, j - i);
                }
            }
            
            return n - currentSize;
        }
    };