class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> top(n + 1, 0), bottom(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            top[i] = top[i + 1] + grid[0][i];
            bottom[i] = bottom[i + 1] + grid[1][i];
        }
        
        long long result = LLONG_MAX;
        long long topSum = 0, bottomSum = 0;
        
        for (int i = 0; i < n; ++i) {
            long long secondRobot = max(top[i + 1], bottomSum);
            
            result = min(result, secondRobot);
            topSum += grid[0][i];
            bottomSum += grid[1][i];
        }
        
        return result;
    }
};
