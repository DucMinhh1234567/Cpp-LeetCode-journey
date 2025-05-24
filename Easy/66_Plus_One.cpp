#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0 && carry != 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
                carry = 1;
            } else {
                digits[i] += 1;
                carry = 0;
            }
        }
        
        if (carry != 0) {
            digits.insert(digits.begin(), 1);
        }

        // Cleaner version
        // for (int i = digits.size() - 1; i >= 0; i--) {
        //     if (digits[i] < 9) {
        //         digits[i]++;
        //         return digits;
        //     }
        //     digits[i] = 0;
        // }
        // digits.insert(digits.begin(), 1);
        return digits;
    }
};