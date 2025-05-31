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
    bool canJump(vector<int>& nums) {
        int maxReach = 0;  // Vị trí xa nhất có thể nhảy đến
        
        for (int i = 0; i < nums.size(); i++) {
            // Nếu vị trí hiện tại vượt quá khả năng nhảy xa nhất, return false
            if (i > maxReach) return false;
            
            // Cập nhật vị trí xa nhất có thể nhảy đến
            maxReach = max(maxReach, i + nums[i]);
            
            // Nếu đã có thể nhảy đến vị trí cuối cùng, return true
            if (maxReach >= nums.size() - 1) return true;
        }
        
        return false;
    }
};