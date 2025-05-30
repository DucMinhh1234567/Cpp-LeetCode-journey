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
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int len = s.length();
        // Sort rồi so sánh: O(nlog(n))
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;

        // Dùng unordered map: O(n)
        unordered_map<char, int> map;
        for (int i = 0; i < len; i++){
            map[s[i]]++;
        }
        for (int i = 0; i < len; i++){
            if (map[t[i]] == 0) return false;
            map[t[i]]--;
        }
        return true;
    }
};