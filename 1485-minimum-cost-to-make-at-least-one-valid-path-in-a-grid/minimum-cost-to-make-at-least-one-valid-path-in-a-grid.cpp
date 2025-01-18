class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        cost[0][0] = 0;
        // Directions for right, left, down, up
        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool updated = true;
        while (updated) {
            updated = false;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < 4; ++k) {
                        int new_x = i + directions[k][0];
                        int new_y = j + directions[k][1];
                        if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                            int new_cost = cost[i][j] + (grid[i][j] != k + 1);
                            if (new_cost < cost[new_x][new_y]) {
                                cost[new_x][new_y] = new_cost;
                                updated = true;
                            }
                        }
                    }
                }
            }
        }
        return cost[m - 1][n - 1];
    }
};
