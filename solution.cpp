#include <vector>
#include <algorithm>

class Solution {
public:
    int getMaximumGold(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int max_gold = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    max_gold = std::max(max_gold, backtrack(grid, i, j));
                }
            }
        }
        
        return max_gold;
    }
    
private:
    int backtrack(std::vector<std::vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }
        
        int gold = grid[i][j];
        grid[i][j] = 0; // Mark as visited
        
        int up = backtrack(grid, i - 1, j);
        int down = backtrack(grid, i + 1, j);
        int left = backtrack(grid, i, j - 1);
        int right = backtrack(grid, i, j + 1);
        
        grid[i][j] = gold; // Restore grid value
        
        return gold + std::max({up, down, left, right});
    }
};
