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
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        for (int i = 0; i <= rowIndex; i++){
            vector<int> currenRow(i + 1, 1);
            for (int j = 1; j < i; j++){
                currenRow[j] = prev[j - 1] + prev[j];
            }
            prev = currenRow;
        }
        return prev;

        // Cách khôn vẫn không hiểu
        // Lấy từ đâu ra
        vector<int>sol;
        long long  ans = 1;
        sol.push_back(ans);
        
        for(int i=0;i<rowIndex;i++){
            ans = ans*(rowIndex-i);
            ans = ans/(i+1);
            sol.push_back(ans);
        }

        return sol;
    }
};