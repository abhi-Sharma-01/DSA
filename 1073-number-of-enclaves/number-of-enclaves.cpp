class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // here our task is to convert the 1 into zero with are a t boundary and lionked to it 
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> Vis(n,vector<int> (m,0));
        queue<pair<int,int>> q;

        for(int j=0; j<m;j++){
            // capture land fron the top row 
            if(grid[0][j] == 1 && !Vis[0][j]){
                q.push({0,j});
                Vis[0][j] = 1;
            }
            // capture land at the bottom row
            if(grid[n-1][j] == 1 && !Vis[n-1][j]){
                q.push({n-1,j});
                Vis[n-1][j] = 1;
            }
        } 

        for(int i=0;i<n;i++){
            // capture land at the first column
            if(grid[i][0]==1 && !Vis[i][0]){
                q.push({i,0});
                Vis[i][0] = 1;
            }
            if(grid[i][m-1]==1 && !Vis[i][m-1]){
                q.push({i,m-1});
                Vis[i][m-1] = 1;
            }
        }

        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !Vis[nr][nc]){
                    q.push({nr,nc});
                    Vis[nr][nc] = 1;
                }
            }
        }

        int count =0;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1 && !Vis[i][j]){
                    count++;
                }
            }
        }
        return count;        
    }
};