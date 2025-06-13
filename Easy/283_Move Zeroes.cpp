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
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 1) return;
        int move = 1, i = 0;
        while (i != nums.size() && move != nums.size()){
            if (nums[i] == 0){
                if (nums[move] != 0){
                    swap(nums[i], nums[move]);
                    move++;
                    i++;
                }
                else {
                    move++;
                }
            }
            else {
                i++;
            }

            if (i > move) move = i + 1;
        }

        // Clever solution
        int nonzero =0; //ye pointer hai
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(nums[i]!=0){
                nums[nonzero++]=nums[i];
            }
        }
        while(nonzero<n){
            nums[nonzero++]=0;
        }
    }
};