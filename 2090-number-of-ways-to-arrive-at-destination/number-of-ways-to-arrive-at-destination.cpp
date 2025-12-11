class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long >>> adjList(n);
        for(auto edge : roads){
            adjList[edge[0]].push_back({edge[1],edge[2]});
            adjList[edge[1]].push_back({edge[0],edge[2]});
        }

        priority_queue< pair<long long,long long> , vector<pair<long long,long long>> , greater<pair<long long,long long>> > pq;
        vector<long long> dist(n,1e18) , ways(n, 0);
        ways[0] = 1;
        dist[0] = 0;

        pq.push({0,0});

        long long MOD = 1e9+7;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long time = it.first;
            long long node = it.second;

            for(auto nbr : adjList[node]){
                long long nbrnode = nbr.first;
                long long ewt = nbr.second;

                if( (ewt + time) < dist[nbrnode]){
                    dist[nbrnode] = ewt + time;
                    pq.push({dist[nbrnode], nbrnode});
                    ways[nbrnode] = ways[node] % MOD;
                }

                // node if the distance become equal then we need not to push back  in the PQ
                else if(ewt+ time == dist[nbrnode]){
                    // we just need to increase the number of ways it cn reach the node
                    ways[nbrnode] = (ways[nbrnode] +ways[node]) % MOD;
                }
            }
        }
        if(dist[n-1]==1e9 || ways[n-1]==0)return -1; // it similar to checking the ways[n-1] == 0 as if not visited then ways == 0

        return ways[n-1]%MOD;
    }
};