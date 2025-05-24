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
    int climbStairs(int n) {
        // Plain Fibonacci solution
        if (n == 0 || n == 1 || n == 2) return n;

        int sum = 3;
        int prev = 2;
        for (int i = 4; i <= n; i++){
            int temp = sum;
            sum += prev;
            prev = temp;
        }
        
        // Using Binet's formula: F(n) = (φ^n - (-φ)^(-n)) / √5
        // where φ = (1 + √5) / 2 (golden ratio)
        // const double phi = (1 + sqrt(5)) / 2;
        // return round(pow(phi, n + 1) / sqrt(5));

        return sum;
    }
};