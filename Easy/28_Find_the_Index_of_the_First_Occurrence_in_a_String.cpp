#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) return -1;

        int start{0}, end{0};
        for (; start < haystack.length(); start++){
            while (end < needle.length() && needle[end] == haystack[start + end]){
                end++;
            }
            if (end == needle.length()){
                return start;
            }
            else {
                end = 0;
            }
        }

        return -1;
    }
};