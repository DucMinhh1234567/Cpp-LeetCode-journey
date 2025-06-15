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
    int maxDiff(int num) {
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

        // Tìm số nhỏ nhất
        temp = to_string(num);
        if (temp.length() == 1) {
            // Nếu số chỉ có 1 chữ số, thay đổi thành 1
            temp[0] = '1';
        } else {
            // Nếu số đầu tiên khác 1, thay đổi số đầu và các số giống số đầu thành 1
            if (temp[0] != '1') {
                char firstDigit = temp[0];
                for (char &c : temp) {
                    if (c == firstDigit) c = '1';
                }
            } else {
                // Nếu số đầu là 1, tìm chữ số đầu tiên khác 0 và khác 1
                // và thay đổi tất cả các chữ số đó thành 0
                for (int i = 1; i < temp.length(); i++) {
                    if (temp[i] != '0' && temp[i] != '1') {
                        char digit = temp[i];
                        for (char &c : temp) {
                            if (c == digit) c = '0';
                        }
                        break;
                    }
                }
            }
        }
        int minNum = stoi(temp);

        return maxNum - minNum;
    }
};