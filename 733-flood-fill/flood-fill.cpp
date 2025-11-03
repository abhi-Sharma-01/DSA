class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n= image.size();
        int m = image[0].size();

        int init_color = image[sr][sc];  // Initial color at the source index
        
        if(init_color == color) return image; // agar initially color is same as to be color no need to change any others

        vector<vector<int>> Vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        Vis[sr][sc] = 1;
        image[sr][sc] = color;  

        vector<int> drow ={-1,0,1,0};
        vector<int> dcol ={0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && !Vis[nr][nc] && image[nr][nc] == init_color ){
                    image[nr][nc] = color;
                    Vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};