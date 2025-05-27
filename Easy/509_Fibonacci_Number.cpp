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
    int fib(int n) {
        if (n == 0) return n;
        if (n == 1 || n == 2) return 1;

        int sum = 1, prev = 1;
        for (int i = 2; i < n; i++){
            int temp = sum;
            sum += prev;
            prev = temp;
        }

        return sum;
    }
};

// Cursor solution: Matrix
// Nếu n >= 50 thì hiệu quả hơn
// Độ phức tạp thời gian: O(log n) thay vì O(n)
// Sử dụng phương pháp lũy thừa nhanh (fast exponentiation)
// Mỗi bước chia đôi số mũ, nên chỉ cần log(n) bước
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        
        // Ma trận ban đầu [[1,1], [1,0]]
        vector<vector<long long>> matrix = {{1,1}, {1,0}};
        matrix = matrixPower(matrix, n-1);
        
        return matrix[0][0];
    }
    
private:
    vector<vector<long long>> matrixPower(vector<vector<long long>>& matrix, int n) {
        if (n == 0) return {{1,0}, {0,1}}; // Ma trận đơn vị
        if (n == 1) return matrix;
        
        vector<vector<long long>> half = matrixPower(matrix, n/2);
        vector<vector<long long>> result = matrixMultiply(half, half);
        
        if (n % 2 == 1) {
            result = matrixMultiply(result, matrix);
        }
        
        return result;
    }
    
    vector<vector<long long>> matrixMultiply(vector<vector<long long>>& a, vector<vector<long long>>& b) {
        return {
            {a[0][0] * b[0][0] + a[0][1] * b[1][0], a[0][0] * b[0][1] + a[0][1] * b[1][1]},
            {a[1][0] * b[0][0] + a[1][1] * b[1][0], a[1][0] * b[0][1] + a[1][1] * b[1][1]}
        };
    }
};