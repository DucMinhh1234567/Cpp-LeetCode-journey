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
    int minMaxDifference(int num) {
        string temp = to_string(num);
        char change = ' ';
        
        // Tìm chữ số đầu tiên khác 9 để thay đổi thành 9
        for (char c : temp) {
            if (c != '9') {
                change = c;
                break;
            }
        }
        
        // Thay đổi tất cả các chữ số change thành 9
        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] == change) {
                temp[i] = '9';
            }
        }
        int maxNum = stoi(temp);

        // Tìm số nhỏ nhất bằng cách thay đổi chữ số đầu tiên thành 0
        temp = to_string(num);
        change = temp[0];
        for (int i = 0; i < temp.length(); i++) {
            if (temp[i] == change) {
                temp[i] = '0';
            }
        }
        int minNum = stoi(temp);

        return maxNum - minNum;
    }
};