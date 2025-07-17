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
    int possibleStringCount(string word) {
        int count = 0;
        for (int i = 1; i < word.length(); i++){
            if (word[i - 1] == word[i]) count++;
        }
        return count + 1;
    }
};