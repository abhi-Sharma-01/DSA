class Solution {
public:
    int firstCompleteIndex(vector<int>& arr,vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int,pair<int, int>> cellPosition;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cellPosition[mat[i][j]] = {i, j};
            }
        }
        vector<int> rowCount(m, 0), colCount(n, 0);        
        for (int k = 0; k < arr.size(); ++k) {
            int value = arr[k];
            auto [row, col] = cellPosition[value];
            rowCount[row]++;
            colCount[col]++;
            
            if (rowCount[row] == n || colCount[col] == m) {
                return k;
            }
        }        
        return -1;  
    }
};
