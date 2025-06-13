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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> result;

        for (int i = 0; i < nums1.size(); i++){
            map[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++){
            if (map.find(nums2[i]) != map.end()){
                result.push_back(nums2[i]);
                map[nums2[i]]--;
                if (map[nums2[i]] == 0) map.erase(nums2[i]);
            }
        }
        
        return result;
    }
};