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
    int countPrimes(int n) {
        vector<bool> check(n + 1, true);
        for (int p = 2; p * p <= n; p++){
            if (check[p] == true){
                for (int i = p * p; i <= n; i += p) check[i] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++){
            if(check[i]) count++;
        }
        return count;
    }
};