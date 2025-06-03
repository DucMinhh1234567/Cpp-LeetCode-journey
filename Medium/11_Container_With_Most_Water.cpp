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
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxAmount = (right - left) * min(height[left], height[right]);
        while (left < right){
            if (height[left] > height[right]) right--;
            else left++;
            maxAmount = max(maxAmount, (right - left) * min(height[left], height[right]));
        }
        return maxAmount;
    }
};