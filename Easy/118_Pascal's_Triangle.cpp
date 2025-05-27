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
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        if (numRows == 2) return {{1}, {1, 1}};

        vector<vector<int>> result = {{1}, {1, 1}};

        for (int i = 2; i < numRows; i++) {
            // Khởi tạo vector có kích thước i + 1 với toàn giá trị 1
            // Mục đích để bỏ qua xử lý 2 số 1 ở rìa
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                // Vẫn logic cũ số thứ j hàng hiện tại (i)
                // = tổng số thứ j và j - 1 ở hàng cũ (i - 1)
                row[j] = result[i-1][j-1] + result[i-1][j];
            }
            // Thêm nguyên 1 row h mới bt là đc làm nthe
            result.push_back(row);
        }

        return result;
    }
};