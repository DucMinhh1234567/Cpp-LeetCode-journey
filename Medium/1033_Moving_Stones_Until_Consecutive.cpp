#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> result(2, 0);
        int large = max({a, b, c});
        int small = min({a, b, c});
        int mid = a + b + c - large - small;

        if (large - mid == 1 && mid - small == 1) return {0, 0};
        else if (large - mid > 2 && mid - small > 2) result[0] = 2;
        else result[0] = 1;
        result[1] = large - small - 2;
        
        return result;
    }
};