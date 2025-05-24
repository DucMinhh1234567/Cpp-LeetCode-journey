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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == nums1.size() && n == 0) return;
        if (n == nums1.size() && m == 0){
            nums1 = nums2;
            return;
        }

        vector<int> temp = nums1;
        int i = 0, j = 0;
        while (i < m && j < n){
            if (temp[i] < nums2[j]){
                nums1[i + j] = temp[i];
                i++;
            }
            else {
                nums1[i + j] = nums2[j];
                j++;
            }
        }

        while (i < m){
            nums1[i + j] = temp[i];
            i++;
        }

        while (j < n){
            nums1[i + j] = nums2[j];
            j++;
        }

        // Cleaner solution: Merge form end to start
        // int i = m - 1;  // Index of last element in nums1
        // int j = n - 1;  // Index of last element in nums2
        // int k = m + n - 1;  // Index of last position in merged array
        
        // while (j >= 0) {
        //     if (i >= 0 && nums1[i] > nums2[j]) {
        //         nums1[k--] = nums1[i--];
        //     } else {
        //         nums1[k--] = nums2[j--];
        //     }
        // }
    }
};