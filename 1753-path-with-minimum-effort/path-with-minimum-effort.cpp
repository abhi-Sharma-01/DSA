class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int, pair<int,int>> ,
                        vector<pair<int, pair<int,int>>>,
                        greater<pair<int, pair<int,int>>>> pq;
        dist[0][0] = 0;
        pq.push({0,{0,0}});

        vector<int> drow = {-1,0,1,0};
        vector<int> dcol = {0,1,0,-1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int ro = it.second.first;
            int co = it.second.second;

            if(ro == n-1 && co == m-1){
                return diff;
            }
            for(int i=0;i<4;i++){
                int nr = ro + drow[i];
                int nc = co + dcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m){

                    int neweffort =  max(abs(heights[ro][co] - heights[nr][nc]),diff);

                    if(neweffort < dist[nr][nc]){
                        pq.push({neweffort,{nr,nc}});
                        dist[nr][nc] = neweffort;
                    }
                }

            }
        }

        return 0;        
    }
};