#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        if (target > nums.back()) return nums.size();
        
        int left = 0, right = nums.size() - 1;
        // Binary search để tìm vị trí chèn
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return (nums[left] < target) ? left + 1 : left;
    }
};