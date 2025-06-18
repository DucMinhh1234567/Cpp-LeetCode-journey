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
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n <= 1) return 0;
        
        vector<int> result(n + 1, 0);
        result[0] = 0;
        result[1] = 0;
        
        for (int i = 2; i <= n; i++) {
            result[i] = min(result[i-1] + cost[i-1], result[i-2] + cost[i-2]);
        }
        
        return result[n];
    }
};