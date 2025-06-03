// WIP
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> total(m + n);
        
        int i = 0, j = 0;
        while (i < m && j < n){
            if (nums1[i] < nums2[j]){
                total[i + j] = nums1[i];
                i++;
            }
            else {
                total[i + j] = nums2[j];
                j++;
            }
        }

        while (i < m){
            total[i + j] = nums1[i];
            i++;
        }
        while (j < n){
            total[i + j] = nums2[j];
            j++;
        }
        
        int k = total.size();
        if (k % 2 == 1){
            return total[k/2];
        }
        return (total[k/2 - 1] + total[k/2]) / 2.0;
    }
};