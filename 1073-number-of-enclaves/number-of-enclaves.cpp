class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>&Vis, vector<vector<int>> &grid){
        Vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();

        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1}; 
        // now checking in the all th four direction to get the all the neighbour 1
        for(int i=0;i<4;i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && Vis[nr][nc]==0 && grid[nr][nc]==1){
                dfs(nr,nc,Vis,grid);
            }
        }

    }

    int numEnclaves(vector<vector<int>>& grid) {
        // My Intiution say we can use the dfs method to solve the problem as we have to find the 1 which are not connected to the boundary and surrounded by the sea level i.e where we can reach 

        int n  = grid.size();
        int m = grid[0].size();

        vector<vector<int>> Vis(n,vector<int>(m,0));

        // We need to find all the 1 which are at the boundry and using dfs we can reach all the 1's that are connected with them and mark them visited so that we need not to come and visit it again
        for(int j=0;j<m;j++){
            if(!Vis[0][j] && grid[0][j]==1){ // checking the very first row of grid
                dfs(0,j,Vis,grid);
            }

            if(!Vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,Vis,grid);
            }
        }

        for(int i=0;i<n;i++){
            if(!Vis[i][0] && grid[i][0]== 1){
                dfs(i,0, Vis, grid);
            }
            if(!Vis[i][m-1] && grid[i][m-1]){
                dfs(i,m-1,Vis,grid);
            }
        }

        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(Vis[i][j]==0 && grid[i][j]==1){
                    count++;
                }
            }
        }

        return count;        
    }
};