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
    int differenceOfSums(int n, int m) {
        // Calculate sum of all numbers from 1 to n
        // sum = k * n * (n + 1) / 2 
        // k: khoảng cách giữa các số
        // n: số chữ số
        long long totalSum = (long long)n * (n + 1) / 2;
        
        // Calculate sum of numbers divisible by m
        long long divisibleCount = n / m;
        long long divisibleSum = (long long)m * divisibleCount * (divisibleCount + 1) / 2;
        
        // Sum of non-divisible numbers = total sum - divisible sum
        // Difference = (non-divisible sum) - (divisible sum)
        // = (total sum - divisible sum) - divisible sum
        // = total sum - 2 * divisible sum
        return totalSum - 2 * divisibleSum;
    }
};