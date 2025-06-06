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
    void rotate(vector<int>& nums, int k) {
        // Cách 1
        int size = nums.size();
        if (size == 0) return;
        
        // Xử lý trường hợp k lớn hơn size
        k = k % size;
        
        vector<int> temp(size);
        for (int i = 0; i < size; i++) {
            temp[(i + k) % size] = nums[i];
        }
        nums = temp;

        
        //Cách 2
        int size = nums.size();
        if (size == 0) return;
        
        k = k % size;
        
        // Reverse toàn bộ mảng
        reverse(nums.begin(), nums.end());
        // Reverse k phần tử đầu tiên
        reverse(nums.begin(), nums.begin() + k);
        // Reverse phần còn lại
        reverse(nums.begin() + k, nums.end());
    }
};