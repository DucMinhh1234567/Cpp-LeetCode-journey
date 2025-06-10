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
    int maxDifference(string s) {
        unordered_map<char, int> map;
        int odd = 0, even = s.length();
        for (int i = 0; i < s.length(); i++){
            map[s[i]]++;
        }
        for (auto i = map.begin(); i != map.end(); i++){
            if (i->second % 2 == 0) even = min(i->second, even);
            if (i->second % 2 == 1) odd = max(i->second, odd);
        }
        return odd - even;
    }
};