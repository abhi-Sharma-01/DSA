class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int& count) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0)
            return;
        
        count += grid[r][c];  // Collect fish
        grid[r][c] = 0;  // Mark cell as visited
        
        dfs(grid, r + 1, c, count);
        dfs(grid, r - 1, c, count);
        dfs(grid, r, c + 1, count);
        dfs(grid, r, c - 1, count);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] > 0) {
                    int count = 0;
                    dfs(grid, r, c, count);
                    maxFish = max(maxFish, count);
                }
            }
        }
        return maxFish;
    }
};
