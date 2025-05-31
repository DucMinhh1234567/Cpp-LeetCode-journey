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
    string intToRoman(int num) {
        // Cách khôn ác
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hdrds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thsds[] = {"", "M", "MM", "MMM"};
        return thsds[num / 1000] + hdrds[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
    }
};