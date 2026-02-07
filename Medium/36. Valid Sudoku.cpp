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

// Determine if a 9 x 9 Sudoku board is valid. 
// Only the filled cells need to be validated according to the following rules:
// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:
// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.
 
// Example 1:
// Input: board = 
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true

// Example 2:
// Input: board = 
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 
// 5 in the top left corner being modified to 8. 
// Since there are two 8's in the top left 3x3 sub-box, it is invalid.

// Constraints:
// board.length == 9
// board[i].length == 9
// board[i][j] is a digit 1-9 or '.'.

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            unordered_set<char> row[9];
            unordered_set<char> col[9];
            unordered_set<char> box[9];

            for (int i = 0; i < 9; i++){ // i là row
                for (int j = 0; j < 9; j++){
                    if (board[i][j] == '.') continue;

                    char value = board[i][j];
                    // cthuc dưới chia box 9x9 của sudoku ra thành 9 box, mỗi box 3x3
                    // lúc nó count là xem phần tử đã tồn tại chưa
                    // có thì 1 chưa thì 0, chưa thì thêm phần tử vào set bằng insert
                    // {3, 5}, count('1') -> Chưa có -> return 0 -> {1, 3, 5}
                    int index = (i / 3) * 3 + (j / 3 );
                    if (row[i].count(value) || col[j].count(value) || box[index].count(value)) return false;

                    row[i].insert(value);
                    col[j].insert(value);
                    box[index].insert(value);
                }
            }

            return true;
        }
    };