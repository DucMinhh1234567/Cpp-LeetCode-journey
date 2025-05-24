#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Brute force O(n)
        // vector<int> pos;
        // for (int i{0}; i < nums.size(); i++){
        //     if (target == nums[i] && pos.empty()){
        //         pos.push_back(i);
        //         pos.push_back(i);
        //     }
        //     else if (target == nums[i] && pos.size() == 1){
        //         pos.push_back(i);
        //     }
        //     else if (target == nums[i] && pos.size() > 1){
        //         pos.pop_back();
        //         pos.push_back(i);
        //     }
        // }
        // if (pos.empty()) {
        //     pos.push_back(-1); 
        //     pos.push_back(-1);
        // }
        // return pos;

        // Binary search O(log(n))
        vector<int> pos = {-1, -1};
        
        int left{0}, right{nums.size() - 1};
        while (left < right){
            int mid {left + (right - left) / 2};
            if (nums[mid] < target){
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        if (nums[left] != target) return pos;

        pos[0] = left;
        right = nums.size() - 1;
        while (left < right){
            int mid {left + (right - left) / 2 + 1};
            if (nums[mid] > target){
                right = mid - 1;
            }
            else {
                left = mid;
            }
        }
        pos[1] = right;

        return pos;
    }
};