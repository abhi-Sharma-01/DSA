class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();
        int start_color = image[sr][sc];

        if(start_color == color) return image;
         
        queue<pair<int,int>> q; // {r,c}
        vector<vector<int>> Vis(n,vector<int>(m,0));

        q.push({sr,sc});
        Vis[sr][sc] =1;
        image[sr][sc] = color;

        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i =0;i<4;i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc] == start_color && !Vis[nr][nc]){
                    image[nr][nc] = color;
                    Vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
        return image;      
    }
};