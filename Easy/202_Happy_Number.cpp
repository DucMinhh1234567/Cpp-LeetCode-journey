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
    int square(int num){
        int toSqrt = 0;
        while (num > 0){
            toSqrt += (num % 10) * (num % 10);
            num /= 10;
        }
        return toSqrt;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = square(slow);
            fast = square(square(fast));
        } while (slow != fast);
        return slow == 1;
    }
};