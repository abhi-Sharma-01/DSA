class Solution {
public:
    void traverse(int node,vector<vector<int>> adjList,vector<bool> & isVisited, vector<int>& curr){
        isVisited[node] = true;
        curr.push_back(node);
        for(int neigh: adjList[node]){
            if(!isVisited[neigh]){
                traverse(neigh,adjList,isVisited,curr);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adjList(n);
        for(auto edge:edges){
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);// only for undirected graph
        }

        vector<bool> isVisited(n,false);
        int count =0;
        // vector<vector<int>> compo;
        for(int i=0;i<n;i++){
            if(!isVisited[i]){
                vector<int> curr;
                traverse(i,adjList,isVisited,curr);

                int edgecount =0;
                for(int node : curr){
                    edgecount += adjList[node].size();
                }

                int size = curr.size();

                if(edgecount == (size*(size-1))){
                    count++;
                }
            }
        }
        return count;
        
    }
};