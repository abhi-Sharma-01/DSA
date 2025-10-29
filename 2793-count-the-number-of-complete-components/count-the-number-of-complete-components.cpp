class Solution {
public:                   
 // In this problem we not only need to find the number of components  
 // Here We need to find if the connected component is complete or not 


 // To check the complete components we need to store the component in vector
 // And need to check if the number of edges = size* (size-1)/ 2;

    void traverse(int node,vector<vector<int>> &adjList,vector<bool> &vis, vector<int> & curr_compo){
        vis[node] = true;
        curr_compo.push_back(node);
        for(int neigh : adjList[node]){
            if(!vis[neigh]){
                traverse(neigh,adjList,vis,curr_compo);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adjList(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> vis(n,false);
        // vector<vector<int>> components;
        int cnt =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int>curr_compo;
                traverse(i,adjList,vis,curr_compo);
            
                int edgecnt = 0;
                for(int node : curr_compo){ // we need to check all the edges for each node in curr_compo component
                    edgecnt += adjList[node].size();
                }
                edgecnt /=2;  // as we are solving for the undirected graph so we have counted double
                // As we have curr_compo compo so to be a complete compo we need the the total edge = (size*(size-1))/2
                int size = curr_compo.size();
                if(edgecnt == (size*(size-1))/2){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};