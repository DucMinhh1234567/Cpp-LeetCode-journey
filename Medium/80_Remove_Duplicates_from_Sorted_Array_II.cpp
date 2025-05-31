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
    int removeDuplicates(vector<int>& nums) {
        // Cách vừa dốt vừa tốn bộ nhớ
        bool check = false;
        int count = 1;
        for (int i = 1, j = 1; i < nums.size(); i++){
            if (!check && nums[i] == nums[i - 1]){
                check = true;
                nums[j] = nums[i];
                j++;
            }
            else if (check && nums[i] == nums[i - 1]){
                continue;
            }
            else if (nums[i] != nums[i - 1]){
                check = false;
                nums[j] = nums[i];
                j++;
            }
            count++;
        }
        return count;

        // Cách giỏi hơn
        if (nums.size() <= 2) return nums.size();
        
        int j = 2;  // Vị trí để ghi phần tử tiếp theo
        
        for (int i = 2; i < nums.size(); i++) {
            // Nếu phần tử hiện tại khác với phần tử ở vị trí j-2
            // nghĩa là nó chưa xuất hiện 2 lần
            if (nums[i] != nums[j-2]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};