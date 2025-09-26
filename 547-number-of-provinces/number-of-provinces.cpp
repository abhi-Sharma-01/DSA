class Solution {
public:
    void traverse(int node,vector<vector<int>> adjList,vector<bool> &isVisited){
        isVisited[node] = true;
        for(int neigh: adjList[node]){
            if(!isVisited[neigh]){
                traverse(neigh,adjList,isVisited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<bool> isVisited(n,false);
        int cnt =0;
        for(int i=0;i<n;i++){
            if(!isVisited[i]){
                cnt++;
                traverse(i,adjList,isVisited);
            }
            
        }
        return cnt;
        
    }
};