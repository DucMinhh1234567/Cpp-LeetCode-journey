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
    vector<string> divideString(string s, int k, char fill) {
        int check = s.length() % k;
        if (check != 0){
            for (int i = 0; i < k - check; i++){
                s.push_back(fill);
            }
        }

        vector<string> result;
        string temp;
        for (int i = 0; i < s.length(); i++){
            temp.push_back(s[i]);
            if ((i + 1) % k == 0){
                result.push_back(temp);
                temp = "";
            }
        }

        return result;
    }
};