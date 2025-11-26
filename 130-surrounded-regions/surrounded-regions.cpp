class Solution {
public:
    void solve(vector<vector<char>>& board) {
     //  Method 2: Using the BFS approach 
    // storing all the 'O' into the queue
    // then mark them visited 

    int m = board.size();
    int n = board[0].size();

    vector<vector<int> >  Vis(m,vector<int> (n,0));

    queue<pair<int,int>> q; // it will capture all the 'O' cell which further will be used 
    
    for(int j = 0;j<n;j++){
        //first row
        if(board[0][j]=='O' && Vis[0][j]==0){
            q.push({0,j});
            Vis[0][j] = 1;
        }
        if(board[m-1][j]=='O' && Vis[m-1][j]==0){
            q.push({m-1,j});
            Vis[m-1][j] = 1;
        }
    }

    // checking the first column and the last columns 

    for(int i=0;i<m;i++){
        //first row
        if(board[i][0]=='O' && Vis[i][0]==0){
            q.push({i,0});
            Vis[i][0] = 1;
        }
        if(board[i][n-1]=='O' && Vis[i][n-1] == 0){
            q.push({i,n-1});
            Vis[i][n-1] = 1;
        }
    }

    // Now here we need to apply the BFS Approach and find all the connecte dcell with the "O"

    vector<int> drow = {-1,0,1,0};
    vector<int> dcol = {0,1,0,-1};
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i =0;i<4;i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(nr>=0 && nr<m && nc>=0 && nc<n && Vis[nr][nc]==0 && board[nr][nc]== 'O'){
                q.push({nr,nc});
                Vis[nr][nc] = 1;
            }
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