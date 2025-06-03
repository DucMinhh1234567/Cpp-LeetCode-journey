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
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0, right = size - 1;
        while (left < right){
            int mid = left + (right - left) / 2;
            // Left side is sorted
            if (nums[0] <= nums[mid]){
                if (nums[0] <= target && target <= nums[mid]) right = mid;
                else left = mid + 1;
            }
            // Right side is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) left = mid + 1;
                else right = mid;
            }
        }
        return (left == right && nums[left] == target) ? left : -1;
    }
};