class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>&grid, vector<vector<int>> &Vis){
        Vis[r][c]=1;
        int n= grid.size();
        int m= grid[0].size();

        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};

        for(int i=0;i<4;i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !Vis[nr][nc]){
                dfs(nr,nc,grid,Vis);
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {

        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> Vis(n,vector<int>(m,0));

        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!Vis[i][j] && grid[i][j]== '1'){
                    dfs(i,j,grid,Vis);
                    count++;
                }
            }
        }
        return count;        
        
    }
};