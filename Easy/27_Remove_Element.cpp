#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int dup{0};
        for (int i{0}; i < nums.size(); i++){
            if (nums[i] != val){
                nums[dup] = nums[i];
                dup++;
            }
        }
        return dup;
    }
};