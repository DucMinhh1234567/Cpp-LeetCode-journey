#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 3; // Kích thước ma trận nxn
    
    // Cách 1: Khai báo và khởi tạo với giá trị mặc định (0)
    vector<vector<int>> matrix1(n, vector<int>(n));
    
    // Cách 2: Khai báo và khởi tạo với giá trị cụ thể
    vector<vector<int>> matrix2(n, vector<int>(n, 1)); // Tất cả phần tử = 1
    
    // Cách 3: Khai báo và khởi tạo từng phần tử
    vector<vector<int>> matrix3(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matrix3[i][j] = i + j; // Ví dụ: ma trận với a[i][j] = i + j
        }
    }
    
    // Cách 4: Khai báo và khởi tạo trực tiếp
    vector<vector<int>> matrix4 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // In ma trận để kiểm tra
    cout << "Matrix 1 (default values):" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix1[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nMatrix 2 (all ones):" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nMatrix 3 (i + j):" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix3[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nMatrix 4 (direct initialization):" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix4[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
} 