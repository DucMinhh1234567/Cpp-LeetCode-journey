#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    bool divisorGame(int n) {
        if (n % 2 == 1) return false;
        return true;
    }
};