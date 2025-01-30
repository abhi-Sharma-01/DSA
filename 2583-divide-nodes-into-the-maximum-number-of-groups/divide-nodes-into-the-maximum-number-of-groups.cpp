class Solution {
public:
    bool isBipartite(unordered_map<int, vector<int>> &adj, int curr, vector<int>& colors, int currColor) {
        colors[curr] = currColor;
        for(int &ngbr : adj[curr]) {
            if(colors[ngbr] == colors[curr] || (colors[ngbr] == -1 && !isBipartite(adj, ngbr, colors, 1 - currColor)))
                return false;
        }
        return true;
    }

    int bfs(unordered_map<int, vector<int>> &adj, int currNode, int n) {
        queue<int> que;
        vector<bool> visited(n, false);
        que.push(currNode);
        visited[currNode] = true;
        int level = 1;
        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                int curr = que.front();
                que.pop();
                for(int &ngbr : adj[curr]) {
                    if(!visited[ngbr]) {
                        que.push(ngbr);
                        visited[ngbr] = true;
                    }
                }
            }
            level++;
        }
        return level - 1;
    }

    int getMaxFromEachComp(unordered_map<int, vector<int>> &adj, int curr, vector<bool>& visited, vector<int>& levels) {
        int maxGrp = levels[curr];
        visited[curr] = true;
        for(int &ngbr : adj[curr]) {
            if(!visited[ngbr])
                maxGrp = max(maxGrp, getMaxFromEachComp(adj, ngbr, visited, levels));
        }
        return maxGrp;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto& edge : edges) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }
        vector<int> colors(n, -1), levels(n, 0);
        for(int node = 0; node < n; node++) {
            if(colors[node] == -1 && !isBipartite(adj, node, colors, 1))
                return -1;
            levels[node] = bfs(adj, node, n);
        }
        int maxGroupEachComp = 0;
        vector<bool> visited(n, false);
        for(int node = 0; node < n; node++) {
            if(!visited[node])
                maxGroupEachComp += getMaxFromEachComp(adj, node, visited, levels);
        }
        return maxGroupEachComp;
    }
};
