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
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        
        vector<string> result;
        int begin = nums[0], end = nums[0];
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i] + 1 == nums[i + 1]) end = nums[i + 1];
            else {
                string temp;
                if (begin == end){
                    temp = to_string(begin);
                    result.push_back(temp);
                }
                else {
                    temp = to_string(begin) + "->" + to_string(end); 
                    result.push_back(temp);
                }
                begin = nums[i + 1];
                end = nums[i + 1];
            }
        }
        
        // Handle the last range
        string temp;
        if (begin == end){
            temp = to_string(begin);
            result.push_back(temp);
        }
        else {
            temp = to_string(begin) + "->" + to_string(end); 
            result.push_back(temp);
        }
        
        return result;

        // Cách clean hơn
        if (nums.empty()) return {};
        
        vector<string> result;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int start = nums[i];
            // Find the end of current range
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }
            
            if (start == nums[i]) {
                result.push_back(to_string(start));
            } else {
                result.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
        }
        
        return result;
    }
};