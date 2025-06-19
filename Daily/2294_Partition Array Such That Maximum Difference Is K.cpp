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
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int compare = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] - compare > k){
                count++;
                compare = nums[i];
            }
        }
        return count;
    }
};