class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Another Method using the BFS
        // where we atre find the first land and count it and push it into the queue and make all the land connected to it as Vis;

        int n = grid.size();
        int m = grid[0].size();

        int countIsland = 0;
        queue<pair<int,int>> q;
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '0' ) continue;

                countIsland++;

                q.push({i,j});
                grid[i][j] = '0';
                // Now what we will we visiting all the land connected to it 


                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();

                    for(int i=0;i<4;i++){
                        int nr = r + drow[i];
                        int nc = c + dcol[i];

                        if(nr>=0 && nr< n && nc>=0 && nc<m  && grid[nr][nc]=='1'){
                            grid[nr][nc] = '0';
                            q.push({nr,nc});
                        }
                    }
                }
            }
        }
        return countIsland;
    }
};