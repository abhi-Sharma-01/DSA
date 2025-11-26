class Solution {
public:

    void dfs(int row,int col, vector<vector<char>> &board , vector<vector<int>> &Vis){
        int m  = board.size();
        int n = board[0].size();

        Vis[row][col] = 1;

        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};

        for(int i =0;i<4 ;i++){

            int nr = row + drow[i];
            int nc = col + dcol[i];

            if(nr>=0 && nr<m && nc>=0 && nc< n && board[nr][nc]=='O' && Vis[nr][nc]==0){
                dfs(nr,nc, board,Vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> Vis(m,vector<int> (n,0));
        // so our goal is to capture all the 'O' at the boundry

        // to check at the boundary we need to capture all the region connected to it with 'O' using DFS we can get all the points that are somehow connected with the edge 'O'

        //  Checking the first row and the last row for all the columns 
       
       for(int j = 0;j<n;j++){
            //first row
            if(board[0][j]=='O' && Vis[0][j]==0){
                dfs(0,j,board, Vis);
            }
            if(board[m-1][j]=='O' && Vis[m-1][j]==0){
                dfs(m-1,j,board, Vis);
            }
       }

       // checking the first column and the last columns 

       for(int i=0;i<m;i++){
            //first row
            if(board[i][0]=='O' && Vis[i][0]==0){
                dfs(i,0,board, Vis);
            }
            if(board[i][n-1]=='O' && Vis[i][n-1] == 0){
                dfs(i,n-1,board, Vis);
            }
       }

       for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(Vis[i][j]== 0 && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
       }      

    }
};