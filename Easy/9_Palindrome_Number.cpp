#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }

        // Solution 1: use string
        // string num {to_string(x)};
        // for (int i{0}; i < num.length() / 2; i++){
        //     if (num[i] != num[num.length() - 1 - i]){
        //         return false;
        //     }
        // }
        // return true;
        
        int temp {x}, count {0};
        while (temp > 0){
            temp /= 10;
            count++;
        }

        vector<int> arr(count);
        for (int i{0}; i < count; i++){
            arr[i] = x % 10;
            x /= 10;
        }

        for (int i{0}; i < count / 2; i++){
            if (arr[i] != arr[count - i - 1]){
                return false;
            }
        }

        return true;
    }
};