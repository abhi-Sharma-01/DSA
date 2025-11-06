class Solution {
public: 
                        // Here We need to find the distance of the nearest zero 

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> Vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,-1));

        queue<pair<pair<int,int>,int>> q;

        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    Vis[i][j]= 1;
                    q.push({{i,j},0});
                }
            }
        }

        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            dis[r][c] = d;

            for(int i=0;i<4;i++){  // check all the direction
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr>=0 && nr<n && nc>=0  && nc<m && Vis[nr][nc] == 0 && mat[nr][nc]== 1 && dis[nr][nc]== -1){
                    Vis[nr][nc] = 1;
                    q.push({{nr,nc},d+1});
                }

            }
        }

        return dis;
        
    }
};