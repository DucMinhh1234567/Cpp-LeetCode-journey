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
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;

        for (int i = 0, j = 0; i < t.length() && j < s.length(); i++) {
            if (t[i] == s[j]) {
                j++;
                if (j == s.length()) return true;
            }
        }
        return false;
    }
};