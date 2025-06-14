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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); i++) {
            // Nếu khoảng hiện tại có thể merge với khoảng cuối cùng trong merged
            if (merged.back()[1] >= intervals[i][0]) {
                // Cập nhật điểm kết thúc của khoảng cuối cùng
                merged.back()[1] = max(merged.back()[1], intervals[i][1]);
            } else {
                // Thêm khoảng mới vào merged
                merged.push_back(intervals[i]);
            }
        }
        
        return merged;
    }
};