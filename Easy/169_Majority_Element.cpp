#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int cur = nums[0];

        for (int i = 1; i < nums.size(); i++){
            if (cur == nums[i]){
                count++;
            }
            else {
                count--;
            }

            if (count < 0){
                count = 1;
                cur = nums[i];
            }
        }

        return cur;
    }
};