class Solution {
public:
    void helper(int node,vector<vector<int>> &adjList,vector<int> &Vis , vector<int>& curr){
        Vis[node] = 1;
        curr.push_back(node);
        for(auto neigh:adjList[node]){
            if(!Vis[neigh]) helper(neigh,adjList,Vis,curr);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> Vis(n,0);
        int count =0;
        for(int i =0;i<n;i++){
            if(!Vis[i]){
                vector<int> curr;
                helper(i,adjList,Vis,curr);
                
                // to be a complete componemnt it should have a edgecount  = size*(size-1)/2

                int edgeCount = 0;
                for(auto node: curr){
                    edgeCount += adjList[node].size();
                }
                int sz = curr.size();

                if(edgeCount == (sz*(sz-1))){
                    count++;
                }

            }
        }
        return count;   
    }
};