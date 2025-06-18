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
    int maxRepeating(string sequence, string word) {
        int maxCount = 0;
        int n = sequence.size();
        int m = word.size();
        
        // Try starting from each position
        for (int i = 0; i <= n - m; i++) {
            int count = 0;
            int pos = i;
            
            // Count consecutive occurrences starting from position i
            while (pos <= n - m && sequence.substr(pos, m) == word) {
                count++;
                pos += m;
            }
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};