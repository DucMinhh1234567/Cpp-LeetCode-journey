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
    bool isPalindrome(string s) {
        // Cách truyền thống
        // string valid;
        
        // for (char c : s) {
        //     if (isalnum(c)) {
        //         valid += tolower(c);
        //     }
        // }
        
        // int left = 0, right = valid.length() - 1;
        // while (left < right) {
        //     if (valid[left] != valid[right]) {
        //         return false;
        //     }
        //     left++;
        //     right--;
        // }
        
        // return true;

        int start=0;
        int end=s.size()-1;
        while(start<=end){
            // xem có phải alphanumeric (trong bảng chữ cái) hay ko
            // ko thì bỏ qua và continue
            // đồng thời so sánh luôn với end
            if(!isalnum(s[start])){start++; continue;}
            if(!isalnum(s[end])){end--;continue;}
            if(tolower(s[start])!=tolower(s[end]))return false;
            else{
                start++;
                end--;
            }
        }
        return true;
    }
};