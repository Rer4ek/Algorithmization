#include<vector>

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    Dfs(i, j, grid);
                }
            }
        }
        return count;
    }

private:
    void Dfs(int row, int col, vector<vector<char>>& grid) {
        if (row < 0 || col < 0 || row > grid.size() - 1 || col > grid[0].size() - 1 || grid[row][col] == '0') {
            return;
        }
        grid[row][col] = '0';
        for (int i = -1; i <= 1; i += 2) {
            Dfs(row + i, col, grid);
            Dfs(row, col + i, grid);
        }
        return;
    }
};
