class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) { 

        // As grid here is given is passed with reference i.e changes can change the grid // So that's why it it preffered to work on Vis array


        // Note: Here We are Using BFS Traversal because we want to traverse multiple node simultaneously 
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>,int> >q;  // pair<pair<int,int>,int> -> siginifies as indexes for  (row,col,time)

        vector<vector<int>> Vis(m, vector<int>(n, 0)); //We also need a visit grid to keep track that we have visited the grid index earlier
        int countOne =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]== 1){
                    countOne++;
                }
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    Vis[i][j]= 2;
                }
            }
        } 

        // Here Before We start traversing through BFS We can still solve some of the edges cases though
        // case 1: if grid is not having any fresh orange
        //  No fresh oranges — nothing to rot
        if (countOne == 0) return 0;

        // No rotten oranges initially — impossible to rot anything
        if (q.empty()) return -1;

        int tm =0;
        int cnt =0;// 
        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            // now using the r,c We need to find the neighbour of grid[i][j]  whose value is = 1;
            // At each rotten index we need to check the next neighbour of it  four directions up,right,down, left 
            for(int i=0;i<4;i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                //now check all direction
                if(nr>=0 && nr<m && nc>=0 && nc<n && Vis[nr][nc] != 2 && grid[nr][nc] ==1){
                    q.push({{nr,nc},t+1});
                    Vis[nr][nc] = 2;
                    cnt++;
                }
            }

        }
        return (cnt == countOne) ? tm : -1;
    }
};