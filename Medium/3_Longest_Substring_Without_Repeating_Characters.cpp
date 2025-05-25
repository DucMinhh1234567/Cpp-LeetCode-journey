#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        
        int start = -1, i = 0, longest = 1;
        unordered_map<char, int> map;

        for (; i < s.length(); i++){
            // tìm thấy, nhảy window đến chữ cái tìm thấy trc đó
            // cập nhật map, cập nhật vị trí hiện tại
            if (map.find(s[i]) != map.end() && map[s[i]] > start){
                start = map[s[i]];
            }
            map.insert_or_assign(s[i], i);
            if (longest < i - start) longest = i - start;
        }

        return longest;
    }
};