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
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    island++;
                    DFS(grid, i, j);
                }
            }
        }
        return island;
    }
    
    void DFS(vector<vector<char>>& grid, int i, int j){
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1') return;

        grid[i][j] = '0';
        DFS(grid, i - 1, j); // Up
        DFS(grid, i + 1, j); // Down
        DFS(grid, i, j + 1); // Right
        DFS(grid, i, j - 1); // Left
    }
};