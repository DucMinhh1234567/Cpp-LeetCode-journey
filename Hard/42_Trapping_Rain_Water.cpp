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
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, water = 0;
        int maxLeft = height[left];
        int maxRight = height[right];

        while (left < right){
            if (maxLeft < maxRight){
                left++;
                maxLeft = max(maxLeft, height[left]);
                water += maxLeft - height[left];
            }
            else {
                right--;
                maxRight = max(maxRight, height[right]);
                water += maxRight - height[right];
            }
        }

        return water;

        // Pretty sure their are other solutions
        // Mine should work but i still haven't figure out
        // how to execute it
    }
};