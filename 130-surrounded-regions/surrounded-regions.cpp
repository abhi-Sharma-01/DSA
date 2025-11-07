class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>&board, vector<vector<int>> &Vis){
        Vis[r][c] = 1;

        int n = board.size();
        int m = board[0].size();

        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};

        //checking the four directions 
        for(int i=0;i<4;i++){
            int nr = r + drow[i];
            int nc = c +  dcol[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && Vis[nr][nc] == 0 && board[nr][nc] == 'O'){
                dfs(nr,nc,board,Vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) { 

            // So  The approach would be like we will firstly find the 'O' at the boundries and then using DFS to find all the neighbour which is connected to it will region i.e not be able to surround then using X 

            // step 1 : find the "O" at th boundry and apply dfs on each and mark it visited 
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> Vis(n,vector<int>(m,0));

        for(int j=0;j<m;j++){        // Here We are checking the first and the last rows if any O's index exist then check dfs
            if(board[0][j]=='O' && Vis[0][j] == 0){
                dfs(0,j,board,Vis);
            }
            if(board[n-1][j]=='O' && Vis[n-1][j] == 0){
                dfs(n-1,j,board,Vis);
            }
        }

        for(int i =0;i<n;i++){
            if(board[i][0]== 'O' && Vis[i][0]==0){
                dfs(i,0,board,Vis);
            }

            if(board[i][m-1]== 'O' && Vis[i][m-1]==0){
                dfs(i,m-1,board,Vis);
            }
        }

        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && Vis[i][j]==0){
                    board[i][j] = 'X';
                }
            }
        }
    
    }
};