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
    int candy(vector<int>& ratings) {
        int n = ratings.size(), count = 0;
        vector<int> counting(n, 1);

        for (int i = 1; i < n; i++){
            if (ratings[i] > ratings[i - 1]){
                counting[i] = counting[i - 1] + 1;
            }
        }
        for (int i = n - 1; i > 0; i--){
            if (ratings[i - 1] > ratings[i]){
                counting[i - 1] = max(counting[i] + 1, counting[i - 1]);
            }
            count += counting[i - 1];
        }

        return count + counting[n - 1];
    }
};