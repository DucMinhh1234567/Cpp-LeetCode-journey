#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = s.length() - 1;
        while (s[i] == ' '){
            i--;
        }
        while (s[i] != ' '){
            count++;
            i--;
        }
        return count;
    }
};