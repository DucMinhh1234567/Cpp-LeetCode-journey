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
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> map;
        int result = -1;
        for (int i = 0; i < arr.size(); i++){
            map[arr[i]]++;
        }
        for (auto& m : map){
            if (m.first == m.second && m.first > result) result = m.first;
        }

        return result;
    }
};