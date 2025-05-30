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
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;

        for (char c : magazine){
            if (map.find(c) != map.end()) map[c]++;
            else map[c] = 1;
        }

        for (char c : ransomNote){
            if (map.find(c) != map.end() && map[c] > 0) map[c]--;
            else return false;
        }
        return true;

        // Cách khác sử dụng mảng cố định
        int count[26] = {0};  // Initialize array with zeros
        
        // Count characters in magazine
        for (char c : magazine) {
            count[c - 'a']++;
        }
        
        // Check if we can construct ransomNote
        for (char c : ransomNote) {
            if (count[c - 'a']-- <= 0) {
                return false;
            }
        }
        return true;
    }
};