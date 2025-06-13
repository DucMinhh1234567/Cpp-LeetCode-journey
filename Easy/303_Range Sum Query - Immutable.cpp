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

class NumArray {
private:
    vector<int> arr;

public:
    NumArray(vector<int>& nums) {
        arr.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++){
            arr.push_back(arr[i - 1] + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0){
            return arr[right];
        }

        return arr[right] - arr[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */