class Solution {
public:
    // Method 2 : using the  Topo Sort 
    bool canFinish(int V, vector<vector<int>>& prereq) {

        vector<vector<int>> adjList(V);
        vector<int> indegree(V,0);
        for(auto edge: prereq){
            adjList[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        // we need to find the nodes with zero incoming edges and keep removing them use queue to store them
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto nbr: adjList[node]){
                indegree[nbr]--;
                if(indegree[nbr]== 0){
                    q.push(nbr);
                }
            }
        }

        if(topo.size()== V) return true;

        return false;

    }
};