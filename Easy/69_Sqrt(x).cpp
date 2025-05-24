#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;


        int left = 1, right = min(x/2, 46340);
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            long long square = (long long)mid * mid;
            
            if (square < x) {
                left = mid + 1;
            } else if (square == x) {
                return mid;
            } else {
                right = mid - 1;
            }
        }
        
        return right;
    }
};