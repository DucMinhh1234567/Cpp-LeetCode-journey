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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));       
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        int  count = 1;
        
        while (top <= bottom && left <= right) {
            for (int j = left; j <= right; j++) {
                matrix[top][j] = count;
                count++;
            }
            top++;
            
            // Traverse down
            for (int i = top; i <= bottom; i++) {
                matrix[i][right] = count;
                count++;
            }
            right--;
            
            // Traverse left
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    matrix[bottom][j] = count;
                    count++;
                }
                bottom--;
            }
            
            // Traverse up
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = count;
                    count++;
                }
                left++;
            }
        }
        
        return matrix;
    }
};