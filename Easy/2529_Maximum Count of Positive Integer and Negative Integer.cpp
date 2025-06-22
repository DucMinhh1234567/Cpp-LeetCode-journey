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
    int maximumCount(vector<int>& nums) {
        int neg = binarySearch(nums, 0);
        int pos = nums.size() - binarySearch(nums, 1);
        return max(neg, pos);
    }

    int binarySearch(vector<int> &nums, int target){
        int left = 0, right = nums.size() - 1;
        int result = nums.size();
        while (left <= right){
            int mid = left + (right - left) / 2;
            if (nums[mid] < target){
                left = mid + 1;
            }
            else {
                result = mid;
                right = mid - 1;
            }
        }
        return result;
    }
};