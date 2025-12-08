class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        // If start OR end cell is blocked, no path exists
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        if(n==1) return 1;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        dist[0][0] = 1;

        vector<int> drow = {-1,-1,0,1,1,1,0,-1};
        vector<int> dcol = {0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            auto it = q.front();
            int dis = it.first;
            int ro = it.second.first;
            int co = it.second.second;
            q.pop();

            for(int i=0;i<8;i++){
                int nr = ro + drow[i];
                int nc = co + dcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==0 && 1+dis< dist[nr][nc]){
                    if(nr == n-1 && nc == n-1){
                        return 1+ dis;
                    }
                    dist[nr][nc] = 1+dis;
                    q.push({1+dis,{nr,nc}});
                }
            }
        }
        
        return -1;
        
    }
};