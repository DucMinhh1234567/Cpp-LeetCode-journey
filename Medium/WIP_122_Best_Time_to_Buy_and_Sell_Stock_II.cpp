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
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], sell = 0;

        for (int i = 1; i < prices.size() - 1; i++){
            if (buy > prices[i]){
                buy = prices[i];
            }
            if (prices[i] - buy > sell){
                sell = prices[i] - buy;
            }
        }

        return sell;
    }
};