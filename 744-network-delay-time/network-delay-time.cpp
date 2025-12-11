class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList(n+1);
        for(auto edge: times)
            adjList[edge[0]].push_back({edge[1],edge[2]});
        
        vector<int> mintime(n+1,1e9);
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        mintime[k] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int minT = it.first;
            int node = it.second;

            if(minT > mintime[node]) continue;
            for(auto &nbr : adjList[node]){
                int nbrnode = nbr.first;
                int ewt = nbr.second;


                if((ewt + minT) < mintime[nbrnode] ){
                    mintime[nbrnode] = ewt + minT;
                    pq.push({mintime[nbrnode], nbrnode});
                }
            }
        }
        int ans =0;
        for(int i=1;i<=n;i++){
            if(mintime[i]==1e9) return -1;
            ans = max(ans,mintime[i]);
        }

        return ans;
        
    }
};