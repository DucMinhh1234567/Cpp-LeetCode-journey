#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dup{1};
        for (int i{1}; i < nums.size(); i++){
            if (nums[i] != nums[i - 1]){
                nums[dup] = nums[i];
                dup++;
            }
        }
        return dup;
    }
};