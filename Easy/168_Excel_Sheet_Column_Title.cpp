#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while (columnNumber > 0) {
            columnNumber--;  // Điều chỉnh để A bắt đầu từ 0
            char c = 'A' + (columnNumber % 26);
            result = c + result;  // Thêm chữ cái vào đầu chuỗi
            columnNumber /= 26;
        }
        return result;
    }
};