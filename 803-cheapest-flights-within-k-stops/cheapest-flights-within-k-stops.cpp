class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for(auto fly: flights){
            adjList[fly[0]].push_back({fly[1],fly[2]});
        }

        queue<pair<int,pair<int,int>>> q; // {stops,{node,dist}}
        vector<int> dist(n,1e9);
        dist[src] = 0;
        q.push({0,{src,0}});

        while(!q.empty()){
            auto it  = q.front();
            q.pop();
            int stop = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stop > k) continue;

            for(auto nbr : adjList[node]){
                int nbrNode = nbr.first;
                int ewt = nbr.second;

                if(cost + ewt < dist[nbrNode] && stop<= k){
                    q.push({stop+1,{nbrNode,cost+ewt}});
                    dist[nbrNode] = cost +ewt;
                }

                
            }
        } 
        
        if(dist[dst]==1e9) return -1;

        return dist[dst];
    }
};