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
    int minimumTotal(vector<vector<int>>& triangle) {
        // Algorithm solution
        int result = triangle[0][0];
        int save = 0;
        for (int i = 1; i < triangle.size(); i++){
            int temp = min(triangle[i][save], triangle[i][save + 1]);
            if (temp == triangle[i][save + 1]) save++;
            result += temp;
        }
        return result;
    }
};