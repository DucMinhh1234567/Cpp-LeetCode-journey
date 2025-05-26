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
    int reverse(int x) {
        int result = 0;

        while (x != 0){
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && x % 10 > 7)) return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && x % 10 < -8)) return 0;

            result = (result * 10 + x % 10);
            x /= 10;
        }

        return result;
    }
};