class Solution {
public:
    void dfs( int node, vector<vector<int>> adjList, vector<bool>&visited){
        visited[node] = true;
        for(int neigh: adjList[node]){
            if(!visited[neigh]){
                dfs(neigh,adjList,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // first we are gpoing to convert the adjmatrix into adjList
        int n = isConnected.size();
        vector<vector<int>> adjList(n); 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        // Now we are going to apply dfs approach 
        vector<bool> visited(n,false);
        int cnt =0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,adjList,visited);
            }
        }

        return cnt;

    }
};