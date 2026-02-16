#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            
            result += to_string(sum % 2);
            carry = sum / 2;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};