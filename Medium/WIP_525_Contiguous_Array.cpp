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
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map;
        int size = 0;
        int start = 0; // Sliding window starting point
        for (int i = 0; i < nums.size(); i++){
            map[i]++;
            if (map[0] == map[1]) {
                map.clear();
                size = max(size, map[0] * 2);
            }
        }
    }
};